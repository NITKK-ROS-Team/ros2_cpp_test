#ifndef SUB_HPP
#define SUB_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

#include <chrono>

namespace pub_sub_int32
{

class sub_int:public rclcpp::Node
{
    public:
        // Subscriber definition.
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub;

        // Callback function when message is received.
        void sub_int_thread(const std_msgs::msg::Int32::SharedPtr msg);

        // Initialize this class.
        sub_int(const rclcpp::NodeOptions & options);
};

}

#endif