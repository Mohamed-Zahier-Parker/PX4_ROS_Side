; Auto-generated. Do not edit!


(cl:in-package mavros_msgs-msg)


;//! \htmlinclude MPC_Inputs.msg.html

(cl:defclass <MPC_Inputs> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (mpc_ref_in
    :reader mpc_ref_in
    :initarg :mpc_ref_in
    :type (cl:vector cl:float)
   :initform (cl:make-array 38 :element-type 'cl:float :initial-element 0.0))
   (mpc_mo_in
    :reader mpc_mo_in
    :initarg :mpc_mo_in
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass MPC_Inputs (<MPC_Inputs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MPC_Inputs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MPC_Inputs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mavros_msgs-msg:<MPC_Inputs> is deprecated: use mavros_msgs-msg:MPC_Inputs instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MPC_Inputs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mavros_msgs-msg:header-val is deprecated.  Use mavros_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'mpc_ref_in-val :lambda-list '(m))
(cl:defmethod mpc_ref_in-val ((m <MPC_Inputs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mavros_msgs-msg:mpc_ref_in-val is deprecated.  Use mavros_msgs-msg:mpc_ref_in instead.")
  (mpc_ref_in m))

(cl:ensure-generic-function 'mpc_mo_in-val :lambda-list '(m))
(cl:defmethod mpc_mo_in-val ((m <MPC_Inputs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mavros_msgs-msg:mpc_mo_in-val is deprecated.  Use mavros_msgs-msg:mpc_mo_in instead.")
  (mpc_mo_in m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MPC_Inputs>) ostream)
  "Serializes a message object of type '<MPC_Inputs>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'mpc_ref_in))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'mpc_mo_in))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MPC_Inputs>) istream)
  "Deserializes a message object of type '<MPC_Inputs>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:setf (cl:slot-value msg 'mpc_ref_in) (cl:make-array 38))
  (cl:let ((vals (cl:slot-value msg 'mpc_ref_in)))
    (cl:dotimes (i 38)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'mpc_mo_in) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'mpc_mo_in)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MPC_Inputs>)))
  "Returns string type for a message object of type '<MPC_Inputs>"
  "mavros_msgs/MPC_Inputs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MPC_Inputs)))
  "Returns string type for a message object of type 'MPC_Inputs"
  "mavros_msgs/MPC_Inputs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MPC_Inputs>)))
  "Returns md5sum for a message object of type '<MPC_Inputs>"
  "44361b7e6cdaa7dc8aa5f281d51dafe6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MPC_Inputs)))
  "Returns md5sum for a message object of type 'MPC_Inputs"
  "44361b7e6cdaa7dc8aa5f281d51dafe6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MPC_Inputs>)))
  "Returns full string definition for message of type '<MPC_Inputs>"
  (cl:format cl:nil "std_msgs/Header header~%~%float32[38] mpc_ref_in~%~%float32[2] mpc_mo_in~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MPC_Inputs)))
  "Returns full string definition for message of type 'MPC_Inputs"
  (cl:format cl:nil "std_msgs/Header header~%~%float32[38] mpc_ref_in~%~%float32[2] mpc_mo_in~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MPC_Inputs>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'mpc_ref_in) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'mpc_mo_in) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MPC_Inputs>))
  "Converts a ROS message object to a list"
  (cl:list 'MPC_Inputs
    (cl:cons ':header (header msg))
    (cl:cons ':mpc_ref_in (mpc_ref_in msg))
    (cl:cons ':mpc_mo_in (mpc_mo_in msg))
))
