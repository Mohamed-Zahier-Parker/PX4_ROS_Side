; Auto-generated. Do not edit!


(cl:in-package mavros_msgs-msg)


;//! \htmlinclude MPC_Outputs.msg.html

(cl:defclass <MPC_Outputs> (roslisp-msg-protocol:ros-message)
  ((mpc_mv_out
    :reader mpc_mv_out
    :initarg :mpc_mv_out
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass MPC_Outputs (<MPC_Outputs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MPC_Outputs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MPC_Outputs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mavros_msgs-msg:<MPC_Outputs> is deprecated: use mavros_msgs-msg:MPC_Outputs instead.")))

(cl:ensure-generic-function 'mpc_mv_out-val :lambda-list '(m))
(cl:defmethod mpc_mv_out-val ((m <MPC_Outputs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mavros_msgs-msg:mpc_mv_out-val is deprecated.  Use mavros_msgs-msg:mpc_mv_out instead.")
  (mpc_mv_out m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MPC_Outputs>) ostream)
  "Serializes a message object of type '<MPC_Outputs>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'mpc_mv_out))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MPC_Outputs>) istream)
  "Deserializes a message object of type '<MPC_Outputs>"
  (cl:setf (cl:slot-value msg 'mpc_mv_out) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'mpc_mv_out)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MPC_Outputs>)))
  "Returns string type for a message object of type '<MPC_Outputs>"
  "mavros_msgs/MPC_Outputs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MPC_Outputs)))
  "Returns string type for a message object of type 'MPC_Outputs"
  "mavros_msgs/MPC_Outputs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MPC_Outputs>)))
  "Returns md5sum for a message object of type '<MPC_Outputs>"
  "74f4756230813d28d9765644d38e8155")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MPC_Outputs)))
  "Returns md5sum for a message object of type 'MPC_Outputs"
  "74f4756230813d28d9765644d38e8155")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MPC_Outputs>)))
  "Returns full string definition for message of type '<MPC_Outputs>"
  (cl:format cl:nil "~%float32[2] mpc_mv_out~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MPC_Outputs)))
  "Returns full string definition for message of type 'MPC_Outputs"
  (cl:format cl:nil "~%float32[2] mpc_mv_out~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MPC_Outputs>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'mpc_mv_out) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MPC_Outputs>))
  "Converts a ROS message object to a list"
  (cl:list 'MPC_Outputs
    (cl:cons ':mpc_mv_out (mpc_mv_out msg))
))
