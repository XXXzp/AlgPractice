#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p=pListHead, *q=pListHead;
        int i = 0;
        for (; p != NULL; i++) {
            if (i >= k)
                q = q->next;
            p = p->next;
        }
        return i < k ? NULL : q;
    }
int main(){
    return 0;
}