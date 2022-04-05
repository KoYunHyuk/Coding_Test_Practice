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

		// 3���� ������ �������� '1�� �� ���� dp', '3���� ���� dp �� + 1' �� �ּڰ� ��
		if ((i % 3) == 0) dp[i] = min(dp[i], dp[i / 3] + 1);

		// 2�� ������ �������� '1�� �A ���� dp', '2�� ���� dp �� + 1' �� �ּڰ� ��
		if ((i % 2) == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N] << endl;

	return 0;
}