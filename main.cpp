#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "graph.h"
using namespace std;

int calculateMaxPVs(int temperatura){
    return (-60-(-90))/temperatura;
}

int main(){
    int CD, PV, X;

    cin >> CD >> PV >> X;
    cin.ignore();

    for(int i = 0; i < CD; i++){
        int CDline;
        string input;

        getline(cin, input);
        istringstream stream(input);

        while(stream >> CDline){
            //graph.addEdge(i, CDline);
            cout << CDline << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < PV; i++){
        int PVline;
        string input;

        getline(cin, input);
        istringstream stream(input);

        while(stream >> PVline){
            //graph.addEdge(i, PVline);
            cout << PVline << " ";
        }
        cout << endl;
    }

    int maxPVs = calculateMaxPVs(X);
    cout<< maxPVs<< "\n";

    graph.DFS2(0, maxPVs, CD-1); 

    /*
    // criando um grafo de 4 vértices
	graph graph(4);
	// adicionando as arestas
	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 2);
	graph.addEdge(3, 1);
	graph.addEdge(3, 2);
	// mostrando os graus de saída
	cout << "Grau de saida do vertice 1: " << graph.order(1);
	cout << "\nGrau de saida do vertice 3: " << graph.order(3);
	// verifica se existe vizinhos
	if(graph.isAdjacent(0, 1))
		cout << "\n\n1 eh vizinho de 0\n";
	else
		cout << "\n\n1 NAO eh vizinho de 0\n";
	if(graph.isAdjacent(0, 2))
		cout << "2 eh vizinho de 0\n";
	else
		cout << "2 NAO eh vizinho de 0\n";

    graph.dfs(0);
    */
	return 0;
}
