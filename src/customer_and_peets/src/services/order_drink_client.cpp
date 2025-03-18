#include "rclcpp/rclcpp.hpp"
#include "customer_and_peets/srv/order_drink.hpp"
#include <chrono>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("order_drink_client");
  auto client = node->create_client<customer_and_peets::srv::OrderDrink>("order_drink");

  auto request = std::make_shared<customer_and_peets::srv::OrderDrink::Request>();
  request->drink_name = "Latte";

  while (!client->wait_for_service(1s)) {
    RCLCPP_WARN(node->get_logger(), "Waiting for the service to be available...");
  }

  auto result_future = client->async_send_request(request);
  if (rclcpp::spin_until_future_complete(node, result_future) == rclcpp::FutureReturnCode::SUCCESS) {
    auto response = result_future.get();
    RCLCPP_INFO(node->get_logger(), "Response: %s", response->message.c_str());
  } else {
    RCLCPP_ERROR(node->get_logger(), "Failed to call service");
  }

  rclcpp::shutdown();
  return 0;
}
