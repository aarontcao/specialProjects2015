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
	
	ofstream fout;
	
	char letter1;
	
	char letter2;

	double amount[340];

	char sequence[340][200];

	ifstream fin;

	char data[] = "Sequence0.txt";
		
	char index[] = "abcdefghijklmnopqrstuvwxyz123456789";

	fin.open("SequenceInt.txt");
	
	fout.open("SequencePositiveLast.txt");
	
	for (int i=0; i<340; i++){
		
		for (int j=0; j<200; j++){
			
			fin>>sequence[i][j];
			
			if (j==199){
				
				if (sequence[i][j]='A'){

					amount[i]=0.258;

				}

				if (sequence[i][j]='C'){

					amount[i]=0.242;

				}

				if (sequence[i][j]='G'){

					amount[i]=0.242;

				}

				if (sequence[i][j]='T'){

					amount[i]=0.259;

				}
				
			}
		}
		
		fout<<amount[i]<<endl;
	}


	fout.close();

	return 0;

}
