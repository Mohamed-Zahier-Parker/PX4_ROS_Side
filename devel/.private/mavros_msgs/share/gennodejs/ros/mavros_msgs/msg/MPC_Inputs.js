// Auto-generated. Do not edit!

// (in-package mavros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class MPC_Inputs {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.mpc_ref_in = null;
      this.mpc_mo_in = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('mpc_ref_in')) {
        this.mpc_ref_in = initObj.mpc_ref_in
      }
      else {
        this.mpc_ref_in = new Array(38).fill(0);
      }
      if (initObj.hasOwnProperty('mpc_mo_in')) {
        this.mpc_mo_in = initObj.mpc_mo_in
      }
      else {
        this.mpc_mo_in = new Array(2).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MPC_Inputs
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Check that the constant length array field [mpc_ref_in] has the right length
    if (obj.mpc_ref_in.length !== 38) {
      throw new Error('Unable to serialize array field mpc_ref_in - length must be 38')
    }
    // Serialize message field [mpc_ref_in]
    bufferOffset = _arraySerializer.float32(obj.mpc_ref_in, buffer, bufferOffset, 38);
    // Check that the constant length array field [mpc_mo_in] has the right length
    if (obj.mpc_mo_in.length !== 2) {
      throw new Error('Unable to serialize array field mpc_mo_in - length must be 2')
    }
    // Serialize message field [mpc_mo_in]
    bufferOffset = _arraySerializer.float32(obj.mpc_mo_in, buffer, bufferOffset, 2);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MPC_Inputs
    let len;
    let data = new MPC_Inputs(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [mpc_ref_in]
    data.mpc_ref_in = _arrayDeserializer.float32(buffer, bufferOffset, 38)
    // Deserialize message field [mpc_mo_in]
    data.mpc_mo_in = _arrayDeserializer.float32(buffer, bufferOffset, 2)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 160;
  }

  static datatype() {
    // Returns string type for a message object
    return 'mavros_msgs/MPC_Inputs';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '44361b7e6cdaa7dc8aa5f281d51dafe6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MPC_Inputs(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.mpc_ref_in !== undefined) {
      resolved.mpc_ref_in = msg.mpc_ref_in;
    }
    else {
      resolved.mpc_ref_in = new Array(38).fill(0)
    }

    if (msg.mpc_mo_in !== undefined) {
      resolved.mpc_mo_in = msg.mpc_mo_in;
    }
    else {
      resolved.mpc_mo_in = new Array(2).fill(0)
    }

    return resolved;
    }
};

module.exports = MPC_Inputs;
