// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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

// 5
// 4 1 8 4 5
// 6
// 5 6 1 8 4 5
// 2 3
void linkInsertion(ListNode* headA, ListNode* headB, int skibA, int skibB) {
    ListNode* insertAt = headA;
    int index = 0;
    while (index < skibA) {
        index++;
        insertAt = insertAt->next;
    }

    // cout << insertAt->val << " " << index << "  " << skibA << endl;

    ListNode* mergeNode = headB;
    index = 0;
    while (index + 1 < skibB) {
        index++;
        mergeNode = mergeNode->next;
    }
    // cout << mergeNode->val << " " << index << "  " << skibB << endl;

    ListNode* temp = mergeNode->next;
    mergeNode->next = insertAt;

    mergeNode = temp;

    while (mergeNode != nullptr) {
        temp = mergeNode->next;
        delete mergeNode;
        mergeNode = temp;
    }
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int nullptrCount = 0;
    ListNode* tempHeadA = headA;
    ListNode* tempHeadB = headB;
    while (nullptrCount < 3 && headA != headB) {
        if (headA->next == nullptr) {
            nullptrCount++;
            headA = tempHeadB;
        } else {
            headA = headA->next;
        }

        if (headB->next == nullptr) {
            nullptrCount++;
            headB = tempHeadA;
        } else {
            headB = headB->next;
        }
    }

    return (headA == headB ? headA : nullptr);
}

void solution() {
    ListNode* arr = Input();
    ListNode* brr = Input();

    // from description,
    // There are skibA nodes before the intersected node in A;
    // There are skibB nodes before the intersected node in B.
    int skibA, skibB;
    cin >> skibA >> skibB;

    linkInsertion(arr, brr, skibA, skibB);

    Debug(arr);
    Debug(brr);


    cout << (getIntersectionNode(arr, brr) == nullptr ? -1 : getIntersectionNode(arr, brr)->val) << endl;

    // if (ans->next != nullptr) Delete(ans);
    // Delete(arr);
    // Delete(brr);
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