#include <iostream>
#include <vector>
#include <queue>

using namespace std; // S1

int N, K;
bool visit[100001];

int main() {
	cin >> N >> K;

	// BFS
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visit[N] = true;

	while (!q.empty()) {
		int posi = q.front().first;
		int count = q.front().second;
		q.pop();

		if (posi == K) {
			cout << count;
			break;
		}

		if (posi + 1 < 100001 && !visit[posi + 1]) {
			q.push({ posi + 1, count + 1 });
			visit[posi + 1] = true;
		}
		if (posi * 2 < 100001 && !visit[posi * 2]) {
			q.push({ posi * 2, count + 1 });
			visit[posi * 2] = true;
		}
		if (posi - 1 >= 0 && !visit[posi - 1]) {
			q.push({ posi - 1, count + 1 });
			visit[posi - 1] = true;
		}
	}

	return 0;
}