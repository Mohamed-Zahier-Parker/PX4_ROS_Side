;; Auto-generated. Do not edit!


(when (boundp 'mavros_msgs::MPC_Outputs)
  (if (not (find-package "MAVROS_MSGS"))
    (make-package "MAVROS_MSGS"))
  (shadow 'MPC_Outputs (find-package "MAVROS_MSGS")))
(unless (find-package "MAVROS_MSGS::MPC_OUTPUTS")
  (make-package "MAVROS_MSGS::MPC_OUTPUTS"))

(in-package "ROS")
;;//! \htmlinclude MPC_Outputs.msg.html


(defclass mavros_msgs::MPC_Outputs
  :super ros::object
  :slots (_mpc_mv_out ))

(defmethod mavros_msgs::MPC_Outputs
  (:init
   (&key
    ((:mpc_mv_out __mpc_mv_out) (make-array 2 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _mpc_mv_out __mpc_mv_out)
   self)
  (:mpc_mv_out
   (&optional __mpc_mv_out)
   (if __mpc_mv_out (setq _mpc_mv_out __mpc_mv_out)) _mpc_mv_out)
  (:serialization-length
   ()
   (+
    ;; float32[2] _mpc_mv_out
    (* 4    2)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[2] _mpc_mv_out
     (dotimes (i 2)
       (sys::poke (elt _mpc_mv_out i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[2] _mpc_mv_out
   (dotimes (i (length _mpc_mv_out))
     (setf (elt _mpc_mv_out i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get mavros_msgs::MPC_Outputs :md5sum-) "74f4756230813d28d9765644d38e8155")
(setf (get mavros_msgs::MPC_Outputs :datatype-) "mavros_msgs/MPC_Outputs")
(setf (get mavros_msgs::MPC_Outputs :definition-)
      "
float32[2] mpc_mv_out
")



(provide :mavros_msgs/MPC_Outputs "74f4756230813d28d9765644d38e8155")


