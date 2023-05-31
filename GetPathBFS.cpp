#include<bits/stdc++.h>
using namespace std;

vector<int> getPathBFS(int** arr, int n, int sv, int ev, bool*visited)
{
	queue<int>q;
	visited[sv] = true;
	q.push(sv);
	//map of child to its parent
	unordered_map<int, int>m;
	
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		if(current == ev){
			break;
		}
		for(int i = 0; i < n; i++){
			if(current == i){
				continue;
			}
			if(arr[current][i] == 1 && !visited[i]){
				q.push(i);
				m[i] = current;
				visited[i] = true;
			}
		}
	}
	//To store the path
	vector<int>res;
	res.push_back(ev);
	int i = ev;
	while(i != sv){
		i = m[i];
		res.push_back(i);
	}
	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	int v, e;
	cout<<"Enter number of vertices and edges: ";
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	cout<<"Enter the edges: ";
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	cout<<"Enter starting and end vertex: ";
	int v1, v2;
	cin >> v1 >> v2;
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	vector<int>res = getPathBFS(arr, v, v1, v2, visited);
	for(int i = 0; i < res.size(); i++){
		cout<<res[i]<<" ";
	}
	for(int i = 0; i < v; i++){
	    delete[] arr[i];
	}
	delete[] arr;
	delete[] visited;
}
