// https://leetcode.com/problems/merge-k-sorted-lists/description/
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

// TC: O(n * k), MC: O(n)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* sentinalNode = new ListNode(1e5);
    ListNode* head = sentinalNode;
    int k = lists.size();

    while (1) {
        int minn = 1e5;
        int temp = -1;
        for (int i = 0; i < k; i++) {
            if (lists[i] == nullptr) continue;
            if (lists[i]->val <= minn) {
                temp = i;
                minn = lists[i]->val;
            }
        }

        if (temp == -1) break;

        head->next = new ListNode(minn);
        head = head->next;
        lists[temp] = lists[temp]->next;

        // cout << minn << endl;
    }

    head = sentinalNode->next;
    delete sentinalNode;
    return head;
}

void solution() {
    int n;
    cin >> n;

    vector<ListNode*> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = Input();
        Debug(arr[i]);
    }

    ListNode* ans = mergeKLists(arr);
    Debug(ans);

    if (ans != nullptr && ans->next != nullptr) Delete(ans);
    for (int i = 0; i < n; i++) {
        Delete(arr[i]);
    }
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