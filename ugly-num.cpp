#include <iostream>
#include <sstream>

using namespace std;

/*
 * Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
 * The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ... shows the
 * first 11 ugly numbers. By convention, 1 is included.
 */
class uglyNumber {
	int xthNum;

	bool isUgly(int num) {
		while(num % 2 == 0) {
			num = num / 2;
		}

		while(num % 3 == 0) {
			num = num / 3;
		}

		while(num % 5 == 0) {
			num = num / 5;
		}

		return (num == 1)? true: false;
	}

public:
	uglyNumber(int xx) {
		xthNum = xx;
	}

	int calXthUglyNum(void) {
		if (xthNum == 1) {
			return 1;
		}

		int count = 1;
		int i = 1;

		while(count < xthNum) {
			i++;
			if (isUgly(i) == true) {
				count++;
			}
		}

		return i;
	}
};

int main(int argc, char **argv) {
	if (argc < 2) {
		cout<<"Plase pass intput\n";
		return 0;
	}

	int nthNum;
	stringstream ss(argv[1]);
	ss >> nthNum;

	uglyNumber obj1(nthNum);
	cout<<nthNum<<" ugly number is "<<obj1.calXthUglyNum()<<endl;

	return 0;
}

