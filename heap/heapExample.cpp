#include<iostream>
using namespace std;


int swap(int *num1, int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int leftChild(int i){
    return(i*2 +1);
    
}

int rightChild(int i){
    return (i*2 + 2);
}

void hipify(int a[],int n,int i){

    int l = leftChild(i);
    int r = rightChild(i);

    int smallest = i;

    if(l < n && a[l] < a[smallest])
    smallest = l;

    if(r < n && a[r] < a[smallest])
    smallest = r;

    if(smallest != i){
        swap(&a[smallest],&a[i]);
        hipify(a,n,smallest);
        
    }
}

void buildHeap(int a[], int n){

    int startIndex = (n/2) -1;


    for(int i = startIndex; i >= 0; i--)
        hipify(a,n,i);
}

void heapSort(int a[],int n){

    buildHeap(a,n);
   

    for(int i = n-1; i > 0; i--){
         swap(&a[0],&a[i]);
           hipify(a,i,0);
}
    }
  


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0; i < n; i++)
    cin >> a[i];

   heapSort(a,n);

    for(int i =0; i< n; i++)
    cout << a[i] <<" ";

    return 0;
}