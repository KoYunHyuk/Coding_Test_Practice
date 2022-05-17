#include <iostream>
#include <vector>

using namespace std; // S3

long long Pn[101];

int main() {
	int test_case;
	cin >> test_case;
	Pn[1] = 1;
	Pn[2] = 1;
	Pn[3] = 1;
	Pn[4] = 2;
	Pn[5] = 2;
	for (int i = 6; i <= 100; i++) {
		Pn[i] = Pn[i - 1] + Pn[i - 5];
	}
	
	int N;
	while (test_case--) {
		cin >> N;

		cout << Pn[N] << "\n";
	}

	return 0;
}