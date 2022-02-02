#include <iostream>

using namespace std;

int dp[50] = { 0, 1, };

int fibonachi(int n) {
	if (n == 0 || n == 1) {
		return dp[n];
	}
	else if (dp[n] == 0) {
		dp[n] = fibonachi(n - 1) + fibonachi(n - 2);
	}
	return dp[n];
}

int main() {
	int N;
	cin >> N;

	int num;

	for (int i = 0; i < 10; i++) {
		cout << fibonachi(i) << endl;
	}
}