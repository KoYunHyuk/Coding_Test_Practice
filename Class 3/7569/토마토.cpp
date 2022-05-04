#include <iostream>
#include <vector>
#include <queue>

using namespace std; // G5

int M, N, H;
int dist[101][101][101];
int dx[6] = { 0,0,0 ,0,-1,1 };
int dy[6] = { 0,0 ,1,-1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };
int result = 0;

int main() {
	cin >> M >> N >> H;
	queue<vector<int>> q;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> dist[i][j][k];

				if (dist[i][j][k] == 1) q.push({ i, j, k });
			}
		}
	}

	while (!q.empty()) {
		vector<int> cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int zz = cur[0] + dz[i];
			int xx = cur[1] + dx[i];
			int yy = cur[2] + dy[i];

			if (zz < 0 || zz >= H || xx < 0 || xx >= N || yy < 0 || yy >= M) continue;

			if (dist[zz][xx][yy] == 0) {
				dist[zz][xx][yy] = dist[cur[0]][cur[1]][cur[2]] + 1;
				q.push({ zz, xx, yy });
			}
		}
	}


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (dist[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				result = max(result, dist[i][j][k]);
			}
		}
	}
	cout << result - 1;
}