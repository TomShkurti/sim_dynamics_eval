sim = csvread('sim (2).csv');
hw = csvread('hw (2).csv');

%Found from the trajectory command message sent at the start of execution.
%Listen to /dvrk/PSM2/joint_traj_controller/follow_joint_trajectory/goal.
hardware_trajectory_start = 1544118428.365670203;
simulation_trajectory_start = 234.573000000;

n = 10;

t_sim = sim(:, 2) + sim(:, 3) * 0.000000001;
t_hw = hw(:, 2) + hw(:, 3) * 0.000000001;

t_sim  = t_sim - simulation_trajectory_start;
t_sim = t_sim (34 : end, :);
t_hw = t_hw - hardware_trajectory_start;

sim = sim(t_sim > 70.0, :);
t_sim = t_sim(t_sim > 70.0);
hw = hw(t_hw > 70.0, :);
t_hw = t_hw(t_hw > 70.0);

scatter(t_sim, sim(:, n));
hold on;
scatter(t_hw, hw(:, n));
hold off;

m = min(size(sim, 1), size(hw, 1));
sim = sim(1 : m, :);
hw = hw(1 : m, :);

e = abs(sim(:, n) - hw(:, n));
mean(e)
max(e)
% histogram(e)