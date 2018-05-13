#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *newList = NULL ;
        ListNode *newListBase = NULL;
        
        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val>pHead2->val){
                newList = pHead2;
                pHead2 = pHead2->next;
            }else{
                newList = pHead1;
                pHead1 = pHead1->next;
            }
            if(newListBase==NULL)
                newListBase = newList;
            newList = newList->next;
        }
        if(pHead1==NULL)
            newList = pHead2;
        else
            newList = pHead1;
        return newListBase;
    }
int main(){
    ListNode L1(1);
    ListNode L2(2);
    ListNode L3(3);
    ListNode L4(4);
    ListNode L5(5);
    ListNode L6(6);
    L1.next=&L3;
    L3.next = &L5;
    L2.next = &L4;
    L4.next = &L6;
    auto L = Merge(&L1,&L2);
    while(L!=NULL){
        cout<<L->val<<endl;
        L = L->next;
    }
    return 0;
}
