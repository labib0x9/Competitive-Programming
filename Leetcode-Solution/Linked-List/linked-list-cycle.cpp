//https://leetcode.com/problems/linked-list-cycle/
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

void linkCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* end_node = head;
    while (end_node->next != nullptr) end_node = end_node->next;

    int index = 0;
    ListNode* cur = head;
    while (cur->next != nullptr) {
        if (index == pos) {
            end_node->next = cur;
            return;
        }
        index++;
        cur = cur->next;
    }
}

bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode* slow_ptr = head;
    ListNode* fast_ptr = head;

    auto move_to_next_next = [&]() -> bool {
        if (fast_ptr->next != nullptr && fast_ptr->next->next != nullptr) {
            fast_ptr = fast_ptr->next->next;
            return true;
        }
        return false;
    };

    if (move_to_next_next() == false) return false;

    while (slow_ptr != fast_ptr) {
        if (slow_ptr == nullptr || fast_ptr == nullptr) return false;
        if (move_to_next_next() == false) return false;
        slow_ptr = slow_ptr->next;
    }

    return true;
}

void solution() {
    ListNode* arr = Input();

    // from description, join ending node to pos'th node..
    int pos;
    cin >> pos;
    linkCycle(arr, pos);

    // Debug(arr);

    // auto ans = deleteDuplicates(arr);

    // Debug(ans);

    cout << hasCycle(arr) << endl;

    // if (ans->next != nullptr) Delete(ans);
    // Delete(arr);

    // debug and delete not performed in this code because of cycle.
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