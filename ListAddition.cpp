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
	 ListNode(int x) : val(x), next(NULL) {}
};

ListNode *newNode(int x){
	ListNode *node = new ListNode(x);
//	node->val=x;
//	node->next=NULL;
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

void pushList(ListNode **h,int data){
	if(*h==NULL){
		*h=newNode(data);
	}else{
		ListNode *t=newNode(data);
		t->next=*h;
		*h=t;
	//	return t;
	}
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

void printList(ListNode *head){
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}

int sizeList(ListNode *h){
	if(h==NULL){
		return 0;
	}else{
		return 1+sizeList(h->next);
	}
}

ListNode *addLists(ListNode *A, ListNode *B){
	
	if(A==NULL && B==NULL){
		return NULL;
	}
	

	int c=0;
	int d=0;
	ListNode *C=NULL;
	ListNode *ta=A;
	ListNode *tb=B;
	int taval;
	int tbval;
	while(ta!=NULL || tb!=NULL){
		
		if(ta!=NULL){
			taval=ta->val;
		}else{
			taval=0;
		}
		if(tb!=NULL){
			tbval=tb->val;
		}else{
			tbval=0;
		}
	//	cout<<"taval="<<taval<<" tbval="<<tbval<<endl;
		d=taval+tbval+c;
		c=d/10;
		d=d%10;
		ListNode *cn=new ListNode(d);
		pushList(&C,d);
		if(ta!=NULL){
			ta=ta->next;
		}
		if(tb!=NULL){
			tb=tb->next;
		}
		
	}
	if(c!=0){
		ListNode *cn=new ListNode(c);
		pushList(&C,c);
	}
	C=reverseList(C);
	return C;
}

int main() {
	ListNode *h=newNode(9);
//	appendList(&h,9);
//	appendList(&h,9);
//	appendList(&h,4);
//	appendList(&h,5);
	ListNode *h1=NULL;
	appendList(&h1,9);
	appendList(&h1,9);
	appendList(&h1,8);
	appendList(&h1,9);
//	appendList(&h1,9);
	
	cout<<"Print List:-"<<endl;
	printList(h);
	printList(h1);
	ListNode *h2=addLists(h,h1);
	printList(h2);
	return 0;
}
