#include <bits/stdc++.h>
using namespace std;


struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
  
 
 
 void print(RandomListNode* A){
 	if(A==NULL){
 		return;
 	}
 	RandomListNode *t=A;
 	while(t!=NULL){
 		cout<<t->label<<" ";
 		if(t->random!=NULL){
 			cout<<t->random->label;
 		}
 		cout<<endl;
 		t=t->next;
 	}
 	cout<<endl;
 	return;
 }
 
 
 RandomListNode* copyRandomList(RandomListNode* A){
  	map<RandomListNode*, RandomListNode*> M;
  	RandomListNode *t=A;
  	RandomListNode *h=NULL;
  	while(t!=NULL){
  		M[t]=new RandomListNode(t->label);
  	//	M[t]->next=t->next;
  	//	M[t]->random=t->random;
  		t=t->next;
  	}
  	
  	t=A;
  	while(t!=NULL){
		M[t]->next=M[t->next];
		M[t]->random=M[t->random];
		t=t->next;
  	}
	return M[A];
  }
 
int main() {
	RandomListNode *a=new RandomListNode(1);
	RandomListNode *b=new RandomListNode(2);
	RandomListNode *c=new RandomListNode(3);
	a->next=b;
	b->next=c;
	a->random=c;
	b->random=a;
	c->random=a;
	print(a);
	RandomListNode *h=copyRandomList(a);
	cout<<"Printing h:\n";
	print(h);
	return 0;
}
