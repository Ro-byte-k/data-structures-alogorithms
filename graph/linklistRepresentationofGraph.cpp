#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//graph representaion using adjencecey list representaion..


struct Node{                        //  struct node representin node in graph
    int dest;                       // int dest stores destination 
    struct Node * next;             // store the address of next element 
};

struct AdjacyList {

    struct Node  *head;             // adjacency list list represent the edges in graph
};                                  // 0->1->2->4           0 has edge with 1 , 2,  4
                                    // 1->3->2->4->0        1 has edge with 3, 2, 4, 0


struct Graph{                      
                                    
    int V;                        // graph sotre V vertices
    struct AdjacyList *array;     // AND adjacency list array 
    bool *visited;                // visited array which represent if node is visted or not
};

struct Node * newNode(int dest){   // create new Node function

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->dest = dest;
    n->next = NULL;
    return n;

}

struct Graph * createGraph(int V){
    struct Graph *g = (struct Graph *) malloc(sizeof(struct Graph));
    g->V = V;
    g->visited = (bool *) malloc(V *sizeof(bool));

    g->array = (struct AdjacyList*) malloc(V *sizeof(struct AdjacyList));    // build array of adjacy list struct

    for(int i = 0; i < V; i ++) {               // make head null of all list
    g->array[i].head = NULL;
    g->visited[i] = false;
    }

    return g;
}

void addEdge(struct Graph *g,int src,int dest){  // add edge to graph

struct Node *check  = NULL;
struct Node *n = newNode(dest);

if(g->array[src].head == NULL){
    n->next =   g->array[src].head ;
    g->array[src].head  = n;

}
else{
    check = g->array[src].head;
    while(check->next != NULL){
        check = check->next;
    }
    check->next = n;
}
struct Node *n2 = newNode(src);
if(g->array[dest].head == NULL){
    n->next =   g->array[dest].head ;
    g->array[dest].head  = n2;
}
else{
    check = g->array[dest].head;
    while(check->next != NULL){
        check = check->next;
    }
    check->next = n2;
    }
}


void printGraph(struct Graph *g){

    for(int i = 0; i < g->V; i++){
        struct Node *p = g->array[i].head;
        cout << "Adejecy list of vetex " << i ;
        while(p != NULL){
            cout << "->"<<p->dest;
            p = p->next;
        }
        cout << endl;
    }
}

void resetVissited(struct Graph *g){
    for(int i = 0; i < g->V; i++)
        g->visited[i] = 0;
}

void dfs(struct Graph *g,int vertx){

//   this is deapth first search algorith implemented
//   using link list representation of Graph
//   heare we created recursively call the dfs function for 
//   unvisited node in graph  
if(g->visited[vertx] == true)               // if 
return;
     g->visited[vertx] = true;              // markk node as visited
    struct Node *t = g->array[vertx].head;
    while(t != NULL){  
        if(g->visited[t->dest]){
             t = t->next;                   // if node visited skip this node f
              continue;
              }
         dfs(g,t->dest);                     // call dfs for every node which is not visisted
         t = t->next;       
         }
          cout << vertx << " ";             //print vertx
}

void bfs(struct Graph *g,int vertx){
     
    // this is breadth first algorithm on link list 
    // representation of graph 
    // in this algorithm we uses queue to perform breadth first 
    // on graph
     
    list<int> queue;
     g->visited[vertx] = true;              // mark as visited source node
     queue.push_back(vertx);                // push source node in queue
     int n;
      struct Node *t; 
      while(!queue.empty()){                // while queue is not empty
        n = queue.front();                  // poget element form queue and store in n
        t =  g->array[n].head;  
        cout << n << " ";
        queue.pop_front();                  // pop element form queue
        while(t != NULL){   
            if(g->visited[t->dest]){       // if element is visted skip
                t = t->next;
                continue;
            }
            queue.push_back(t->dest);      // if element is not visited  push element in queue
            g->visited[t->dest] = true;     // mark as visited
            t = t->next;                    
        }
    }
         
}





int main(){
        int v =10;
        struct Graph *g = createGraph(v);


        addEdge(g,0,1);
        addEdge(g,2,3);
        addEdge(g,4,3);
        addEdge(g,1,4);
        addEdge(g,1,3);
        addEdge(g,1,7);
        addEdge(g,7,3);
        addEdge(g,9,2);
        addEdge(g,6,5);
        addEdge(g,8,4);
        addEdge(g,5,3);
 
        printGraph(g);
        dfs(g,0);
        cout << endl;
        resetVissited(g);
        bfs(g,0);
return 0;

}