#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include <time.h>

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
	
	char arr[] = "start gnuplot -p -e \"set xrange [-10:10]\" -e \"set yrange [-10:10]\" -e \"plot \'PitViper.txt\' u 1:2 w linespoints, \'PitViper.txt\' u 3:4 w linespoints\" > NULL 2>&1";
	
	ofstream fout;
	
	vector <Point> mouse;
	vector <Point> snake;
	
	Point snakeStart;
	snakeStart.set_x(1);
	snakeStart.set_y(0);
	
	snake.push_back(snakeStart);

	Point mouseStart;
	mouseStart.set_x(0);
	mouseStart.set_y(0);
	
	mouse.push_back(mouseStart);
	
	fout.open("PitViper.txt");
		
	fout<<snake.back().return_x()<<"	"<<snake.back().return_y()<<"	"<<mouse.back().return_x()<<"	"<<mouse.back().return_y()<<endl;

	bool position = false;
	
	//-e 'unset key' -e 'set term jpeg' -e \"set output \'0000.jpg\'\"
	//-e \"set terminal jpg color enhanced \"Helvetica\" 20\"
	// -e \"set terminal jpeg enhanced font helvetica 20\"
	
	char index[] = "abcdefghijklmnopqrstuvwxyz123456789";
	
	srand(time(0));
	
	do {
		
		double distance = sqrt((snake.back().return_x() - mouse.back().return_x()) * (snake.back().return_x() - mouse.back().return_x()) + (snake.back().return_y() - mouse.back().return_y()) * (snake.back().return_y() - mouse.back().return_y()));

		Point s;
		
		int choice = rand() % 4;
		
		if (distance == 1) {
			
			if(snake.back().return_x() > mouse.back().return_x()) {

				s.set_x( snake.back().return_x() - abs(snake.back().return_x() - mouse.back().return_x()) );
				s.set_y(snake.back().return_y());

			}
			else if(snake.back().return_x() < mouse.back().return_x()) {

				s.set_x( snake.back().return_x() + abs(snake.back().return_x() - mouse.back().return_x()) );
				s.set_y(snake.back().return_y());

			}

			if(snake.back().return_y() > mouse.back().return_y()) {

				s.set_y( snake.back().return_y() - abs(snake.back().return_y() - mouse.back().return_y()) );
				s.set_x(snake.back().return_x());

			}
			else if(snake.back().return_y() < mouse.back().return_y()) {

				s.set_y( snake.back().return_y() + abs(snake.back().return_y() - mouse.back().return_y()) );
				s.set_x(snake.back().return_x());

			}
			
		}
		else if(choice == 0) {
			
			s.set_y(snake.back().return_y() + 1);
			s.set_x(snake.back().return_x());
			
		} 
		else if (choice == 1) {
			
			s.set_x(snake.back().return_x() + 1);
			s.set_y(snake.back().return_y());
			
		}
		else if (choice == 2) {
			
			s.set_y(snake.back().return_y() - 1);
			s.set_x(snake.back().return_x());
			
		}
		else if (choice == 3) {
			
			s.set_x(snake.back().return_x() - 1);
			s.set_y(snake.back().return_y());
			
		}

		snake.push_back(s);


		Point m;

		choice = rand() % 5;
		
		if(choice == 0) {
			
			m.set_y(mouse.back().return_y() + 1);
			m.set_x(mouse.back().return_x());
			
		} 
		else if (choice == 1) {
			
			m.set_x(mouse.back().return_x() + 1);
			m.set_y(mouse.back().return_y());
			
		}
		else if (choice == 2) {
			
			m.set_y(mouse.back().return_y() - 1);
			m.set_x(mouse.back().return_x());
			
		}
		else if (choice == 3) {
			
			m.set_x(mouse.back().return_x() - 1);
			m.set_y(mouse.back().return_y());
			
		}
		else if (choice == 4) {

			m.set_x(mouse.back().return_x());
			m.set_y(mouse.back().return_y());
			
		}
		
		mouse.push_back(m);

		if(distance == 0) {

			position = true;

		}
		
		fout<<snake.back().return_x()<<"	"<<snake.back().return_y()<<"	"<<mouse.back().return_x()<<"	"<<mouse.back().return_y()<<endl;
		
	} while(position == false);
	
	
	fout.close();
	
	system("PAUSE>NUL");
	return 0;
	
}
