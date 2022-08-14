#include<iostream>

using namespace std;

 typedef struct Heap{
    int *harr;
    int capacity;
    int size;
}Heap;

struct Heap * createHeap(int capacity){
    struct Heap *n = (struct Heap *)malloc(sizeof(struct Heap));
    n->capacity = capacity;
    n->harr = (int *)malloc(n->capacity* sizeof(int ));
    n->size = 0;
    return n;
}


void swap(int *num1 ,int *num2){
    int temp;
    temp = *num1;
    *num1  = *num2;
    *num2 = temp;
}

int parent(int i){return (i-1)/2;}                      // returns parrent element of index element

int leftChild(int i){return(i*2 + 1);}                  // returns leftChild of index element

int rightChild(int i){return (i*2 + 2);}                // returns rightchild of index element 


// function to insert element to heap 
void insertElement(struct Heap *h,int key){
    if(h->capacity == h->size){                         // if heap size is equal to heap capacity     
        cout << "overflow";                             // print ovelflow
        return;
    }

    h->size++;              //increase heap size
    int i = h->size -1;     // intilize i as heap size -1
    h->harr[i] = key;       // store key in heap at  array[i] 

    while(i != 0 && (h->harr[parent(i)]) > h->harr[i]){         //fix heap property after inserting an element
        swap(&(h->harr[parent(i)]), &(h->harr[i]));             // if haray[i] < harray[parent(i)] swap 
        i = parent(i);                                          // do this until 1st element of array is checked
    }
}

void print(struct Heap *h){

    for(int i = 0; i< h->size;i++)
    cout << h->harr[i]<< " ";
}

void heapify(struct Heap *h,int i){
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;

    if(l < h->size && h->harr[l] < h->harr[i])
    smallest = l;

    if(r < h->size && h->harr[r] < h->harr[smallest])
    smallest = r;

    if(smallest != i){
        swap(&(h->harr[smallest]),&(h->harr[i]));
        heapify(h,smallest);
    }
}


int main(){

    Heap *h;
    h = createHeap(10);
    int s;
    cin >> s;
    int key;
    for(int i = 0; i< s; i++){
        cin >> key;
        insertElement(h,key);

    }
    print(h);
}