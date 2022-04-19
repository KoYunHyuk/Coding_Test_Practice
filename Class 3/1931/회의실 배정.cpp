#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // S1

int N;

int main() {
	cin >> N;
	vector<pair<int, int>> time;

	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		time.push_back({ end, start });
	}
	sort(time.begin(), time.end());

	int count = 1;
	int temp = time[0].first;
	for (int i = 1; i < N; i++) {
		if (time[i].second >= temp) {
			count++;
			temp = time[i].first;
		}
	}
	cout << count;
}