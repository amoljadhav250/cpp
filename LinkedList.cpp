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

void reverseList(Node **h){
	if(*h==NULL){
		return;
	}
	if((*h)->next == NULL){
		return;
	}
	Node *prev=NULL;
	Node *curr=*h;
	Node *next=curr->next;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*h=prev;
}

bool compareList(Node *a, Node *b){
	if(a==NULL && b==NULL){
		return true;
	}
else if(a==NULL && b!=NULL){
		return false;
	}else if (b==NULL && a!=NULL){
		return false;
	}	else if(a->data==b->data && compareList(a->next,b->next)){
		return true;
	}else{
		return false;
	}
	return false;
}

bool isPalindrome(Node *h){
	if(h==NULL){
		return true;
	}
	if(h->next==NULL){
		return true;
	}
//	return false;
//	cout<<"Line 126\n";
	Node *fast=h;
	Node *slow=h;
	Node *mid=NULL;
	Node *prev=NULL;
//	cout<<"Line 133\n";
	
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		prev=slow;
		slow=slow->next;
	}
//	cout<<"Line 137\n";
	
	if(fast!=NULL){
		mid=slow;
		slow=slow->next;
	}
	prev->next=NULL;
//	cout<<"Line 142\n";
	
	reverseList(&slow);
//	cout<<"Line 144\n";
	//return false;
	printList(h);
	printList(slow);
	bool flag=compareList(h,slow);
//	cout<<"Line 153\n";
//	return false;
	reverseList(&slow);
	if(mid){
		prev->next=mid;
		mid->next=slow;
	}else{
		prev->next=slow;
	}
	
	if(flag){
		return true;
	}
	else{
		return false;
	}
}
Node *mergeLists(Node *a, Node *b){
	Node *root=new Node;
	if(a==NULL && b==NULL){
		root=NULL;
	//	return root;
	}else if(a!=NULL && b==NULL){
		root=a;
	//	return root;
	}else if(b!=NULL && a==NULL){
		root=b;
	//	return root;
	}else if(a->data<=b->data){
		cout<<"adata="<<a->data<<endl;
		root->data=a->data;
		root->next=mergeLists(a->next,b);
	//	return root;
	}else{
		cout<<"bdata="<<b->data<<endl;
		root->data=b->data;
		root->next=mergeLists(a,b->next);
		//return root;
	}
	return root;
}

int main() {
	Node *h=newNode(1);
	h->next=newNode(3);
	appendList(&h,4);
	appendList(&h,5);
	appendList(&h,9);
	
	Node *h1=newNode(2);
	h1->next=newNode(3);
	appendList(&h1,6);
	appendList(&h1,7);
	appendList(&h1,9);

	cout<<"Print List:-\n";
	printList(h);
	printList(h1);
	Node *h2=mergeLists(h,h1);
	printList(h2);
	return 0;
}
