#include <iostream>

using namespace std;

// Recursive solution.
bool isSubsetPresent(int *arr, int length, int sum) {
	if (length == 0 && sum != 0) return false;

	if (sum == 0) return true;

	if (arr[length-1] > sum) return isSubsetPresent(arr, length-1, sum);

	return isSubsetPresent(arr, length-1, sum - arr[length-1]) ||
			isSubsetPresent(arr, length-1, sum);
}

// Dynamic Programming solution.
bool isSubsetPresentDP(int *arr, int len, int sum) {
	bool dp[len+1][sum + 1] = {false};

	for (int i = 0; i <= len; i++)
		dp[i][0] = true;

	for (int i = 1; i <= sum; i++)
		dp[0][i] = false;

	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < arr[i-1]) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}	
		}
	}
#if 0
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= sum; j++) {
			cout<<dp[i][j]<<"	";
		}
		cout<<endl;
	}
#endif

	return dp[len][sum];
}

int main(int argc, char **argv) {
	//int set[] = {1, 2, 3, 4, 5};
	int set[] = {};

	int length = sizeof(set)/sizeof(set[0]);

	bool ret1 = isSubsetPresent(set, length, 2);
	bool ret2 = isSubsetPresentDP(set, length, 2);

	if (ret1 == true) cout<<"Rec: Subset is present.\n";
	else cout<<"Rec: Subset not present.\n";

	if (ret2 == true) cout<<"DP: Subset is present.\n";
	else cout<<"DP :Subset not present.\n";

	return 0;
}
 
