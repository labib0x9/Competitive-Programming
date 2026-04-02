// https://leetcode.com/problems/reverse-linked-list-ii/description/
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

// ListNode* reverseBetween(ListNode* head, int left, int right) {
// 	if (head == nullptr || head->next == nullptr || left == right) return head;

// 	ListNode sentinalNode = ListNode(0, head);
// 	ListNode* prev = nullptr;
// 	ListNode* tail = nullptr;
// 	ListNode* revTail = nullptr;
// 	ListNode* revHead = nullptr;

// 	for (int i = 1; head != nullptr; i++) {
// 		if (i == left) {
// 			revTail = head;
// 			tail = prev;
// 			tail->next = nullptr;
// 			prev = head;
// 			head = head->next;
// 		} else if (i == right) {
// 			revHead = head;
// 			auto next = head->next;
// 			head->next = prev;
// 			head = next;
// 			break;
// 		} else if (left <= i && i <= right) {
// 			auto next = head->next;
// 			head->next = prev;
// 			prev = head;
// 			head = next;
// 		} else {
// 			head = head->next;
// 			prev = prev->next;
// 		}
// 	}



// 	tail->next = revHead;
// 	revTail->next = head;

// 	return sentinalNode.next;
// }

ListNode* reverseBetween(ListNode* head, int left, int right) {
	if (head == nullptr || head->next == nullptr || left == right) return head;

	ListNode sentinalNode = ListNode(0, head);
	head = &sentinalNode;
	ListNode* prev = nullptr;
	ListNode* tail = nullptr;
	ListNode* revTail = nullptr;
	ListNode* revHead = nullptr;

	for (int i = 1; i < left; i++) {
		head = head->next;
	}

	tail = head;
	head = head->next;
	revTail = head;

	for (int i = left; i <= right; i++) {
		revHead = head;
		auto next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	tail->next = revHead;
	revTail->next = head;

	return sentinalNode.next;
}

void solution() {
	ListNode* arr = Input();
	int num1, num2;
	cin >> num1 >> num2;

	arr = reverseBetween(arr, num1, num2);
	Debug(arr);

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