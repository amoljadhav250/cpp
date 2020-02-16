#include <bits/stdc++.h>
#include <chrono>
using namespace std; 
using namespace std::chrono;

void fun(){
	unordered_map<int,int> m;
	srand(time(0));
	for(int i=0;i<1000007;i++){
		m.insert(make_pair(rand()%1000001,rand()%1000001));
	}
}

int main() {
	auto start=chrono::high_resolution_clock::now();
	fun();
	auto end=chrono::high_resolution_clock::now();
	auto diff=chrono::duration_cast<microseconds>(end-start);
	cout<<diff.count()<<endl;
	return 0;
}
