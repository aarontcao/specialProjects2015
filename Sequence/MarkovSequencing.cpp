#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include <time.h>

using namespace std;

int main() {
	int amount[340];
	
	double total[340];
	
	ofstream fout;
	
	char letter1;
	
	char letter2;
	
	char sequence[340][200];

	ifstream fin;

	char data[] = "Sequence0.txt";
		
	char index[] = "abcdefghijklmnopqrstuvwxyz123456789";

	fin.open("SequenceInt.txt");
	
	fout.open("SequenceNaegativeTT.txt");

	cout<<"Pair?"<<endl;

	cin>>letter1;
	
	cin>>letter2;
	
	for (int i=0; i<340; i++){
		
		for (int j=0; j<200; j++){
			
			fin>>sequence[i][j];
			
		}
	}

	for(int i = 0; i < 340; i++){

		amount[i]=0;

		for (int j = 0; j < 200; j++){

			if (sequence[i][j]==letter1 and sequence[i][j+1]==letter2){

				amount[i]++;

			}
		}

		total[i]=pow(0.292,amount[i]);
		fout<<total[i]<<endl;
	}


	fout.close();

	return 0;

}
