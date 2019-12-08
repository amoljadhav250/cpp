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

Node  *removeDuplicatesSorted2(Node *head){
//	cout<<"in the function"<<endl;
	if(head==NULL){
		return head;
	}
//	cout<<"line 67"<<endl;
	Node *dummy=new Node;
	dummy->next=head;
	Node *prev=dummy;
	
	Node *current=head;
//	cout<<"line 73"<<endl;
	while(current!=NULL){
	//	cout<<"line 75"<<endl;
//		cout<<"current->data"<<current->data<<endl;
		while(current->next!=NULL && prev->next->data == current->next->data){
			current = current->next;
		}
		if(prev->next == current){
			prev=prev->next;
		}else{
			prev->next=current->next;
		}
		current=current->next;
	}
	return dummy->next;
}

int main() {
	Node *h=newNode(1);
	h->next=newNode(3);
	appendList(&h,5);
	appendList(&h,5);
	appendList(&h,5);
	appendList(&h,7);
	appendList(&h,7);
	appendList(&h,8);
	cout<<"Print List:-\n";
	printList(h);
	h=removeDuplicatesSorted2(h);
	cout<<"Print List:-\n";
	printList(h);
	return 0;
}
