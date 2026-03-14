// https://leetcode.com/problems/palindrome-linked-list/description/
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

ListNode* slowAndPastPtr(ListNode* head) {
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    auto jump = [&]() ->bool {
        if (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
            fastPtr = fastPtr->next->next;
            return true;
        }
        return false;
    };

    while (jump()) {
        slowPtr = slowPtr->next;
    }

    auto temp = slowPtr->next;
    slowPtr->next = nullptr;
    slowPtr = temp;

    return slowPtr;
}

ListNode* reverse(ListNode* head) {
    auto prev = head;
    head = head->next;
    bool init = true;
    while (head != nullptr) {
        auto temp = head->next;
        head->next = prev;
        if (init) {
            prev->next = nullptr;
            init = false;
        }
        prev = head;
        head = temp;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;

    ListNode* middleNode = slowAndPastPtr(head);
    // Debug(head);
    // Debug(middleNode);
    ListNode* secondHead = reverse(middleNode);
    // Debug(secondHead);

    while (head != nullptr && secondHead != nullptr) {
        if (head->val != secondHead->val) return false;
        head = head->next;
        secondHead = secondHead->next;
    }
    return true;
}

void solution() {
    ListNode* arr = Input();
    Debug(arr);

    cout << isPalindrome(arr) << endl;

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