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

struct Node{
	int data;
	Node *next;
};

Node *newNode(int x){
	Node *node = new Node;
	node->data=x;
	node->next=NULL;
	return node;
}

void printList(Node *head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void appendList(Node **h,int data){
	if(*h==NULL){
		*h=newNode(data);
	}else{
		Node *t=*h;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=newNode(data);
	}
}

void removeDuplicatesSorted(Node *h){
	Node *t=h;
	if(h==NULL){
		return;
	}
	while(t->next!=NULL){
		if(t->data==t->next->data){
			Node *tnextnext=t->next->next;
			free(t->next);
			t->next=tnextnext;
		}else{
			t=t->next;
		}
	}
//	return h;
}

int main() {
	Node *h=newNode(1);
	h->next=newNode(1);
	appendList(&h,5);
	appendList(&h,5);
	appendList(&h,5);
	appendList(&h,7);
	appendList(&h,7);
	appendList(&h,8);
	cout<<"Print List:-\n";
	printList(h);
	removeDuplicatesSorted(h);
	cout<<"Print List:-\n";
	printList(h);
	return 0;
}
