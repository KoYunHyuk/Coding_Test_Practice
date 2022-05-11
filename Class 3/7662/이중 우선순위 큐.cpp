#include <iostream>
#include <set>
#include <queue>

using namespace std; // G4

int T, k;
string str;
bool visited[1000001];

int main() {
	char c;
	int n;

	cin >> T;
	while (T--) {
		cin >> k;

		// 1. max_heap, min_heap 이용
		priority_queue<pair<int, int>> max_heap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

		for (int i = 0; i < k; i++) {
			cin >> c >> n;
			if (c == 'I') {
				max_heap.push({ n, i });
				min_heap.push({ n, i });
				visited[i] = true;
			}
			else {
				if (n == 1) { 
					while (!max_heap.empty() && !visited[max_heap.top().second]) {
						max_heap.pop();
					}

					if (!max_heap.empty()) {
						visited[max_heap.top().second] = false;
						max_heap.pop();
					}
				}
				else {
					while (!min_heap.empty() && !visited[min_heap.top().second]) {
						min_heap.pop();
					}

					if (!min_heap.empty()) {
						visited[min_heap.top().second] = false;
						min_heap.pop();
					}
				}
			}
		}

		while (!max_heap.empty() && !visited[max_heap.top().second]) {
			max_heap.pop();
		}
		while (!min_heap.empty() && !visited[min_heap.top().second]) {
			min_heap.pop();
		}

		if (min_heap.empty() && max_heap.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << max_heap.top().first << " " << min_heap.top().first << "\n";
		}

		// 2. multiset 이용
		/*multiset<int> ms;

		while (k--) {
			cin >> c >> n;
			if (c == 'I') { // Insert
				ms.insert(n);
			}
			else { // Delete
				if (!ms.empty() && n == -1) { // 최소값 삭제
					ms.erase(ms.begin());
				}
				else if (!ms.empty() && n == 1) { // 최댓값 삭제
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto end_iter = ms.end();
			end_iter--;
			cout << *end_iter << " " << *ms.begin() << "\n";
		}*/
	}
}