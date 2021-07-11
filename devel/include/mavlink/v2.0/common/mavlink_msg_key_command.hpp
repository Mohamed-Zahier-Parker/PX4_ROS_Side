// MESSAGE KEY_COMMAND support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief KEY_COMMAND message
 *
 * Keyboard char command.
 */
struct KEY_COMMAND : mavlink::Message {
    static constexpr msgid_t MSG_ID = 229;
    static constexpr size_t LENGTH = 9;
    static constexpr size_t MIN_LENGTH = 9;
    static constexpr uint8_t CRC_EXTRA = 203;
    static constexpr auto NAME = "KEY_COMMAND";


    uint64_t time_usec; /*< [us]   */
    char command; /*<    */


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
        ss << "  command: " << +command << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_usec;                     // offset: 0
        map << command;                       // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_usec;                     // offset: 0
        map >> command;                       // offset: 8
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
