#include <iostream>

using namespace std;

int N, M;
int num[100001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;

	cin >> num[1];
	for (int i = 2; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}	

	int i, j;
	while(M--) {
		cin >> i >> j;

		cout << num[j] - num[i-1] << "\n";
	}
}