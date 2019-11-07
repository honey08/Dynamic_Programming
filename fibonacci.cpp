#include <iostream>

using namespace std;

/*
 * The Fibonacci numbers are the numbers in the following integer sequence.
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
 * Fn = Fn-1 + Fn-2
 */
class fibonacci {
	int xthNum;

	int calFibRec(int num) {
		if (num == 0) return 0;
		if (num == 1) return 1;

		return calFibRec(num -1) + calFibRec(num - 2);
	}

public:
	fibonacci(int xx) {
		xthNum = xx;
	}

	int calFibUsingRec(void) {
		return calFibRec(xthNum);
	}

	int calFibUsingDP(void)
	{
		if (xthNum == 0) return 0;
		if (xthNum == 1) return 1;

		int arr[xthNum + 1];
		int i = 2;
		arr[0] = 0;
		arr[1] = 1;

		while(i <= xthNum) {
			arr[i] = arr[i-1] + arr[i-2];
			i++;
		}

		return arr[xthNum];
	}
};

int main(int argc, char **argv) {
	int num;
	cout<<"Enter a number ";
	cin>>num;

	fibonacci obj1(num);
	cout<<num<<"th fibonacci number using recursion is "<<obj1.calFibUsingRec()<<endl;
	cout<<num<<"th fibonacci number using DP is "<<obj1.calFibUsingDP()<<endl;

	return 0;
}
