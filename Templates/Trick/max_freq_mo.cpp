int maxx_freq = 0;	// Maximum frequency in the range
vector<int> mp(N + 1, 0);	// mp[v] = occurrences of value v in current range
vector<int> cnt(N + N + 10, 0); // cnt[v] = number of values occurring v time.

// how many value occurs k time ? cnt[k + n] ???

// change here
auto add = [&](int idx) {
	if (idx == -1) return;
	int freq = mp[arr[idx]];
	cnt[freq + n]--;
	mp[arr[idx]]++;

	freq++;

	cnt[freq + n]++;
	if (maxx_freq < freq)
		maxx_freq++;
};

// change here
auto remove = [&](int idx) {
	if (idx == -1) return;
	int freq = mp[arr[idx]];
	cnt[freq + n]--;
	mp[arr[idx]]--;

	freq--;

	cnt[freq + n]++;
	if (cnt[maxx_freq + n] == 0)
		maxx_freq--;
};
