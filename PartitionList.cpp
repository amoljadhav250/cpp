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
ListNode *addLess(ListNode *h, int x){
	if(h==NULL){
		return h;
	}
	if(h->val<x){
		ListNode *n=newNode(h->val);
		n->next=addLess(h->next,x);
		return n;
	}else{
		return addLess(h->next,x);
	}
}



ListNode *addGreater(ListNode *h, int x){
	if(h==NULL){
		return h;
	}
	if(h->val>x){
		ListNode *n=newNode(h->val);
		n->next=addGreater(h->next,x);
		return n;
	}else{
		return addGreater(h->next,x);
	}
}

int countNodes(ListNode *h, int x){
	int count=0;
	while(h){
		if(h->val==x){
			count++;
		}
		h=h->next;
	}
	return count;
}

ListNode *partiton(ListNode *A, int B){
	ListNode *h1=addLess(A,B);
	ListNode *h2=addGreater(A,B);
	ListNode *h=NULL;
	ListNode *start;
	if(h1!=NULL){
		start=h1;
		h=h1;
		while(h->next){
		h=h->next;
		}
	}

	int count=countNodes(A,B);
	for(int i=1;i<=count;i++){
		if(h==NULL){
			h=newNode(B);
			start=h;
		}else{
			h->next=newNode(B);
		h=h->next;
		}
		
	}
	if(h==NULL){
		h=h2;
		start=h;
	}else{
		h->next=h2;	
	}
	return start;
}
int main() {
	ListNode *h=NULL;newNode(1);
	appendList(&h,8);
	appendList(&h,6);
	appendList(&h,4);
	appendList(&h,10);
	appendList(&h,4);
	appendList(&h,10);
	appendList(&h,3);
	appendList(&h,7);
	cout<<"Print List:-"<<endl;
	printList(h);
	ListNode *hp=partiton(h,1);
	cout<<"Print After partitioning at 7:-"<<endl;
	printList(hp);
	return 0;
}
