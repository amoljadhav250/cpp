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

void printList(ListNode *head){
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}

ListNode *rotateList(ListNode *A, int B){
	ListNode *h=A;
	if(h==NULL){
		return h;
	}
	int n=0;
	ListNode *t=h;
	while(t!=NULL){
		n++;
		t=t->next;
	}
	int k=B%n;
	if(k==0){
		return h;
	}
	int p=n-k-1;
//	d(n);
//	d(p);
//	dn(k);
	t=h;
	ListNode *tn=t->next;
	while(p--){
		t=tn;
		tn=t->next;
	}
	t->next=NULL;
	t=h;
	h=tn;
//	cout<<"line 69 "<<t->data<<endl;
//	cout<<"line 70 "<<tn->data<<endl;
//	cout<<"line 71 "<<h->data<<endl;
//	printList(h);
//	printList(t);
	while(tn->next!=NULL){
		tn=tn->next;
	}
	tn->next=t;
	return h;
}

int main() {
	ListNode *h=newNode(1);
	h->next=newNode(3);
	appendList(&h,4);
	appendList(&h,5);
	appendList(&h,9);
	
	cout<<"Print List:-"<<endl;
	printList(h);
	
	h=rotateList(h,9);
	cout<<"Print List after rotating by 7:-"<<endl;
	printList(h);
	return 0;
}
