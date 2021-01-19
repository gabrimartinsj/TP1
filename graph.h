#include <iostream>
#include <list>
#include <algorithm>
#include <stack>
using namespace std;

class graph{
	int V;
	list<int> *adj;

public:
	graph(int V);
	void addEdge(int vertex1, int vertex2);
	bool isAdjacent(int vertex1, int vertex2);
    bool dfs(int vertex);
    int order(int vertex);
};

graph::graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void graph::addEdge(int vertex1, int vertex2){
	adj[vertex1].push_back(vertex2);
}

bool graph::isAdjacent(int vertex1, int vertex2){
	if(find(adj[vertex1].begin(), adj[vertex1].end(), vertex2) != adj[vertex1].end())
		return true;
	return false;
}

int graph::order(int vertex){
	return adj[vertex].size();
}

bool graph::dfs(int vertex)
{
	stack<int> pilha;
	bool visitados[V], pilha_rec[V];

	// inicializa visitados e pilha_rec com false
	for(int i = 0; i < V; i++)
		visitados[i] = pilha_rec[i] = false;

	// faz uma DFS
	while(true)
	{
		bool achou_vizinho = false;
		list<int>::iterator it;

		if(!visitados[vertex])
		{
			pilha.push(vertex);
			visitados[vertex] = pilha_rec[vertex] = true;
		}

		for(it = adj[vertex].begin(); it != adj[vertex].end(); it++)
		{
			// se o vizinho já está na pilha é porque existe ciclo
			if(pilha_rec[*it])
				return true;
			else if(!visitados[*it])
			{
				// se não está na pilha e não foi visitado, indica que achou
				achou_vizinho = true;
				break;
			}
		}

		if(!achou_vizinho)
		{
			pilha_rec[pilha.top()] = false; // marca que saiu da pilha
			pilha.pop(); // remove da pilha
			if(pilha.empty())
				break;
			vertex = pilha.top();
		}
		else
			vertex = *it;
	}

	return false;
}
