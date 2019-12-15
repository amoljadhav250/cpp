#include<bits/stdc++.h>
#define LL long long int
#define sc(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define F first
#define S second
#define d(x) cout<<#x<<":"<<x<<"\t"
#define dn(x) cout<<#x<<":"<<x<<"\n"
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

ListNode *newNode(int x){
	ListNode *node = new ListNode;
	node->val=x;
	node->next=NULL;
	return node;
}

void printList(ListNode *head){
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}


void appendList(ListNode **h,int data){
	if(*h==NULL){
		*h=newNode(data);
	}else{
		ListNode *t=*h;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=newNode(data);
	}
}

ListNode *reverseNodes(ListNode *A, int B){
	if(A==NULL || A->next==NULL){
		return A;
	}
	ListNode *prev=NULL;
	ListNode *curr=A;
	ListNode *next=A->next;
	int i;
	for( i=1; curr!=NULL && i<=B ;i++){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
//	printList(prev);
//	if(prev!=NULL)cout<<"prev="<<prev->val<<endl;
//	if(curr!=NULL)cout<<"curr="<<curr->val<<endl;
//	if(next!=NULL)cout<<"next="<<next->val<<endl;
	if(i==B+1){
		A->next=reverseNodes(curr,B);
	}
	return prev;
}
int main() {
	ListNode *h=newNode(1);
	appendList(&h,2);
	appendList(&h,3);
	appendList(&h,4);
	appendList(&h,5);
	appendList(&h,6);
	appendList(&h,7);
	appendList(&h,8);
	appendList(&h,9);
	cout<<"Print List:-"<<endl;
	printList(h);
	h=reverseNodes(h,3);
	cout<<"Print List:-"<<endl;
	printList(h);
	return 0;
}
