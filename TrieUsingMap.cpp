#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
	map<char, TrieNode*> m;
	bool isEnd;
};

TrieNode *getTrieNode(){
	TrieNode* node = new TrieNode;
	node->isEnd=false;
	return node;
}

void insert(TrieNode* root, string s){
	char c;
	TrieNode* t=root;
	for(int i=0;i<s.length();i++){
		c=s[i];
		if(t->m[c]==NULL){
			t->m[c]=getTrieNode();
		}
		t=t->m[c];
	}
	t->isEnd=true;
}

int search(TrieNode *root, string s){
	char c;
	TrieNode *t=root;
	for(int i=0;i<s.length();i++){
		c=s[i];
		if(t->m[c]==NULL){
			return 0;
		}
		t=t->m[c];
	}
	if(t!=NULL && t->isEnd==true){
		return 1;
	}
	return 0;
}


int main() {
	TrieNode *root=getTrieNode();
	insert(root,"amol");
	cout<<search(root,"amol")<<endl;
	cout<<search(root,"the")<<endl;
	insert(root,"there");
	cout<<search(root,"amol")<<endl;
	cout<<search(root,"the")<<endl;
	insert(root,"the");
	cout<<search(root,"amol")<<endl;
	cout<<search(root,"the")<<endl;
	cout<<search(root,"ther")<<endl;
	cout<<search(root,"there")<<endl;
	return 0;
}
