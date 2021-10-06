# HOG_Human_Detection
# Acme Robotics Proposal – Perception

# Overview
Our design uses monocular camera to detect humans and get their positions in the robot’s reference frame. The module is developed in such a way that it detects humans (N>=1) and 
then creates bounding box around it. The distance of human is calculated from the pixel values of the bounding boxes. This system is perfect for use in robots like autonomous caddies in 
malls or airports for transportation which is underdevelopment by Acme. The module detects humans and if the distance is below a threshold, the vehicle slows down. The 
distance measurements can be fed to the odometry of the robot in order to control its motion. The project could be easily expanded and trained to detect more objects and take actions based on the type of the object.
The AIP design process allows continuous development. Because of this, new features and modules could be added over new sprints and thus making the module highly
customizable.
