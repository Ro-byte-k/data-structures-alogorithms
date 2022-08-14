#include<bits/stdc++.h>

using namespace std;

int g[10][10];

void dfs(int s,int v){
    bool visited[v];
    stack<int> stack;
    for(int i = 0; i< v; i++)
    visited[i] = false;
   
   stack.push(s);
   visited[s] = true;
   while ((!stack.empty()))
   {
    int top =  stack.top();
   
    cout << top << " ";
    stack.pop();
    for(int i = 0; i < v; i++){
      if(g[top][i] == 1 && !visited[i]){
        stack.push(i);
        visited[i] = true;
      }
    }
   }
  } 

  void bfs(int s,int v){

    bool visited[v];
    list<int> queue;
    for(int i  = 0; i < v; i++)
    visited[i] = false;

    queue.push_back(s);
    while(!queue.empty()){

      int n = queue.front();
      cout<< n <<" ";
      visited[n] = true;
      queue.pop_front();
      for(int i = 0; i < v; i++){
        if(g[n][i] == 1 && !visited[i] ){
          queue.push_back(i);
          visited[i] = true;
        }
      }
    }

  }

int main(){

int v,e;
cin >> v >> e;


for(int i = 0; i < v; i++ )
for(int j= 0; j < v; j++)
g[i][j] = 0;

int v1,v2;
 for(int i = 0; i < e;i++){
    cin >> v1 >> v2;
    g[v1][v2] = 1;
    g[v2][v1] = 1;
 }

 dfs(0,v);
 cout<< endl;
 bfs(0,v);

}