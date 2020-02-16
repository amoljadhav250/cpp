#include <bits/stdc++.h>
using namespace std;


class LRU{
	int capacity;
	unordered_map<int,int> cache;
	list<int> lru;
	//set<int> s;
	public:
	LRU(int c){
		capacity=c;
	}
	void Set(int key, int value){
		if(cache.find(key)!=cache.end()){
			cache[key]=value;
			lru.remove(key);
			lru.push_back(key);
		}else{
			if(lru.size()==capacity){
				int f=lru.front();
				lru.pop_front();
				cache.erase(f);
				cache[key]=value;
				lru.push_back(key);
			}else{
			cache[key]=value;
			lru.push_back(key);				
			}
		}
	}
	
	int Get(int key){
		if(cache.find(key)!=cache.end()){
			lru.remove(key);
			lru.push_back(key);
			return cache[key];
		}else{
			return -1;
		}
	}
};

int main() {
	LRU Cache(2);
	Cache.Set(1,10);
	Cache.Set(5,12);
	cout<<Cache.Get(5)<<endl;
	cout<<Cache.Get(1)<<endl;
	cout<<Cache.Get(10)<<endl;
	Cache.Set(6,14);
	cout<<Cache.Get(5)<<endl;
	return 0;
}
