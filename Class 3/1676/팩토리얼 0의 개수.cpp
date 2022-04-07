#include <iostream>
#include <vector>

using namespace std; // S4

int N;

int main() {
	cin >> N;

	int count = 0;
	for (int i = 2; i <= N; i++) {
		if (i % 5 == 0) count++;
		if (i % 25 == 0) count++;
		if (i % 125 == 0) count++;
	}
	cout << count;

	return 0;
}