#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "graph.h"
using namespace std;

int calculateMaxPVs(int X){
    return (-60-(-90))/X;
}

int main(){
    int CD, PV, X;

    cin >> CD >> PV >> X;
    cin.ignore();

    graph graph(CD+PV);

    for (int i = 0; i < CD; i++){
        int CDline;
        string input;

        getline(cin, input);
        istringstream stream(input);

        while (stream >> CDline){
            graph.addEdge(i, CDline);
        }
    }

    for (int i = 0; i < PV; i++){
        int PVline;
        string input;

        getline(cin, input);
        istringstream stream(input);

        while (stream >> PVline){
            graph.addEdge(i, PVline);
        }
    }

    int maxPVs = calculateMaxPVs(X);
    cout << "MAX PV " <<maxPVs<< "\n";
    cout << "*\n";

    if (graph.hasCycle())
		cout << "C = 1\n";
    else
		cout << "C = 0\n";

	return 0;
}
