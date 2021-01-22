#include <iostream>
#include <list>
#include <stack>
using namespace std;

class graph {
	int V;
	list<int> *adj;
	list<int> *routs;

public:
	graph(int V);
	void addEdge(int vertex1, int vertex2);
    bool DFS(int vertex, int CD, int X);
	bool hasCycle(int CD, int X);
};

graph::graph(int V){
	this->V = V;
	adj = new list<int>[V];
	routs = new list<int>;
}

void graph::addEdge(int vertex1, int vertex2){
	adj[vertex1].push_back(vertex2);
}

bool graph::DFS(int vertex, int CD, int X){
	int R = (-60-(-90))/X;
	int cont = 0;

	if (cont == R){
		cout << "*\n";
		return false;
	}

	stack<int> pilha;
	bool visitados[V], pilha_rec[V];
	bool cycle = false;
	bool flag = false;

	// inicializa visitados e pilha_rec com false
	for (int i = 0; i < V; i++)
		visitados[i] = pilha_rec[i] = false;

	// faz uma DFS
	while (true){
		bool achou_vizinho = false;
		list<int>::iterator it;

		if (!visitados[vertex]){
			pilha.push(vertex);
			visitados[vertex] = pilha_rec[vertex] = true;
			routs->push_back(vertex);
			cout << vertex << endl;
		}

		if (cont == R+1){
			break;
		}
		cont++;

		for (it = adj[vertex].begin(); it != adj[vertex].end(); it++){
			// se o vizinho já está na pilha é porque existe ciclo
			if (pilha_rec[*it]){
				cycle = true;
				break;
			} else if (!visitados[*it]){
				// se não está na pilha e não foi visitado, indica que achou
				achou_vizinho = true;
				break;
			}
		}

		if (!achou_vizinho){
			pilha_rec[pilha.top()] = false; // marca que saiu da pilha
			pilha.pop(); // remove da pilha
			if (pilha.empty()){
				break;
			}
			vertex = pilha.top();
		} else {
			vertex = *it;
		}
	}

/*
	for (int i = CD; i < V; i++){
		if (visitados[i]){
			flag = true;
		}
	}

	for (int i = CD; i < V; i++){
		if (visitados[i] && flag){
			cont++;

			if (cont == R){
				if (cycle){
					return true;
				}
				else
					return false;
			}
		}
		*/
	if (cycle)
		return true;
	else
		return false;
}

bool graph::hasCycle(int CD, int X){
	bool flag = false;

	for (int i = 0; i < CD; i++){
		if (DFS(i, CD, X)){
			flag = true;
		}
	}

	routs->sort();

	list<int>::iterator it;
	for (it = routs->begin(); it != routs->end(); it++)
		cout << *it << " ";
	cout << endl;

	if (flag)
		return true;
	else
		return false;
}
