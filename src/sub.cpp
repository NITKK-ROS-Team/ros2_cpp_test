#include "pub_sub_int32/sub.hpp"

namespace pub_sub_int32
{

    void sub_int::sub_int_thread(const std_msgs::msg::Int32::SharedPtr msg)
    {
        // get the message data. "msg" has "int data" field.
        int num = msg->data;

        // RCLCPP_INFO is print to console.
        RCLCPP_INFO(this->get_logger(), "data: %d", num);
    }

    // Initialize this class.
    sub_int::sub_int(const rclcpp::NodeOptions &options) : Node("sub_int", options)
    {
        using namespace std::chrono_literals;
        // Create a subscriber.
        // - "std_msgs::msg::Int32" is the message type.
        // - "pub_int" is the name of subscriber.
        // - 10 is qos (Don't change).
        // - "&sub_int::sub_int_thread" is the callback function when message is received.
        sub = this->create_subscription<std_msgs::msg::Int32>("pub_int", 10,
                    std::bind(&sub_int::sub_int_thread, this, std::placeholders::_1));
    }
}

int main(int argc, char * argv[])
{
    // Create a node.
    // - "pub_sub_int32::pub_int" is the class name.
    // - "rclcpp::NodeOptions()" is the options.
    rclcpp::init(argc, argv);
    auto node = std::make_shared<pub_sub_int32::sub_int>(rclcpp::NodeOptions());
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(pub_sub_int32::sub_int)
