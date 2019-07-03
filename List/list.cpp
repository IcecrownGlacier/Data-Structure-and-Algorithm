#include "list.h"


List::List()
{

}

ListNode* List::creat_list_node(int val)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newNode)
	{
		cout << "Out of memory" << endl;
		return NULL;
	}
	else
	{
		newNode->val = val;
		newNode->next = NULL;
		return newNode;
	}
}

void List::insert(ListNode *head, int val)
{
	ListNode *newNode = creat_list_node(val);
	ListNode *temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;
	//head->val++;

}

void List::print_list(ListNode *head)
{
	ListNode *temp = head;
	while (temp != NULL)
	{
		cout << temp->val << "-->";
		temp = temp->next;
	}
	cout << endl;
}

void List::reserver_with_head(ListNode *head)
{
	ListNode *firstNode = NULL;
	ListNode *curNode = NULL;

	firstNode = head->next;
	while (firstNode->next != NULL)
	{
		curNode = firstNode->next;
		firstNode->next = curNode->next;
		curNode->next = head->next;
		head->next = curNode;
	}
}

ListNode* List::reserver_without_head(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *pre = NULL;
	ListNode *cur = head;
	ListNode *newPre = NULL;
	ListNode *newCur = NULL;

	while (cur != NULL)
	{
		newPre = cur;
		newCur = cur->next;
		cur->next = pre;
		pre = newPre;
		cur = newCur;
	}

	return pre;

	/*
	if (head == NULL || head->next == NULL)
	return head;
	ListNode *firstNode = NULL;
	ListNode *curNode = NULL;

	firstNode = head->next;
	while (firstNode->next != NULL)
	{
	curNode = firstNode->next;
	firstNode->next = curNode->next;
	curNode->next = head->next;
	head->next = curNode;
	}
	ListNode *newHead = head->next;
	head->next = NULL;

	ListNode *temp = newHead;
	while (temp->next != NULL)
	temp = temp->next;
	temp->next = head;

	return newHead;
	*/
}

vector<int> List::print_list_from_tail_to_head(ListNode *head)
{
	vector<int> arraryList;
	if (head == NULL)
		return arraryList;

	ListNode *firstNode = NULL;
	ListNode *curNode = NULL;

	firstNode = head->next;
	while (firstNode->next != NULL)
	{
		curNode = firstNode->next;
		firstNode->next = curNode->next;
		curNode->next = head->next;
		head->next = curNode;
	}

	ListNode *temp = head->next;
	while (temp != NULL)
	{
		arraryList.push_back(temp->val);
		temp = temp->next;
	}
	arraryList.push_back(head->val);

	return arraryList;
}

ListNode* List::find_kth_to_tail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
		return NULL;
	auto pKthToHead = pListHead;
	for (int i = 0; i < k - 1; i++)
	{
		if (pKthToHead->next == NULL)
			return NULL;
		else
			pKthToHead = pKthToHead->next;
	}

	auto pKthToTail = pListHead;
	while (pKthToHead->next != NULL)
	{
		pKthToHead = pKthToHead->next;
		pKthToTail = pKthToTail->next;
	}

	return pKthToTail;
	/*
	if (pListHead == NULL || k == 0)
	return NULL;

	ListNode *pre = NULL;
	ListNode *cur = pListHead;
	ListNode *newPre = NULL;
	ListNode *newCur = NULL;

	int length = 0;
	while (cur != NULL)
	{
	newPre = cur;
	newCur = cur->next;
	cur->next = pre;
	pre = newPre;
	cur = newCur;

	length++;
	}

	if (k > length)
	return NULL;

	ListNode *kthToTail = NULL;
	cur = pre;
	newPre = NULL;
	newCur = NULL;

	for (int i = 0; i < k; i++)
	{
	newPre = cur;
	newCur = cur->next;
	cur->next = kthToTail;
	kthToTail = newPre;
	cur = newCur;
	}

	return kthToTail;
	*/
}

ListNode* List::merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	if (pHead1 == NULL && pHead2 == NULL)
		return NULL;

	ListNode* pMergeHead = NULL;
	if (pHead1->val > pHead2->val)
	{
		pMergeHead = pHead2;
		pHead2 = pHead2->next;
	}
	else
	{
		pMergeHead = pHead1;
		pHead1 = pHead1->next;
	}

	ListNode *temp = pMergeHead;

	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->val > pHead2->val)
		{
			temp->next = pHead2;
			temp = temp->next;
			pHead2 = pHead2->next;

		}
		else if (pHead1->val < pHead2->val)
		{
			temp->next = pHead1;
			temp = temp->next;
			pHead1 = pHead1->next;
		}
		else
		{
			temp->next = pHead1;
			temp = temp->next;
			pHead1 = pHead1->next;

			temp->next = pHead2;
			temp = temp->next;
			pHead2 = pHead2->next;
		}
	}
	if (pHead1 == NULL)
		temp->next = pHead2;
	else
		temp->next = pHead1;

	return pMergeHead;
}