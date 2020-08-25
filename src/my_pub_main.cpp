#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include "my_messages/msg/two_ints.hpp"
#include <chrono>

int main(int argc, char * argv[]){
  using namespace std::chrono_literals;

  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("minimal_publisher");
  auto publisher = node->create_publisher<my_messages::msg::TwoInts>("msg_test",rclcpp::QoS(10));
  auto message = std::make_shared<my_messages::msg::TwoInts>();

  rclcpp::WallRate loop_rate(1s);

  while(rclcpp::ok()){
    message->a = 3;
    message->b = 4;
    RCLCPP_INFO(node->get_logger(),"Pub:%d, %d",message->a, message->b);
    publisher->publish(*message);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
