# ROS2 咖啡店模拟项目 (Customer & Peets)

## 📖 项目概述
本项目为ROS2学习实践项目，模拟咖啡店顾客与咖啡师的交互场景。包含两个核心节点：
- **顾客节点 (Customer)**：生成饮品订单请求
- **咖啡师节点 (Peets)**：处理订单并返回制作状态

## 🛠️ 环境配置
- **操作系统**: Ubuntu 20.04 LTS
- **ROS2版本**: Foxy Fitzroy
- **编译系统**: colcon
- **依赖项**: 
  ```bash
  sudo apt install ros-foxy-rclcpp ros-foxy-std-msgs

## 🗂️ 项目结构
```text
crs_ws/
├── build/                  # 编译中间文件
├── install/                # 安装目录
├── log/                    # 日志文件
├── srv/
│   ├── OrderDrink.srv
└── src/
    └── customer_and_peets/ # ROS2功能包
        ├── src/
        │   ├── lanuch
        │   │   ├── customer_and_peets_launch.py
        │   ├── nodes/
        │   │   ├── customer.cpp  # 顾客节点源码
        │   │   ├── peets.cpp     # 咖啡师节点源码
        │   ├── services/
        │   │   ├── order_drink_server.cpp # 咖啡师服务端源码
        │   │   ├── order_drink_client.cpp # 客户客户端源码
        ├── include/        # 头文件目录
        ├── CMakeLists.txt  # 构建配置
        └── package.xml     # 包配置文件


```

## 🚀 快速启动
### 1. 克隆仓库
```bash
git clone git@github.com:MrDynimate/ROS2_Try_proj.git
cd ROS2_Try_proj
```

### 2.编译项目
```bash
colcon build --packages-select customer_and_pee
```

### 3.配置环境变量
```bash
echo "source ~/crs_ws/install/setup.bash" >> ~/.bashrc
```

### 4.运行节点
**打开终端1（顾客）：**
```bash
source install/setup.bash
ros2 run customer_and_peets customer
```
**打开终端2（咖啡师）：**
```bash
source install/setup.bash
ros2 run customer_and_peets peets
```
## 📝 节点功能说明
### 顾客节点 (customer)

    生成随机饮品订单（咖啡类型、糖量、温度）

    发布到 /order_request 话题

    订阅 /order_status 接收制作状态

    消息频率：2秒/次

### 咖啡师节点 (peets)

    订阅 /order_request 接收订单

    模拟饮品制作过程（5秒延时）

    发布制作状态到 /order_status

    支持订单优先级处理
## 🔧 自定义配置
修改 customer.cpp 中的参数调整行为：
```cpp
// 修改订单频率（单位：毫秒）
timer_ = this->create_wall_timer(
  2000ms,  // 修改此数值
  std::bind(&Customer::make_order, this));
```

## 🤝 协作开发指南
### 分支命名规则*
| 分支类型 | 命名格式         | 示例                   |
| :------ | :------------- | :--------------------- |
| 功能开发 | feature/功能描述 | feature/priority-queue |
| 问题修复	| hotfix/问题描述 | hotfix/memory-leak     |

### 典型开发流程
```bash
# 创建新功能分支
git checkout -b feature/order-validation

# 提交修改（使用规范前缀）
git commit -m "feat: 添加订单有效性验证逻辑"

# 推送到远程
git push origin feature/order-validation

# 在GitHub创建Pull Request
```

## 🧪 调试建议
查看话题数据流：
```bash
ros2 topic echo /order_request
ros2 topic echo /order_status
```
查看节点关系图：
```bash
rqt_graph
```

## 📌 注意事项
1.首次运行前需执行：
```bash
rosdep install --from-paths src --ignore-src -y
```
2.若修改消息类型，需要重新编译：
```bash
colcon build --symlink-install
source install/setup.bash
```
## 🧩 迭代方向
- [ ] Lunch文件编写
- [ ] 参数变化
- [ ] 更多节点功能

## 📜 许可证
[MIT license](https://www.mit-license.org/)

---
__项目维护者__：MrDynimate

__最后更新__：2025-3-11

__Version__：v0.0.1-beta








