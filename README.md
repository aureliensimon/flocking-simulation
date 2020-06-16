# Flocking simulation : Boids

In 1986, Craig Reynolds made a computer model of coordinated animal motion such as bird flocks and fish schools. It called the generic simulated flocking creatures **boids**. 

## Rules
The basic flocking model consists of three simple steering behaviors which describe how an individual boid maneuvers based on the positions and velocities its nearby flockmates.

**Separation**

<img align="left" width="500" height="500" src="img/separation.png">
<br><br><br>
steer to avoid crowding local flockmates

**Alignment**

<img align="left" width="500" height="500" src="img/alignment.png">
<br><br><br>
steer towards the average heading of local flockmates 

**Cohesion**

<img align="left" width="500" height="500" src="img/cohesion.png">
<br><br><br>
steer to move toward the average position of local flockmates


