// https://leetcode.com/problems/merge-two-sorted-lists/description/
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* sentinalNode = new ListNode(-1);
    ListNode* head = sentinalNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            head->next = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            head->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        head = head->next;
    }

    while (list1 != nullptr) {
        head->next = new ListNode(list1->val);
        list1 = list1->next;
        head = head->next;
    }

    while (list2 != nullptr) {
        head->next = new ListNode(list2->val);
        list2 = list2->next;
        head = head->next;
    }

    head = sentinalNode->next;
    delete sentinalNode;

    return head;
}

void solution() {
    ListNode* arr = Input();
    Debug(arr);

    ListNode* brr = Input();
    Debug(brr);

    ListNode* ans = mergeTwoLists(arr, brr);
    Debug(ans);

    if (ans != nullptr && ans->next != nullptr && ans != arr) Delete(ans);
    Delete(arr);
    Delete(brr);
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