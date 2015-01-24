#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v = {5, 3, -1, -5};
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), [](int a, int b) {return abs(a) < abs(b); });

	return 0;
}
