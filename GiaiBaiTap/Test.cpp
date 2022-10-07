#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n,m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void inp(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

int BFS(int u){
	queue <int> q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x:adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x]=true;
				parent[x]=v;
			}
			else if(x!=parent[v]){
				return true;
			}
		}
	}
	return false;
}

int main(){
	inp();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			if(BFS(i)){
				cout<<"Yess";
				return 0;
			}
		}
	}
	cout<<"No";

	return 0;
}
