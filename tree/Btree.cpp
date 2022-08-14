#include<iostream>

using namespace std;

typedef struct Node {
    int data;                                                // ->  data present at node
    struct Node *left, *right;                               // ->represent left pointer and right pointer
}Node;


//function to create new node 
struct Node* createNode(int data){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node)); 
    n->data  = data;
    n->left = n->right = NULL;

    return n;
}

//function to add Node in tree

void addNode(Node **n,int data){  // here double pointer represents address of pointer which will store the address
    if(*n == NULL){                // of root which is also a pointer  node this method is required to solve this problem recursively
        *n = createNode(data);
        
        return;
    }
    if(data > (*n)->data){                // *n represent data present at address n  which is address  of node 
                                          // and (*n)->data represents accessing  member of struct by pointer
                              
        addNode(&((*n)->right),data);    // here &((n*)->right) represent the address of right pointer of node
    }
    else{
         addNode(&((*n)->left),data);   // here &((n*)->left) represent the address of left pointer of node
    }
   
    
}

void inorderTraversal(Node *n){             // inorder traversasl of binary tree
    if(n == NULL)
        return;
 cout << n->data <<" ";                     // print value of current node

inorderTraversal(n->left);                  // perform inforder on left tree first
                     
inorderTraversal(n->right);                 // perform inorder on right tree

}
void preorderTraversal(Node *n){           // preorder traversal of binary tree
    if(n == NULL)
    return;

    preorderTraversal(n->left);             // perform preorder on left sub tree
    cout << n->data <<" ";                        //print value of node
    preorderTraversal(n->right);            //perform preorder on rigth sub tree
}

void postorderTraversal(Node *n){           // preorder traversal of binary tree
    if(n == NULL)
    return;

    postorderTraversal(n->left);             // perform preorder on left sub tree
                          
    postorderTraversal(n->right);           //perform preorder on rigth sub tree
    cout << n->data << " ";                        //print value of node      
}





int main(){

Node *root;
root = NULL;
addNode(&root,5);  // here we passing addres of root node 
addNode(&root,10);
addNode(&root,8);
addNode(&root,9);
addNode(&root,4);
addNode(&root,6);
addNode(&root,7);

addNode(&root,3);
addNode(&root,2);
addNode(&root,1);

inorderTraversal(root);
cout << endl;
preorderTraversal(root);
cout <<endl;
postorderTraversal(root);



}