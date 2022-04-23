#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // S3

int N;
int stair[301];
int dp[301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) { // 끝 계단은 무조건 밟아야 하므로 끝 계단부터 시작
		cin >> stair[i];
	}
	
	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << dp[N];
}