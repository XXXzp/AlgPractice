#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

    ListNode* ReverseList(ListNode* pHead) {       
        ListNode *pre=NULL, *head=pHead, *next=pHead->next;
        while(head!=NULL){
            head->next = pre;
            pre = head;
            head = next;
            next = next->next;
        }
        return pre;
    }
