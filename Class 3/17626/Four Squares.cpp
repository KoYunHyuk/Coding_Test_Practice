#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[50001];

int main() {
	cin >> N;

	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int minimum = 987654321;
		for (int j = 1; j*j <= i; j++) {
			minimum = min(minimum, dp[i - j * j]);
		}
		dp[i] = minimum + 1;
	}

	
	cout << dp[N];
}