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
	
	char arr[] = "start gnuplot -p -e \"set xrange [-5:5]\" -e \"set yrange [-5:5]\" -e \"plot \'8.txt\' u 1:2 w points, \'8.txt\' u 3:4 w points\" > NULL 2>&1";
	
	system(arr);
	
	system("PAUSE>NUL");
	return 0;
}
