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


ListNode *reverseList(ListNode *h){
	if(h==NULL){
		return NULL;
	}else if(h->next==NULL){
		return h;
	}
	else{
		ListNode *prev=NULL;
		ListNode *curr=h;
		ListNode *next=curr->next;
		
		while(curr!=NULL){//travel the loop
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			
		}
	h=prev;
		return h;
	}
}

ListNode *reorderList(ListNode *A){
	ListNode *h=A;
	if(h==NULL || h->next==NULL){
		return h;
	}
	ListNode *slow=h;
	ListNode *fast=h;
	ListNode *prev=NULL;
	while(fast!=NULL && fast->next!=NULL){
		
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	ListNode *s=NULL;
	if(fast!=NULL){
		
		ListNode *p=slow->next;
		slow->next=NULL;
		s=reverseList(p);
	}else{
		prev->next=NULL;
		s=reverseList(slow);
	}
	
	ListNode *f=h;
	ListNode *fn=f->next;
	ListNode *sn=s->next;
	while(fn!=NULL && sn!=NULL){
//		cout<<"f="<<f->val<<" s="<<s->val<<" fn="<<fn->val<<" sn="<<sn->val<<endl;
		f->next=s;
		s->next=fn;
		f=fn;
		s=sn;
		fn=f->next;
		sn=s->next;
	}
		f->next=s;
		s->next=fn;
		f=fn;
		s=sn;
		fn=f->next;
		sn=s->next;
	return h;
	
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
//	appendList(&h,10);
	
	cout<<"Print List:-"<<endl;
	printList(h);
//	h=reverseList(h);
//	cout<<"Print List after reversing at i"<<endl;
//	printList(h);
	h=reorderList(h);
	cout<<"Print List after half reversing at i"<<endl;
	printList(h);
	return 0;
}
