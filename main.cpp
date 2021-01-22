#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "graph.h"
using namespace std;


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
            if (CDline == 0)
                continue;
            graph.addEdge(i, CDline+CD-1);
        }
    }

    for (int i = CD; i <= PV; i++){
        int PVline;
        string input;

        getline(cin, input);
        istringstream stream(input);

        while (stream >> PVline){
            if (PVline == 0)
                continue;
            graph.addEdge(i, PVline+CD-1);
        }
    }

    int maxPVs = (-60-(-90))/X;
    cout << maxPVs << "\n";

    if (graph.hasCycle(CD, X))
		cout << "1\n";
    else
		cout << "0\n";

	return 0;
}
