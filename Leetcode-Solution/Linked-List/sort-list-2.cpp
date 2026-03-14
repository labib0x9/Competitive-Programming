// https://leetcode.com/problems/sort-list/description/
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

ListNode* getMiddle(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* slowPtr = head;
    ListNode* fastPtr = head->next;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    auto temp = slowPtr->next;
    slowPtr->next = nullptr;
    return temp;
}

ListNode* mergeSort(ListNode* head) {
    // cout << "DIV "; Debug(head);
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* middleNode = getMiddle(head);
    auto left = mergeSort(head);
    auto right = mergeSort(middleNode);

    // cout << "LEFT "; Debug(left);
    // cout << "RIGHT "; Debug(right);

    ListNode sentinalNode = ListNode(0);
    ListNode* tempHead = &sentinalNode;

    while (left != nullptr && right != nullptr) {
        if (left->val <= right->val) {
            tempHead->next = left;
            left = left->next;
        } else {
            tempHead->next = right;
            right = right->next;
        }
        tempHead = tempHead->next;
    }

    if (left != nullptr) {
        tempHead->next = left;
    }

    if (right != nullptr) {
        tempHead->next = right;
    }

    // cout << "CONQ "; Debug(tempHead);
    return sentinalNode.next;
}

ListNode* sortList(ListNode* head) {
    return mergeSort(head);
}

void solution() {
    ListNode* arr = Input();
    Debug(arr);

    Debug(sortList(arr));

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