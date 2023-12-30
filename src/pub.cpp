#include "pub_sub_int32/pub.hpp"

namespace pub_sub_int32
{
    void pub_int::pub_number()
    {
        // RCLCPP_INFO is print to console.
        RCLCPP_INFO(this->get_logger(), "data");
        // Create a new message.
        std_msgs::msg::Int32 msg;
        // Set the message data.
        static int i = 0;
        // Set the message data. "msg" has "int data" field.
        msg.data = i++;
        // Publish the message.
        pub->publish(msg);
    }

    pub_int::pub_int(const rclcpp::NodeOptions &options) : Node("pub_int", options)
    {
        // Create a publisher.
        // - "std_msgs::msg::Int32" is the message type.
        // - 10 is qos (Don't change).
        // - "pub_int" is the name of publisher.
        pub = this->create_publisher<std_msgs::msg::Int32>("pub_int", 10);

        // Create a timer definition. Interval is 1 second (= 1000ms).
        std::chrono::milliseconds period(1000);

        // Create a timer. Call "pub_number" method when timer is triggered.
        timer = this->create_wall_timer(period, std::bind(&pub_int::pub_number, this));
    }
}

int main(int argc, char * argv[])
{
    // Create a node.
    // - "pub_sub_int32::pub_int" is the class name.
    // - "rclcpp::NodeOptions()" is the options.
    rclcpp::init(argc, argv);
    auto node = std::make_shared<pub_sub_int32::pub_int>(rclcpp::NodeOptions());
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(pub_sub_int32::pub_int)