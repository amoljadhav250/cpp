#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string a="amolamol";
	int n=a.length();
	cout<<" n: "<<n<<endl;
	int l,r,i,k;
	l=0;r=0;
	int z[20];
	memset(z,0,sizeof(z));
	z[0]=n;
	for( i=1;i<n;i++){
	    
	    cout<<"Begin:  i:"<<i<<" l:"<<l<<" r:"<<r<<endl;
	    
	    if(i>r){
	        l=i;
	        r=i;
	        while(a[r-l]==a[r]){
	            r++;
	        }
	        z[i]=r-l;
	        r--;;
	    }
	    else{
	        k=i-l;
	        if(z[k]<r-i+1){
	            z[i]=z[k];
	        }
	        else{
	            l=i;
	            while(a[r-l]==a[r]){
	            r++;
	        }
	        z[i]=r-l;
	        r--;
	        }
	    }
	    
	    cout<<"End:  i:"<<i<<" l:"<<l<<" r:"<<r<<endl;
	    cout<<" z["<<i<<"]="<<z[i]<<endl;
	    
	}
	
	cout<<endl<<endl;
	
	for(int i=0;i<n;i++){
	    cout<<i<<" "<<z[i]<<" "<<endl;
	}
	
	
	return 0;
}
