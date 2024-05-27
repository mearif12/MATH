#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
//adjacency list representation of the graph
    unordered_map<char, list<char>> graph = {
        {'a', {'b', 'c', 'd'}},
        {'b', {'a', 'c'}},
        {'c', {'a', 'b', 'd', 'e', 'f'}},
        {'d', {'a', 'c', 'e'}},
        {'e', {'c', 'd', 'f'}},
        {'f', {'c', 'e'}}
    };

//task-1:sort vertices by their degrees in descending order
    list<char> vertices;
    for (const auto& pair : graph) {
        vertices.push_back(pair.first);
    }
    vertices.sort([&graph](char a, char b) {
        return graph[a].size() > graph[b].size();
    });

//task-2:color the nodes using Welsh-Powell algorithm
    unordered_map<char, int> colorMap;
    for (char node : vertices) {
        set<int> neighborColors;
        for (char neighbor : graph[node]) {
            if (colorMap.find(neighbor) != colorMap.end()) {
                neighborColors.insert(colorMap[neighbor]);
            }
        }
        int color = 0;
        while (neighborColors.find(color) != neighborColors.end()) {
            color++;
        }
        colorMap[node] = color;
        cout << node << ": color " << color << endl;
    }

    return 0;
}

/**---------------------output---------------------------
Node 'c': It has no neighbors with assigned colors,
          so it can be assigned color 0.
Node 'e': Its neighbors are 'c' (color 0) and 'd' (unassigned).
          So, it can be assigned color 1.
Node 'a': Its neighbors are 'b', 'c', and 'd'. 'c' is colored with color 0.
          So, it can be assigned color 2.
Node 'f': Its neighbors are 'c' (color 0) and 'e' (color 1).
          So, it can be assigned color 2.
Node 'b': Its neighbor 'c' is colored with color 0.
          So, it can be assigned color 1.
Node 'd': Its neighbors are 'a' (color 2), 'c' (color 0), and 'e' (color 1).
          So, it can be assigned color 3.
*/
