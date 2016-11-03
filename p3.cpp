//FOR THE USE IN CSCE464 
//Copyright © 2016 by George Steven Gaytan
//All Rights Reserved
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

const long NOISE = pow(10, -10);//10^-10 mW
const long Bi = 25;//25 dB


class Path_gains(){
	char trans;//transmitter
	char rec;//receiver
	long power;//pathgain of transmission
};

p3(int, vector<Path_gains>, vector<long>, 

int main(){
	//for mimicking hw problem
	//set parameters here
	int times = 4;

	p3(times, init_path_gains(), init_trans_pow());
}

p3(int times, vector<pathgains> path_gains, 
	vector<long> trans_pow, ){
	
}
