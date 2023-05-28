#include<bits/stdc++.h>
using namespace std;

void printGraphDFS(int **edges, bool *visited, int n, int starting_vertex){
	visited[starting_vertex] = true;
	cout<<starting_vertex<<" ";
	for(int i = 0; i < n; i++){
		if(starting_vertex == i){
			continue;
		}
		if(edges[starting_vertex][i] == 1){
			if(visited[i] == true){
				continue;
			}
			visited[i] = true;
			//cout will print the elements but not by DFS traversal
//			cout<<i<<" "; 
			printGraphDFS(edges, visited, n, i);
		}
	}
}
void DFS(int **edges, int n){
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		if(visited[i] == false){
			printGraphDFS(edges, visited, n, i);
		}
	}
	cout<<endl;
	delete[] visited;
}

void printGraphBFS(int **edges, bool *visited, int n, int starting_vertex)
{
	queue<int>pendingVertices;
	pendingVertices.push(starting_vertex);
	visited[starting_vertex] = true;
	
	while(!pendingVertices.empty())
	{
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		cout<<currentVertex<<" ";
		for(int i = 0; i < n; i++){
			if(i == starting_vertex)
				continue;
			if(edges[starting_vertex][i] == 1 && !visited[i]){
				pendingVertices.push(i);
				visited[i] = true;
			}
		}
	}
}
void BFS(int **edges, int n){
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		if(visited[i] == false){
			printGraphBFS(edges, visited, n, i);
		}
	}
	cout<<endl;
	delete[] visited;
}

int main()
{
	cout<<"enter the number of vertices: ";
	int n; //no of vertices
	cin>>n;
	int e; //no of edges
	cout<<"enter the number of edges: ";
	cin>>e;

	int **edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for(int j = 0; j < n; j++){
			edges[i][j] = 0;
		}
	}
	
	cout<<"enter edges in pairs, one by one: ";
	for(int i = 0; i < e; i++){
		int first, second; //edges stores as pair
		cin>>first;
		cin>>second;
		edges[first][second] = 1;
		edges[second][first] = 1;
	}
	DFS(edges, n);
	BFS(edges, n);
	for(int i = 0; i < n; i++){
		delete[] edges[i];
	}
	delete[] edges;
	return 0;
}


