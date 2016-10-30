//FOR THE USE IN CSCE464 
//Copyright © 2016 by George Steven Gaytan
//All Rights Reserved
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib>

int count = 0;
int xCount = 0;
const int packet_trans = 1000;

class Simulation {
    int X, Xi, Y, Ri;
	bool success;
}

Simulation::Simulation(){
	X = 3;
	Y = 2;
	Ri = 1;
	Xi = 1;
}

int main(){
	ofstream myfile;
	myfile.open ("hw5p2.txt");
	myfile << p2();
	myfile.close();
	return 0;

}

string p2(){
	Simulation sim;
	vector<Simulation> simVect;
	while (count < packet_trans){
		xCount = 0;

		while(xCount < sim.X){
			if(sim.Xi >= 0 && sim.Xi <= 15){
				if(sim.Ri == 1){
					sim.Xi++;
					sim.success = true;
					simVect.push_back(sim);
					count++;
					xCount++;
	            }
				if(sim.Ri == 2){
					sim.Xi++;
					sim.success = true;
					simVect.push_back(sim);
					count++;
					xCount++;
				}
				if(sim.Ri == 3){
					sim.Xi++;
					sim.success = false;
					simVect.push_back(sim);
					count++;
					xCount++;
				}
			}
		}

	}
}





