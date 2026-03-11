// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

int removeDuplicates(vector<int>& nums) {
	int cnt = 1, n = nums.size();
	int x = nums[0];
	for (int i = 1; i < n; i++) {
		if (nums[i] == x) {
			continue;
		}
		x = nums[i];
		nums[cnt] = nums[i];
		cnt++;
	}
	return cnt;
}

void solution() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}

	cout << removeDuplicates(arr) << endl;
	PRINT(arr);

}

int32_t main() {

	// Test Case
	bool TEST_CASE = !true;

	ios::sync_with_stdio(false) ; cin.tie(0) ;

	int t_c = 1, tt_c = 1;
	if (TEST_CASE) cin >> t_c;

	// cin.ignore(); // In Case getline(cin, s)

	while (t_c--) {
		// cout << "Case " << tt_c++ << ": ";
		solution();
		// if (t_c) cout << '\n';
	}

	return 0;
}