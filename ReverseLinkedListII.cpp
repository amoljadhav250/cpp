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


ListNode *reverseList(ListNode *h, int B, int C){
	if(h==NULL){
		return NULL;
	}else if(h->next==NULL){
		return h;
	}
	else{
		ListNode *prev=NULL;
		ListNode *curr=h;
		ListNode *next=curr->next;
		
		for(int i=1;i<B && curr!=NULL;i++){
			next=curr->next;
			prev=curr;
			curr=next;
		}
		
		ListNode *beforestart=prev;
		ListNode *start=curr;
		
		int cal=C-B;
			for(int i=0;i<=cal && curr!=NULL;i++){//travel the loop
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			
		}
		if(B==1){
			h=prev;
			start->next=curr;
		}else{
			beforestart->next=prev;
			start->next=curr;
		}
		return h;
	}
}

int main() {
	ListNode *h=newNode(1);
	appendList(&h,2);
	appendList(&h,3);
	appendList(&h,4);
	appendList(&h,5);
	
	cout<<"Print List:-"<<endl;
	printList(h);
	
	for(int i=1;i<=5;i++){
		for(int j=i;j<=5;j++){
	h=reverseList(h,i,j);
	cout<<"Print List after reversing at i="<<i<<" j="<<j<<endl;
	printList(h);
		}
	}

	return 0;
}
