#include <iostream>

using namespace std;

static constexpr int MAX = 10;

static int getMaxGoldRecHelper(int arr[][MAX], int r, int c, int ROWS, int COLS) {

	if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
		return 0;

	return arr[r][c] +
		max(getMaxGoldRecHelper(arr, r, c + 1, ROWS, COLS),
			max(getMaxGoldRecHelper(arr, r - 1, c + 1, ROWS, COLS),
				getMaxGoldRecHelper(arr, r + 1, c + 1, ROWS, COLS)));
}

int getMaxGoldRec(int arr[][MAX], int ROWS, int COLS) {
	int sum = 0;
	int sumFinal = 0;
	int c = 0;

	for (int i = 0; i < ROWS; i++) {
		sum = getMaxGoldRecHelper(arr, i, c, ROWS, COLS);

		if (sum > sumFinal)
			sumFinal = sum;
	}

	return sumFinal;
}

int getMaxGoldDP(int arr[][MAX], int ROWS, int COLS) {
	int goldArr[ROWS][COLS] = {0};
	int right;
	int rightUp;
	int rightDown;
	int result = 0;

	for (int i = COLS - 1; i >= 0; i--) {
		for (int j = 0; j < ROWS; j++) {
			if (i == COLS - 1)
				right = 0;
			else
				right = goldArr[j][i + 1];

			if (j == 0 || i == COLS - 1)
				rightUp = 0;
			else
				rightUp = goldArr[j - 1][i + 1];

			if (j == ROWS - 1 || i == COLS - 1)
				rightDown = 0;
			else
				rightDown = goldArr[j + 1][i + 1];

			goldArr[j][i] = arr[j][i] + max(right,
				max(rightUp, rightDown));
		}
	}

	result = goldArr[0][0];
	for (int i = 1; i < ROWS; i++) {
		if (result < goldArr[i][0])
				result = goldArr[i][0];
	}

	return result;
}

int main(int args, char **argv) {
	int gold[MAX][MAX] = {{10, 33, 13, 15},
		{22, 21, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 14, 2}};

	cout<<getMaxGoldRec(gold, 4, 4)<<endl;

	cout<<getMaxGoldDP(gold, 4, 4)<<endl;

	return 0;
}
