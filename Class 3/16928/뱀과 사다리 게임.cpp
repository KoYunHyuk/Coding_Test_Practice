#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, M;
bool visited[101];
map<int, int> m;

int main() {
	cin >> N >> M;

	int u, v;
	for (int i = 0; i < N + M; i++) {
		cin >> u >> v;
		m[u] = v;
	}

	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == 100) {
			cout << cnt;
		}

		for (int i = 1; i <= 6; i++) {
			int xx = x + i;
			if (xx == 100) {
				cout << cnt + 1;
				return 0;
			}
			
			if (!m[xx]) {
				if (!visited[xx]) {
					visited[xx] = true;
					q.push({ xx, cnt + 1 });
				}
			}
			else {
				if (!visited[m[xx]]) {
					visited[m[xx]] = true;
					q.push({ m[xx], cnt + 1 });
				}
			}
		}
	}
}

