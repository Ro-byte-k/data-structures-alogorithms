#include <bits/stdc++.h>
using namespace std;

vector<int> g[100];
bool visited[100];

void dfs(int vertex){

    visited[vertex] = true;
    cout << vertex <<"->";
    for(int child: g[vertex]){
        if(visited[child]) continue;;


        dfs(child);
    }
}


int main(){

    int n,m;
    cin >> n >> m;
    for(int i =0 ; i < m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(4);

}