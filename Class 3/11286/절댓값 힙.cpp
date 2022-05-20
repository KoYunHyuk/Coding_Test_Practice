#include <iostream>
#include <queue>

using namespace std; // S1

int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int x;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				if (pq.top().second == -1) {
					cout << -pq.top().first << "\n";
					pq.pop();
				}
				else {
					cout << pq.top().first << "\n";
					pq.pop();

				}
			}
		}
		else if (x > 0) {
			pq.push({ x, 1 });
		}
		else {
			pq.push({ -x, -1 });
		}
	}
}