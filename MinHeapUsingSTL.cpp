#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int,vector<int>, greater<int> > pq;
	pq.push(2);
	pq.push(3);
	pq.push(1);
	pq.push(5);
	pq.push(4);
	cout<<pq.size()<<" ";
	while(pq.empty()==false){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}
