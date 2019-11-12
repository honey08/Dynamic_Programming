#include <iostream>

using namespace std;

int countWaysRec(int *coinArr, int size, int sum) {
	if (sum < 0) return 0;
	if (sum == 0) return 1;
	if (size <=0 && sum >= 1) return 0;

	return countWaysRec(coinArr, size - 1, sum) +
		countWaysRec(coinArr, size, sum - coinArr[size - 1]);
}

int countWaysDP(int *coinArr, int size, int sum) {
	int sumArr[sum + 1][size] = {0};
	int x = 0, y = 0;

	for (int i = 0; i < size; i++)
		sumArr[0][i] = 1;

	for (int i = 1; i <= sum; i++) {
		for (int j = 0; j < size; j++) {
			if (j - 1 >= 0)
				x = sumArr[i][j - 1];
			else
				x = 0;

			if (i - coinArr[j] >= 0)
				y =  sumArr[i - coinArr[j]][j];
			else
				y = 0;

			sumArr[i][j] = x + y;
		}
	}
	return sumArr[sum][size - 1];
}

int main(int argc, char **argv) {
	int sumCoins = 4;
	int coinArr[] = {1, 2, 3};
	cout<<countWaysRec(coinArr, sizeof(coinArr)/sizeof(int), sumCoins)<<endl;
	cout<<countWaysDP(coinArr, sizeof(coinArr)/sizeof(int), sumCoins)<<endl;

	int sumCoins1 = 10;
	int coinArr1[] = {2, 5, 3, 6};
	cout<<countWaysRec(coinArr1, sizeof(coinArr1)/sizeof(int), sumCoins1)<<endl;
	cout<<countWaysDP(coinArr1, sizeof(coinArr1)/sizeof(int), sumCoins1)<<endl;

	return 0;
}
