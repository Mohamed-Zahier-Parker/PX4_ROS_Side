// MESSAGE MPC_OUTPUTS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief MPC_OUTPUTS message
 *
 * MPC outputs.
 */
struct MPC_OUTPUTS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 228;
    static constexpr size_t LENGTH = 16;
    static constexpr size_t MIN_LENGTH = 16;
    static constexpr uint8_t CRC_EXTRA = 159;
    static constexpr auto NAME = "MPC_OUTPUTS";


    uint64_t time_usec; /*< [us]   */
    std::array<float, 2> mpc_mv_out; /*<    */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_usec: " << time_usec << std::endl;
        ss << "  mpc_mv_out: [" << to_string(mpc_mv_out) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_usec;                     // offset: 0
        map << mpc_mv_out;                    // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_usec;                     // offset: 0
        map >> mpc_mv_out;                    // offset: 8
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
