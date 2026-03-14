#include <bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'

template<typename T>
void PRINT(vector<T>& arr) {
    for (int i = 0; i < int(arr.size()); i++)
        cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Input() {
    int n;
    cin >> n;

    ListNode num1 = ListNode(-1);  // Sentinal Node
    ListNode* temp = &num1;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    return num1.next;
}

void Delete(ListNode* head) {
    while (head != nullptr) {
        auto temp = head;
        head = head->next;
        delete temp;
    }
}

void Debug(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void solution() {
    ListNode* num1 = Input();
    ListNode* num2 = Input();

    Debug(num1);
    Debug(num2);

    Delete(num1);
    Delete(num2);
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