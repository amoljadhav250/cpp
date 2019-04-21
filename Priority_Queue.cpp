#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int> > > Q;
    Q.push(make_pair(1,4));
    Q.push(make_pair(5,3));
    Q.push(make_pair(11,2));
    Q.push(make_pair(8,7));
    Q.push(make_pair(5,6));
    
    while(Q.empty()==false){
        pair<int,int> K=Q.top();
        cout<<K.first<<" "<<K.second<<endl;
        Q.pop();
    }
    return 0;
}
