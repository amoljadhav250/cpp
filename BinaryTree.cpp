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
	Node *left, * right;
};

Node *newNode(int data){
	Node *node=new Node;
	node->data = data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void preOrder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<"\n";
	preOrder(root->left);
	preOrder(root->right);
}

void leftView(Node *root,int *level,int nlevel){
	if(root==NULL){
		return;
	}
	if(*level<nlevel){
		*level=nlevel;
		cout<<root->data<<endl;
	}
	leftView(root->left,level,nlevel+1);
	leftView(root->right,level,nlevel+1);
}

void rightView(Node *root,int *level,int nlevel){
	if(root==NULL){
		return;
	}
	if(*level<nlevel){
		*level=nlevel;
		cout<<root->data<<endl;
	}
	rightView(root->right,level,nlevel+1);
	rightView(root->left,level,nlevel+1);
}

int main() {
	Node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->right->right=newNode(5);
	root->right->right->right=newNode(6);
	root->left->left->left=newNode(7);
	root->left->left->left->left=newNode(8);
	preOrder(root);cout<<"\n";
	cout<<"Left View:-\n";
	int left=0;
	leftView(root,&left,1);
	cout<<"Right View:-\n";
	int right=0;
	rightView(root,&right,1);
	return 0;
}
