#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> dp(N + 1);

	// Bottom-Up
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		// 3으로 나누어 떨어지면 '1를 뺀 기존 dp', '3으로 나눈 dp 값 + 1' 중 최솟값 택
		if ((i % 3) == 0) dp[i] = min(dp[i], dp[i / 3] + 1);

		// 2로 나누어 떨어지면 '1을 뺸 기존 dp', '2로 나눈 dp 값 + 1' 중 최솟값 택
		if ((i % 2) == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N] << endl;

	return 0;
}