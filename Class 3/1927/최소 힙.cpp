#include <iostream>
#include <vector>
#include <queue>

using namespace std; // S2

int N, x;

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else{
				cout << 0 << "\n";
			}
		}
		else {
			pq.push(x);
		}
	}

}