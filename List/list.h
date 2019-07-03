#include <vector>
#include <iostream>

using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL){
	}
};

class List{
public:

	List();

	ListNode* creat_list_node(int val);

	void insert(ListNode* head, int val);

	void reserver_with_head(ListNode* head);

	ListNode* reserver_without_head(ListNode* head);

	void print_list(ListNode* head);

	vector<int> print_list_from_tail_to_head(ListNode* head);

	ListNode* find_kth_to_tail(ListNode * pListHead, unsigned int k);

	ListNode* merge(ListNode* pHead1, ListNode* pHead2);
};