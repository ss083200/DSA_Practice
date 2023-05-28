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
			cout<<i<<" ";
//			printGraph(edges, visited, n, i);
		}
	}
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
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	printGraphDFS(edges, visited, n, 0);
	for(int i = 0; i < n; i++){
		delete[] edges[i];
	}
	delete[] edges;
	delete[] visited;
	return 0;
}

