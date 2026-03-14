// https://leetcode.com/problems/odd-even-linked-list/description/
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

ListNode* oddEvenList(ListNode* head) {
    ListNode* OddSentinal = new ListNode(0);
    ListNode* EvenSentinal = new ListNode(1);
    auto oddHead = OddSentinal;
    auto evenHead = EvenSentinal;

    int n = 1;
    while (head != nullptr) {
        if (n & 1) {
            oddHead->next = head;
            head = head->next;
            oddHead = oddHead->next;
            oddHead->next = nullptr;
        } else {
            evenHead->next = head;
            head = head->next;
            evenHead = evenHead->next;
            evenHead->next = nullptr;
        }
        n++;
    }

    evenHead = EvenSentinal->next;
    oddHead->next = evenHead;
    oddHead = OddSentinal->next;

    delete OddSentinal;
    delete EvenSentinal;

    return oddHead;
}

void solution() {
    ListNode* arr = Input();
    Debug(arr);

    Debug(oddEvenList(arr));

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