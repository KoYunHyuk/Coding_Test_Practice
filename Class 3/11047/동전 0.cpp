#include <iostream>
#include <vector>
#include <cstring>

using namespace std; // S3

int N, K, result;
int coin[10];

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (K == 0) break;
		if (coin[i] > K) continue;
		
		int mok = K / coin[i];
		result += mok;
		K -= mok * coin[i];
	}

	cout << result;
}