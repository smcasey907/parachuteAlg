/*
 * main.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: Shawn
 */
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//velocity after opening her chute
double velocity (double elapsedTime){
	return (8.81917*((exp((-2.2224)*(30+elapsedTime)+66.3131)+1))/(exp((-2.2224)*(30+elapsedTime)+66.3131)-1));
}

//Algorithm for each jump. Each iteration takes into account a later pull time
//and returns the total time it takes for her to reach the ground with each
//iteration
double jump (double pullTime){
	double currentHeight = 2800;
	double totalTime=0;
	while (pullTime >= totalTime){
		currentHeight += .1*((70/sqrt(2)*(exp(-0.396*totalTime)-1)/(exp(-0.396*totalTime)+1)));
		totalTime += .1;
	}
	double timeSinceChutePulled = 0;
	while (currentHeight > 0){
		currentHeight += .1*velocity(timeSinceChutePulled);
		totalTime += .1;
		timeSinceChutePulled += .1;

	}
	totalTime += .1;
	return totalTime;
}



int main (int argc, char** argv){
double vel = -9.5;
double currentTime = 999;
double pullChute = 30;
double currentVel = 0;

//Iterates through each jump until she finds a jump where her landing velocity is
//just above -9.5 meters per second and prints out the final values
while (currentVel > vel){
	currentTime = jump(pullChute);
	currentVel = 8.81917*((exp((-2.2224)*(currentTime-30)+66.3131)+1))/(exp((-2.2224)*(currentTime-30)+66.3131)-1);
	pullChute += .1;
}

cout <<"If Jane pulls the chute at " << pullChute -.1 << " seconds, she would land at a speed of\n" <<
		currentVel << " meters/second for a total fall time of " << currentTime << " seconds, giving her\n" <<
		"a total time to escape of " << 240-currentTime << " seconds" << endl;

}


