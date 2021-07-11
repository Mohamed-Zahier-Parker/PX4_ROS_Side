// MESSAGE MPC_INPUTS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief MPC_INPUTS message
 *
 * MPC inputs.
 */
struct MPC_INPUTS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 227;
    static constexpr size_t LENGTH = 168;
    static constexpr size_t MIN_LENGTH = 168;
    static constexpr uint8_t CRC_EXTRA = 251;
    static constexpr auto NAME = "MPC_INPUTS";


    uint64_t time_usec; /*< [us]   */
    std::array<float, 38> mpc_ref_in; /*<    */
    std::array<float, 2> mpc_mo_in; /*<    */


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
        ss << "  mpc_ref_in: [" << to_string(mpc_ref_in) << "]" << std::endl;
        ss << "  mpc_mo_in: [" << to_string(mpc_mo_in) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_usec;                     // offset: 0
        map << mpc_ref_in;                    // offset: 8
        map << mpc_mo_in;                     // offset: 160
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_usec;                     // offset: 0
        map >> mpc_ref_in;                    // offset: 8
        map >> mpc_mo_in;                     // offset: 160
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
