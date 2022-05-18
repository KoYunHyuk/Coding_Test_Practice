#include <iostream>
#include <vector>
#include <queue>


using namespace std; // S3

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	priority_queue<int> pq;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			pq.push(x);
		}
	}
}