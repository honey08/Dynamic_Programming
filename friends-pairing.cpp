#include <iostream>

using namespace std;

int getNumPairsRec(int num) {
	if (num <= 0)
		return 0;

	if (num == 1)
		return 1;

	if (num == 2)
		return 2;

	return getNumPairsRec(num - 1) +
		 (num - 1)*getNumPairsRec(num - 2);
}

int getNumPairsDP(int num) {
	int pair[num + 1] = {0};
	pair[0] = 0;
	pair[1] = 1;
	pair[2] = 2;

	for (int i=3; i<=num; i++)
		pair[i] = pair[i-1] + (i-1)*pair[i - 2];

	return pair[num];
}

int main(int argc, char **argv) {
	cout<<getNumPairsRec(3)<<endl;
	cout<<getNumPairsDP(3)<<endl;

	cout<<getNumPairsRec(4)<<endl;
	cout<<getNumPairsDP(4)<<endl;

	cout<<getNumPairsRec(10)<<endl;
	cout<<getNumPairsDP(10)<<endl;
}
