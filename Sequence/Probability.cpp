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
	int amount[16][340];

	statistic[16][200]
	
	ofstream fout;
	
	char sequence[340][200];

	ifstream fin;

	char data[] = "Sequence0.txt";
		
	char index[] = "abcdefghijklmnopqrstuvwxyz123456789";

	fin.open("SequenceAA");

	fin.open("SequenceAC");

	fin.open("SequenceAT");

	fin.open("SequenceAG");

	fin.open("SequenceCA");

	fin.open("SequenceCC");

	fin.open("SequenceCG");

	fin.open("SequenceCT");

	fin.open("SequenceGA");

	fin.open("SequenceGC");

	fin.open("SequenceGG");

	fin.open("SequenceGT");

	fin.open("SequenceTA");

	fin.open("SequenceTC");

	fin.open("SequenceTG");

	fin.open("SequenceTT");
	
	fout.open("ProbabilityPositive.txt");
	
	for (int i=0; i<16; i++){
		
		for (int j=0; j<340; j++){

			fin>>amount[i][j];
			
			for (int k = 0; k < 199; k++){

				if (j==0){

					statistic[j][k]=pow(amount[i][j],

						if);
				}

				else{

					statistic[j][k]=statistic[j][k]*amount[i][j]

				}

			}

		}
	}

	fout.close();

	return 0;

}
