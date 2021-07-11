// Generated by gencpp from file mavros_msgs/MPC_Inputs.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_MPC_INPUTS_H
#define MAVROS_MSGS_MESSAGE_MPC_INPUTS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace mavros_msgs
{
template <class ContainerAllocator>
struct MPC_Inputs_
{
  typedef MPC_Inputs_<ContainerAllocator> Type;

  MPC_Inputs_()
    : header()
    , mpc_ref_in()
    , mpc_mo_in()  {
      mpc_ref_in.assign(0.0);

      mpc_mo_in.assign(0.0);
  }
  MPC_Inputs_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , mpc_ref_in()
    , mpc_mo_in()  {
  (void)_alloc;
      mpc_ref_in.assign(0.0);

      mpc_mo_in.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef boost::array<float, 38>  _mpc_ref_in_type;
  _mpc_ref_in_type mpc_ref_in;

   typedef boost::array<float, 2>  _mpc_mo_in_type;
  _mpc_mo_in_type mpc_mo_in;





  typedef boost::shared_ptr< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> const> ConstPtr;

}; // struct MPC_Inputs_

typedef ::mavros_msgs::MPC_Inputs_<std::allocator<void> > MPC_Inputs;

typedef boost::shared_ptr< ::mavros_msgs::MPC_Inputs > MPC_InputsPtr;
typedef boost::shared_ptr< ::mavros_msgs::MPC_Inputs const> MPC_InputsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::MPC_Inputs_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mavros_msgs::MPC_Inputs_<ContainerAllocator1> & lhs, const ::mavros_msgs::MPC_Inputs_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.mpc_ref_in == rhs.mpc_ref_in &&
    lhs.mpc_mo_in == rhs.mpc_mo_in;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mavros_msgs::MPC_Inputs_<ContainerAllocator1> & lhs, const ::mavros_msgs::MPC_Inputs_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "44361b7e6cdaa7dc8aa5f281d51dafe6";
  }

  static const char* value(const ::mavros_msgs::MPC_Inputs_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x44361b7e6cdaa7dcULL;
  static const uint64_t static_value2 = 0x8aa5f281d51dafe6ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/MPC_Inputs";
  }

  static const char* value(const ::mavros_msgs::MPC_Inputs_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"\n"
"float32[38] mpc_ref_in\n"
"\n"
"float32[2] mpc_mo_in\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::mavros_msgs::MPC_Inputs_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.mpc_ref_in);
      stream.next(m.mpc_mo_in);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MPC_Inputs_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::MPC_Inputs_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::MPC_Inputs_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "mpc_ref_in[]" << std::endl;
    for (size_t i = 0; i < v.mpc_ref_in.size(); ++i)
    {
      s << indent << "  mpc_ref_in[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.mpc_ref_in[i]);
    }
    s << indent << "mpc_mo_in[]" << std::endl;
    for (size_t i = 0; i < v.mpc_mo_in.size(); ++i)
    {
      s << indent << "  mpc_mo_in[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.mpc_mo_in[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_MPC_INPUTS_H
