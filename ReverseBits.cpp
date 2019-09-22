#include <iostream>
using namespace std;

unsigned int reverseBits(unsigned int A){
	unsigned int a=A;
	unsigned int t=0;
	for(int i=0;i<32;i++){
		int j=31-i;
		if(a & (1<<i)){
			t=t|(1<<j);
		}
	}
	
	return t;
}

void printBinary(unsigned int a){
	cout<<" ";
	for(int i=31;i>=0;i--){
		if(a & (1<<i)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
}

int main() {

	printBinary(4294967295);cout<<endl;
	printBinary(reverseBits(4294967295));cout<<endl;
	cout<<reverseBits(4294967295)<<endl;
	
		printBinary(7);cout<<endl;
	printBinary(reverseBits(7));cout<<endl;
	cout<<reverseBits(7)<<endl;
	return 0;
}
