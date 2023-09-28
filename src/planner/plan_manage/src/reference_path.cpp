
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>


// using namespace ego_planner;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "reference_path_node");
  ros::NodeHandle renh;

  // ros::Publisher reference_path_wps_send = renh.advertise<geometry_msgs::PoseStamped>("/reference_path",1);
  ros::Publisher reference_path_wps_send = renh.advertise<geometry_msgs::PoseStamped>("/target_reference_node/target_odom",1);


  geometry_msgs::PoseStamped reference_path_wps;

  
  // double x[] = {0, 1.72, 5.38, 6.0, 7.0, 4.0, 0.0};
  // double y[] = {0, -0.30, -0.50, -0.50, -1.0, 0.00};
  // double z[] = {1, 1.0, 0.8, 0.8, 1.0, 0.85, 1.00};
  // int point_num = 3, idx = 0;

  double x[] = {0, 1.8,  3.8,  4.56, 5.58, 3.14, 1.0};
  double y[] = {0, -0.20, -0.01, 0.0,  0.140, 1.4,  0.0};
  double z[] = {1, 0.8,   0.8,   0.8,  0.8,   0.76, 0.82};
  int point_num = 7, idx = 0;

  //case for sim
  // double x[] = {0, 5, 10, 15, 10, 5};
  // double y[] = {0, 0, 0, 0, 0, 0};
  // double z[] = {1.0,1.0 , 1.0, 1.0, 1.0, 1.0};
  // int point_num = 6, idx = 0;


  while(ros::ok()) {
    reference_path_wps.header.frame_id = "world";
    reference_path_wps.header.stamp = ros::Time::now();
    reference_path_wps.pose.position.x = x[idx];
    reference_path_wps.pose.position.y = y[idx];
    reference_path_wps.pose.position.z = z[idx];

    std::cout << idx << " === " << point_num << std::endl;

    
    reference_path_wps_send.publish(reference_path_wps);
    ros::Duration(5.0).sleep();
    idx += 1;
    if (idx >= point_num) {
      std::cout << idx << " ++++ " << point_num << std::endl;
      break;
    }
  }
  // ros::spin();
  return 0;
}
