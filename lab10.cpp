#include <iostream>
#include <algorithm>
using namespace std;

#define INF 999
int main() {
    int nV;
    cout << "Enter number of vertices: ";
    cin >> nV;
       
//creating and printing adjacency matrix
    int graph[nV][nV];
    cout<<"Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> graph[i][j];
        }
    }
    cout<<"the adjacency matrix:"<<endl;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cout << graph[i][j]<<" ";
        }
        cout<<endl;
    }

//calculating shortest path according to Warshalls algorithm
    for (int k = 0; k < nV; k++) {
        for (int i = 0; i < nV; i++) {
            for (int j = 0; j < nV; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

//printing the resulting shortest path matrix
    cout << "Shortest distance between every pair of vertices:\n";
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (graph[i][j] == INF)
                cout << "INF\t";
            else
                cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
  return 0;
}
