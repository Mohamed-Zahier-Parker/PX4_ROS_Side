;; Auto-generated. Do not edit!


(when (boundp 'mavros_msgs::MPC_Inputs)
  (if (not (find-package "MAVROS_MSGS"))
    (make-package "MAVROS_MSGS"))
  (shadow 'MPC_Inputs (find-package "MAVROS_MSGS")))
(unless (find-package "MAVROS_MSGS::MPC_INPUTS")
  (make-package "MAVROS_MSGS::MPC_INPUTS"))

(in-package "ROS")
;;//! \htmlinclude MPC_Inputs.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass mavros_msgs::MPC_Inputs
  :super ros::object
  :slots (_header _mpc_ref_in _mpc_mo_in ))

(defmethod mavros_msgs::MPC_Inputs
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:mpc_ref_in __mpc_ref_in) (make-array 38 :initial-element 0.0 :element-type :float))
    ((:mpc_mo_in __mpc_mo_in) (make-array 2 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _mpc_ref_in __mpc_ref_in)
   (setq _mpc_mo_in __mpc_mo_in)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:mpc_ref_in
   (&optional __mpc_ref_in)
   (if __mpc_ref_in (setq _mpc_ref_in __mpc_ref_in)) _mpc_ref_in)
  (:mpc_mo_in
   (&optional __mpc_mo_in)
   (if __mpc_mo_in (setq _mpc_mo_in __mpc_mo_in)) _mpc_mo_in)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32[38] _mpc_ref_in
    (* 4    38)
    ;; float32[2] _mpc_mo_in
    (* 4    2)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32[38] _mpc_ref_in
     (dotimes (i 38)
       (sys::poke (elt _mpc_ref_in i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[2] _mpc_mo_in
     (dotimes (i 2)
       (sys::poke (elt _mpc_mo_in i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32[38] _mpc_ref_in
   (dotimes (i (length _mpc_ref_in))
     (setf (elt _mpc_ref_in i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[2] _mpc_mo_in
   (dotimes (i (length _mpc_mo_in))
     (setf (elt _mpc_mo_in i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get mavros_msgs::MPC_Inputs :md5sum-) "44361b7e6cdaa7dc8aa5f281d51dafe6")
(setf (get mavros_msgs::MPC_Inputs :datatype-) "mavros_msgs/MPC_Inputs")
(setf (get mavros_msgs::MPC_Inputs :definition-)
      "std_msgs/Header header

float32[38] mpc_ref_in

float32[2] mpc_mo_in
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :mavros_msgs/MPC_Inputs "44361b7e6cdaa7dc8aa5f281d51dafe6")


