#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	int capac = 50, bRate = 1;
	double dt = 1, population = 10;
	
	
	ofstream fout;
	
	fout.open("FishPrice2.txt");
	
	for(int i = 0; i <= 675; i++) {
		
		double effort = .02;
			
		population += (1 - population / capac - effort * population) * dt;
		
		double price = 12 * population - 0.2 * population * population;
		
		double costPerFish = 0.01 * population * population * population - 0.6 * population * population * 			population + 13 * population + 35 ;
		
		double profit = effort*population*price - effort*population*costPerFish;
		
		fout<<i<<"	"<<profit<<endl;
	}
	
	fout<<"e";
	
	fout.close();
	
	return 0;
	
}