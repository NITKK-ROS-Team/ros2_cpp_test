#ifndef PUB_HPP
#define PUB_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

#include <chrono>

namespace pub_sub_int32
{

class pub_int:public rclcpp::Node
{
    private:
        // Publisher definition.
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub;

        // Timer definition.
        rclcpp::TimerBase::SharedPtr timer;

        // Publish number function (method).
        void pub_number();

    public:
        // Initialize this class.
        pub_int(const rclcpp::NodeOptions & options);
};

}

#endif