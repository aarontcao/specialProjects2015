#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

class Point {
	
	private:
		int x;
		int y;
		
	public:
		Point() {
			x = y = 0;
		}
		
		Point(int xCoord, int yCoord) {
			x = xCoord;
			y = yCoord;	
		}
		
		void set_x(int xCoord) {
			x = xCoord;
		}
		
		void set_y(int yCoord) {
			y = yCoord;
		}
		
		int return_x() {
			return x;
		}
		
		int return_y() {
			return y;
		}
	
};

istream& operator>>(istream &is, Point &p) {
	
	int x, y;
	
	cout<<"x-coordinate: ";
	is>>x;
	p.set_x(x);
	
	cout<<"y-coordinate: ";
	is>>y;
	p.set_y(y);

	return is;
	
}

ostream& operator<<(ostream &os, Point p) {
	
	os<<"("<<p.return_x()<<", "<<p.return_y()<<")"<<endl;
	
	return os;
	
}

int main() {
	
	ofstream fout;
	
	vector <Point> list;
	
	Point origin;
	origin.set_x(0);
	origin.set_y(0);
	
	list.push_back(origin);
	
	int n;
	cout<<"Number of Steps: ";
	cin>>n;
	
	fout<<list[0].return_x()<<"		"<<list[0].return_y()<<endl;
	
	fout.open("WalkData.txt");
	
	char arr[] = "gnuplot -e 'unset key' -e 'set term jpeg' -e \"set output \'0000.jpg\'\" -e 'set xrange [-10:10]' -e 'set yrange [-10:10]' -e 	\"plot \'WalkData.txt\' u 1:2 with linespoints\"";
		
	char index[] = "abcdefghijklmnopqrstuvwxyz123456789";
	
	srand(time(0));
	for(int i = 1; i <= n; i++) {
		
		Point p;
		
		int choice = rand() % 2;
		
		if(choice == 0) {
			
			p.set_x(list[i - 1].return_x() + 1);
			
		} 
		else if (choice == 1) {
			
			p.set_x(list[i - 1].return_x() - 1);
			
		}
		
		choice = rand() % 2;
		
		if(choice == 0) {
					
			p.set_y(list[i - 1].return_y() + 1);		
					
		} 
		else if (choice == 1) {
					
			p.set_y(list[i - 1].return_y() - 1);
					
		}
		
		list.push_back(p);

		arr[61] = index[i];

		fout<<list[i].return_x()<<"		"<<list[i].return_y()<<endl;
		
		system(arr);
		
	}
	
	fout<<"e";
	fout.close();
	
	return 0;
	
}