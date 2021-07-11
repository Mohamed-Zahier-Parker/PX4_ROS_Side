#include <ros/ros.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include "mpc0/rtmodel.h"
#include <cmath>
#include <algorithm>
#include "std_msgs/String.h"
#include <mavros_msgs/MPC_Inputs.h>
#include <mavros_msgs/MPC_Outputs.h>
#include <geometry_msgs/PoseStamped.h>
#include <iostream>

#include <sstream>

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

//Callback function for MPC inputs topic
mavros_msgs::MPC_Inputs mpc_ins;
void mpc_inputs_cb(const mavros_msgs::MPC_Inputs::ConstPtr& msg){
    mpc_ins = *msg;
}


//MPC inputs and outputs declaration !!!ADD Assign in callback function of own topic and find way to convert double array to float array!!!
// float MPC_ref[38]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
float MPC_ref[38]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float MPC_mo[2]={0,0};
float MPC_mv[2]={0,0};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "MPC_handler");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);

    //!!!Make New Subscriber(PX4->ROS) and Publisher(ROS->PX4) to your own topics!!!
    ros::Subscriber mpc_in_sub = nh.subscribe<mavros_msgs::MPC_Inputs>
            ("/mavros/mpc_inputs_topic", 10, mpc_inputs_cb);

    ros::Publisher mpc_outputs_pub = nh.advertise<mavros_msgs::MPC_Outputs>
            ("/mavros/mpc_outputs/mpc_outputs_topic", 10);        

    // Required for now to allow vehicle to go into offbaord mode(CHECK if you can make mpc outputs publish do the same)
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);

    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(50.0);//50Hz corresponding to 0.02 seconds

     // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    // Required for now to allow vehicle to go into offbaord mode(CHECK if you can make mpc outputs publish do the same)
    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    //!!!Define Struct for publish topic!!!
    mavros_msgs::MPC_Outputs mpc_outs;

    //Intilise MPC
    MPC0_initialize();

    //publish a few values before starting to allow changing into offboard mode
    for(int i = 100; ros::ok() && i > 0; --i){
        //!!!MAKE A WAY TO WAIT FOR CALLBACK to be first called before passing!!!
        //Set inputs to MPC
        for(int i=0;i<38;i++){
            MPC_ref[i]=mpc_ins.mpc_ref_in[i];
        }
        MPC_mo[0]=mpc_ins.mpc_mo_in[0];MPC_mo[1]=mpc_ins.mpc_mo_in[1];

        // TESTING
        // std::cout<<"MPC_in ref: "<<mpc_ins.mpc_ref_in[0]<<" ; "<<mpc_ins.mpc_ref_in[37]<<"\n";
        // std::cout<<"MPC_in mo: "<<mpc_ins.mpc_mo_in[0]<<" ; "<<mpc_ins.mpc_mo_in[1]<<"\n";

        std::copy(std::begin(MPC_ref),std::end(MPC_ref),MPC0_U.ref_out);
        std::copy(std::begin(MPC_mo),std::end(MPC_mo),MPC0_U.moorx);
        //Step MPC
        MPC0_step();
        //Extract output of MPC
        std::copy(MPC0_Y.mv,MPC0_Y.mv+2,MPC_mv);
        // mpc_outs.header=mpc_ins.header;
        mpc_outs.mpc_mv_out[0]=MPC_mv[0];mpc_outs.mpc_mv_out[1]=MPC_mv[1];
        //!!!ADD publish to topic!!!
        mpc_outputs_pub.publish(mpc_outs);

        // TESTING
        // std::cout<< "MPC_mv : " << MPC_mv[0] <<" ; " << MPC_mv[1]<<"\n";

        // Required for now to allow vehicle to go into offbaord mode(CHECK if you can make mpc outputs publish do the same)
        local_pos_pub.publish(pose);

        //Run callback functions
        ros::spinOnce();
        //Loop back after 0.02 seconds is over
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){
        if( current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
            }
        }

        // Required for now to allow vehicle to go into offbaord mode(CHECK if you can make mpc outputs publish do the same)
        local_pos_pub.publish(pose);

         //Set inputs to MPC
        for(int i=0;i<38;i++){
            MPC_ref[i]=mpc_ins.mpc_ref_in[i];
        }
        MPC_mo[0]=mpc_ins.mpc_mo_in[0];MPC_mo[1]=mpc_ins.mpc_mo_in[1];

        // TESTING
        // std::cout<<"MPC_in ref: "<<mpc_ins.mpc_ref_in[0]<<" ; "<<mpc_ins.mpc_ref_in[37]<<"\n";
        // std::cout<<"MPC_in mo: "<<mpc_ins.mpc_mo_in[0]<<" ; "<<mpc_ins.mpc_mo_in[1]<<"\n";

        std::copy(std::begin(MPC_ref),std::end(MPC_ref),MPC0_U.ref_out);
        std::copy(std::begin(MPC_mo),std::end(MPC_mo),MPC0_U.moorx);
        //Step MPC
        MPC0_step();
        //Extract output of MPC
        std::copy(MPC0_Y.mv,MPC0_Y.mv+2,MPC_mv);
        // mpc_outs.header=mpc_ins.header;
        mpc_outs.mpc_mv_out[0]=MPC_mv[0];mpc_outs.mpc_mv_out[1]=MPC_mv[1];
        //!!!ADD publish to topic!!!
        mpc_outputs_pub.publish(mpc_outs);

        //!!!TESTING!!!
        // std::cout<< "MPC_mv : " << MPC_mv[0] <<" ; " << MPC_mv[1]<<"\n";
        // std_msgs::String msg_out;
        // std::stringstream ss;
        // ss << "MPC_mv : " << MPC_mv[0] <<" ; " << MPC_mv[1];
        // msg_out.data = ss.str();
        // ROS_INFO("%s", msg_out.data.c_str());

        ros::spinOnce();
        rate.sleep();
    }
    //Teminate MPC
    MPC0_terminate();

    return 0;
}

