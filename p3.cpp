//FOR THE USE IN CSCE464 
//Copyright © 2016 by George Steven Gaytan
//All Rights Reserved
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

//global variables
const long NOISE = pow(10, -10);//10^-10 mW
const long Bi = 316;//25 dB

//object for Path_gains
struct Path_gain{
	char trans;//transmitter
	char rec;//receiver
	long power;//pathgain of transmission
};

//funct declarations
void p3(int);
//HELPERS
vector<Path_gain> init_path_gains();

int main(){
	//for mimicking hw problem
	//set parameters here
	int times = 4;
	p3(times);
}

void p3(int times){
	vector<Path_gain> pgv = init_path_gains();
	vector<double> trans_pow;
	int count = 0;
	for(int t = 1; t <= times; ++t){
		if (count == 0){
			trans_pow.push_back(Bi*(pgv[0].power + NOISE)/(pgv[2].power));
			count++;
			cout << "Power for A at time " << t << ":" << trans_pow[0] << endl;
			trans_pow.push_back(Bi*(pgv[1].power + NOISE)/(pgv[3].power));
			count++;
			cout << "Power for C at time " << t << ":" << trans_pow[1] << endl;
		} else {
			trans_pow.push_back(Bi*trans_pow[count-1]*(pgv[0].power + NOISE)/(pgv[2].power));
			cout << "Power for A at time " << t << ":" << trans_pow[count] << endl;
			count++;
			trans_pow.push_back(Bi*trans_pow[count-3]*(pgv[0].power + NOISE)/(pgv[3].power));
			cout << "Power for B at time " << t << ":" << trans_pow[count] << endl;
			count++;
		}
		
	}
}

vector<Path_gain> init_path_gains(){
	vector<Path_gain> pgv;//AB AD CB CD
	Path_gain pg;
	pg.trans = 'A';
	pg.rec = 'B';
	pg.power = pow(10,-5);
	pgv.push_back(pg);
	pg.rec = 'D';
	pg.power = pow(10, -8.2);
	pgv.push_back(pg);
	pg.trans = 'C';
	pg.rec = 'B';
	pg.power = pow(10,-7.8);
	pgv.push_back(pg);
	pg.rec = 'D';
	pg.power = pow(10, -6);
	pgv.push_back(pg);

	return pgv;
}