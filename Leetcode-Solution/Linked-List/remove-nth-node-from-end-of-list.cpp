// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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

    ListNode* num1 = new ListNode(-1);  // Sentinal Node
    ListNode* temp = num1;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    temp = num1->next;
    delete num1;
    return temp;
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* sentinalNode = new ListNode(0, head);
    ListNode* slowPtr = sentinalNode;
    ListNode* fastPtr = sentinalNode;
    while (n-- && fastPtr != nullptr) {
        fastPtr = fastPtr->next;
    }

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }

    auto temp = slowPtr->next;
    if (temp != nullptr) temp = temp->next;
    slowPtr->next = temp;

    head = sentinalNode->next;
    delete sentinalNode;

    return head;
}

void solution() {
    ListNode* arr = Input();
    Debug(arr);

    int n;
    cin >> n;

    Debug(removeNthFromEnd(arr, n));

    Delete(arr);
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