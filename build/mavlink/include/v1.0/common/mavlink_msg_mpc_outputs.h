#pragma once
// MESSAGE MPC_OUTPUTS PACKING

#define MAVLINK_MSG_ID_MPC_OUTPUTS 228


typedef struct __mavlink_mpc_outputs_t {
 uint64_t time_usec; /*< [us]  */
 float mpc_mv_out[2]; /*<   */
} mavlink_mpc_outputs_t;

#define MAVLINK_MSG_ID_MPC_OUTPUTS_LEN 16
#define MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN 16
#define MAVLINK_MSG_ID_228_LEN 16
#define MAVLINK_MSG_ID_228_MIN_LEN 16

#define MAVLINK_MSG_ID_MPC_OUTPUTS_CRC 159
#define MAVLINK_MSG_ID_228_CRC 159

#define MAVLINK_MSG_MPC_OUTPUTS_FIELD_MPC_MV_OUT_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MPC_OUTPUTS { \
    228, \
    "MPC_OUTPUTS", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mpc_outputs_t, time_usec) }, \
         { "mpc_mv_out", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_mpc_outputs_t, mpc_mv_out) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MPC_OUTPUTS { \
    "MPC_OUTPUTS", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mpc_outputs_t, time_usec) }, \
         { "mpc_mv_out", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_mpc_outputs_t, mpc_mv_out) }, \
         } \
}
#endif

/**
 * @brief Pack a mpc_outputs message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us]  
 * @param mpc_mv_out   
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mpc_outputs_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *mpc_mv_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPC_OUTPUTS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, mpc_mv_out, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN);
#else
    mavlink_mpc_outputs_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.mpc_mv_out, mpc_mv_out, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPC_OUTPUTS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_CRC);
}

/**
 * @brief Pack a mpc_outputs message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us]  
 * @param mpc_mv_out   
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mpc_outputs_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *mpc_mv_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPC_OUTPUTS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, mpc_mv_out, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN);
#else
    mavlink_mpc_outputs_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.mpc_mv_out, mpc_mv_out, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPC_OUTPUTS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_CRC);
}

/**
 * @brief Encode a mpc_outputs struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mpc_outputs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mpc_outputs_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mpc_outputs_t* mpc_outputs)
{
    return mavlink_msg_mpc_outputs_pack(system_id, component_id, msg, mpc_outputs->time_usec, mpc_outputs->mpc_mv_out);
}

/**
 * @brief Encode a mpc_outputs struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mpc_outputs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mpc_outputs_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mpc_outputs_t* mpc_outputs)
{
    return mavlink_msg_mpc_outputs_pack_chan(system_id, component_id, chan, msg, mpc_outputs->time_usec, mpc_outputs->mpc_mv_out);
}

/**
 * @brief Send a mpc_outputs message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us]  
 * @param mpc_mv_out   
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mpc_outputs_send(mavlink_channel_t chan, uint64_t time_usec, const float *mpc_mv_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPC_OUTPUTS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, mpc_mv_out, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPC_OUTPUTS, buf, MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_CRC);
#else
    mavlink_mpc_outputs_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.mpc_mv_out, mpc_mv_out, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPC_OUTPUTS, (const char *)&packet, MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_CRC);
#endif
}

/**
 * @brief Send a mpc_outputs message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mpc_outputs_send_struct(mavlink_channel_t chan, const mavlink_mpc_outputs_t* mpc_outputs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mpc_outputs_send(chan, mpc_outputs->time_usec, mpc_outputs->mpc_mv_out);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPC_OUTPUTS, (const char *)mpc_outputs, MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_CRC);
#endif
}

#if MAVLINK_MSG_ID_MPC_OUTPUTS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mpc_outputs_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *mpc_mv_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, mpc_mv_out, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPC_OUTPUTS, buf, MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_CRC);
#else
    mavlink_mpc_outputs_t *packet = (mavlink_mpc_outputs_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->mpc_mv_out, mpc_mv_out, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPC_OUTPUTS, (const char *)packet, MAVLINK_MSG_ID_MPC_OUTPUTS_MIN_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN, MAVLINK_MSG_ID_MPC_OUTPUTS_CRC);
#endif
}
#endif

#endif

// MESSAGE MPC_OUTPUTS UNPACKING


/**
 * @brief Get field time_usec from mpc_outputs message
 *
 * @return [us]  
 */
static inline uint64_t mavlink_msg_mpc_outputs_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field mpc_mv_out from mpc_outputs message
 *
 * @return   
 */
static inline uint16_t mavlink_msg_mpc_outputs_get_mpc_mv_out(const mavlink_message_t* msg, float *mpc_mv_out)
{
    return _MAV_RETURN_float_array(msg, mpc_mv_out, 2,  8);
}

/**
 * @brief Decode a mpc_outputs message into a struct
 *
 * @param msg The message to decode
 * @param mpc_outputs C-struct to decode the message contents into
 */
static inline void mavlink_msg_mpc_outputs_decode(const mavlink_message_t* msg, mavlink_mpc_outputs_t* mpc_outputs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mpc_outputs->time_usec = mavlink_msg_mpc_outputs_get_time_usec(msg);
    mavlink_msg_mpc_outputs_get_mpc_mv_out(msg, mpc_outputs->mpc_mv_out);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MPC_OUTPUTS_LEN? msg->len : MAVLINK_MSG_ID_MPC_OUTPUTS_LEN;
        memset(mpc_outputs, 0, MAVLINK_MSG_ID_MPC_OUTPUTS_LEN);
    memcpy(mpc_outputs, _MAV_PAYLOAD(msg), len);
#endif
}
