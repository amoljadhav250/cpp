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

ListNode *swapNodes(ListNode *A){
	if(A==NULL || A->next==NULL){
		return A;
	}
	ListNode *t=A;
	ListNode *p=NULL;
	ListNode *s=A->next;
	ListNode *tnn=t->next->next;
	ListNode *tn=t->next;
	while(t!=NULL && t->next!=NULL){
	//	cout<<"t="<<t->val<<" tn="<<tn->val<<endl;
		tnn=t->next->next;
	//	if(tnn!=NULL){
	//		cout<<"tnn="<<tnn->val<<endl;
	//	}

		tn->next=t;
		t->next=tnn;
		if(p!=NULL){
			p->next=tn;
		}
		p=t;
		if(tnn!=NULL){
			t=tnn;
		}
		

	tn=t->next;
	}
	A=s;
	return A;
}

int main() {
	ListNode *h=newNode(1);
	
	ListNode *one=newNode(4);
	ListNode *two=newNode(5);
	ListNode *three=newNode(6);
	ListNode *four=newNode(7);
	
	h->next=newNode(2);
//	h->next->next=one;
//	one->next=two;
//	two->next=three;
//	three->next=four;
//	four->next=NULL;
//	appendList(&h,10);
//	appendList(&h,11);
	appendList(&h,12);
	cout<<"Print List:-"<<endl;
	printList(h);
	h=swapNodes(h);
	cout<<"Print List:-"<<endl;
	printList(h);
	return 0;
}
