// https://leetcode.com/problems/remove-nodes-from-linked-list/description/
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

ListNode* reverse(ListNode* head) {
    if (head == nullptr) return head;
    auto prev = head;
    head = head->next;
    prev->next = nullptr;

    while (head != nullptr) {
        auto next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* removeNodes(ListNode* head) {
    head = reverse(head);
    int maxx = head->val;

    auto prev = head, temp = head;
    head = head->next;
    while (head != nullptr) {
        if (head->val < maxx) {
            head = head->next;
            continue;
        }
        maxx = head->val;
        prev->next = head;
        head = head->next;
        prev = prev->next;
    }
    prev->next = nullptr;

    return reverse(temp);
}

void solution() {
    ListNode* arr = Input();
    Debug(arr);

    Debug(removeNodes(arr));

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