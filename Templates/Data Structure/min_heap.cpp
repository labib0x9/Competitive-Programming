auto cmp = [](int a, int b) {
    return a > b;
};
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);