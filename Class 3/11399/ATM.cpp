#include <iostream>
#include <queue>
#include <algorithm>

using namespace std; // S3

int N, result;
vector<int> Pn;

int main() {
	cin >> N;

	priority_queue<int> pq;
	
	int p;
	for (int i = 0; i < N; i++) {
		cin >> p;
		Pn.push_back(p);
	}
	sort(Pn.begin(), Pn.end());

	result += Pn[0];
	for (int i = 1; i < N; i++) {
		Pn[i] = Pn[i - 1] + Pn[i];
		result += Pn[i];
	}

	cout << result;
}