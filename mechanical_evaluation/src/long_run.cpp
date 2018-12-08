#include <cwru_davinci/uv_control/psm_interface.h>

#include <geometry_msgs/PoseArray.h>

int main(int argc, char** argv){
	std::vector<std::vector<double> > targets = {
		{-0.70, -0.10, 0.15,  0.05, 0.02, -0.15, 0.1},
		{-0.75, -0.05, 0.14,  0.15, 0.025, -0.1, 0.1},
		{-0.60,  0.00, 0.13,  0.00, 0.02, -0.15, 0.1},
		{-0.65,  0.02, 0.12, -0.15, 0.025, 0.15, 0.1},
		{-0.55,  0.05, 0.11, -0.1,  0.02, -0.15, 0.1},
		{-0.50,  0.10, 0.10, -0.05, 0.020, 0.15, 0.1},
	};

	ros::init(argc, argv, "tracer");
	ros::NodeHandle nh;

	psm_interface psm = psm_interface(1, nh);

	while(ros::ok()){
		for(int i = 0; i < 6; i++){
			psm.go(targets[i], 2.0);
			geometry_msgs::PoseArray t = *(ros::topic::waitForMessage<geometry_msgs::PoseArray>("/polaris_sensor/targets", nh));
			geometry_msgs::Pose t_base = t.poses[0];
			geometry_msgs::Pose t_grip = t.poses[1];
			printf(
				"%f, %f, %f, %f, %f, %f, %f,  %f, %f, %f, %f, %f, %f, %f\n",

				t_base.position.x, t_base.position.y, t_base.position.z,
				t_base.orientation.x, t_base.orientation.y, t_base.orientation.z, t_base.orientation.w,

				t_grip.position.x, t_grip.position.y, t_grip.position.z,
				t_grip.orientation.x, t_grip.orientation.y, t_grip.orientation.z, t_grip.orientation.w
			);
		}	
	}

	return 0;
}
