#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include "my_messages/msg/two_ints.hpp"

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);

  auto node=rclcpp::Node::make_shared("ros1_like_subscriber_test");
  auto subscription = node->create_subscription<my_messages::msg::TwoInts>(
    "msg_test",
    rclcpp::QoS(10),
    [node](const my_messages::msg::TwoInts::SharedPtr msg) ->void {
     RCLCPP_INFO(node->get_logger(), "I heard: %d, %d", msg->a, msg->b);
    }
  );
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
