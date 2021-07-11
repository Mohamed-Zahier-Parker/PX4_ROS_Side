// Auto-generated. Do not edit!

// (in-package mavros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class MPC_Outputs {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mpc_mv_out = null;
    }
    else {
      if (initObj.hasOwnProperty('mpc_mv_out')) {
        this.mpc_mv_out = initObj.mpc_mv_out
      }
      else {
        this.mpc_mv_out = new Array(2).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MPC_Outputs
    // Check that the constant length array field [mpc_mv_out] has the right length
    if (obj.mpc_mv_out.length !== 2) {
      throw new Error('Unable to serialize array field mpc_mv_out - length must be 2')
    }
    // Serialize message field [mpc_mv_out]
    bufferOffset = _arraySerializer.float32(obj.mpc_mv_out, buffer, bufferOffset, 2);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MPC_Outputs
    let len;
    let data = new MPC_Outputs(null);
    // Deserialize message field [mpc_mv_out]
    data.mpc_mv_out = _arrayDeserializer.float32(buffer, bufferOffset, 2)
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'mavros_msgs/MPC_Outputs';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '74f4756230813d28d9765644d38e8155';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    float32[2] mpc_mv_out
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MPC_Outputs(null);
    if (msg.mpc_mv_out !== undefined) {
      resolved.mpc_mv_out = msg.mpc_mv_out;
    }
    else {
      resolved.mpc_mv_out = new Array(2).fill(0)
    }

    return resolved;
    }
};

module.exports = MPC_Outputs;
