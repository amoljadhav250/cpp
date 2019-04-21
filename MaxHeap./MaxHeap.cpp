#include <iostream>
using namespace std;

class MaxHeap{
    int size;
    int *MH;
    int capacity;
    
public:
    int parent(int c){
        return (c-1)/2;
    }
    
    int getSize(){
        return this->size;
    }
    
    int left(int p){
        return 2*p+1;
    }
    
    int right(int p){
        return 2*p+2;
    }
    
    MaxHeap(int S){
        this->capacity=S;
        this->MH=new int[S];
        this->size=0;
    }
    
    void MaxHeapify(int i,int S){
        int largest=i;
        int r=right(i);
        int l=left(i);
        
        if(r<S && MH[r]>MH[i]){
            largest=r;
        }
        
        if(l<S && MH[l]>MH[largest]){
            largest=l;
        }
        
        if(largest!=i){
            int temp=MH[i];
            MH[i]=MH[largest];
            MH[largest]=temp;
            MaxHeapify(largest, S);
        }
    }
    
    void printHeap(){
        for(int i=0;i<this->size;i++){
            cout<<MH[i]<<"\n";
        }
        cout<<endl;
    } 

void insert(int k){
    if(this->size==this->capacity){
        cout<<"Can not insert, overflow occurs\n";
    }else{
        this->size++;
        MH[this->size-1]=k;
        int temp=this->size-1;
        while (parent(temp)>=0 && MH[parent(temp)]<MH[temp]){
            int t=MH[temp];
            MH[temp]=MH[parent(temp)];
            MH[parent(temp)]=t;
            temp=parent(temp);
        }
    }
} 

void HeapSort(){
   int n=this->size;
    for(int i=n-1;i>=0;i--){
        int t=MH[i];
        MH[i]=MH[0];
        MH[0]=t;
        MaxHeapify(0,i);
        
        //cout<<endl;
        //printHeap();
        //cout<<endl;
    }
}

void clear(){
    this->size=0;
    cout<<" MaxHeap cleared\n";
}
};



int main(){
    
    int t=0;
    int x;
    cin>>t;
     MaxHeap M(t+5);
    for(int i=0;i<t;i++){
        cin>>x;
        M.insert(x);
    }

    M.HeapSort();
    M.printHeap();

   /* M.insert(1);
    M.insert(2);
    M.insert(5);

    M.insert(4);
    M.printHeap();
    
    M.insert(8);
    M.insert(9);
    M.insert(10);

    M.insert(7);
    M.printHeap();
  
    
    M.HeapSort();
    M.printHeap();
    M.clear();
    
    M.insert(1);
    M.insert(2);
    M.insert(3);
    M.insert(4);
    M.insert(5);
    M.insert(6); 
    M.insert(7);
    M.insert(7);
    M.insert(8);
           
    M.printHeap();
    M.HeapSort();
    M.printHeap();
           
    M.insert(11);
    M.insert(121);
    M.insert(131);*/
    return 0;    
} 
