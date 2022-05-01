#include <iostream>
#include <vector>

using namespace std; // S1

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int k;
	cin >> k;

	int M, N, x, y;
	for (int i = 0; i < k; i++) {
		cin >> M >> N >> x >> y;

		int limit = lcm(M, N);
		int j;
		for (j = x; j <= limit; j += M) {
			int temp = (j%N == 0) ? N : j % N;
			if (temp == y) {
				cout << j << "\n";
				break;
			}
		}
		if (j > limit) cout << "-1\n";
	}
	return 0;
}