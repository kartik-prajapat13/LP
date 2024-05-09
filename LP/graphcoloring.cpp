#include <iostream>
#include <vector>
using namespace std;

int matrix[20][20] = {0};

void accept(int n, int m, char color[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Is there an edge between " << i << " and " << j << ": ";
            cin >> matrix[i][j];
            matrix[j][i] = matrix[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << "Enter color " << i << " name: ";
        cin >> color[i];
    }
}

void display(int n, int m, char color[]) {
    for (int i = 0; i < n; i++) {
        cout << "\t" << i;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 1; i <= m; i++) {
        cout << color[i] << ", ";
    }
    cout << endl;
}

void coloring(int n, int m, char color[]) {
    char solution[20] = {0};
    for (int i = 0; i < n; i++) {
        for (int c = 1; c <= m; c++) {
            bool isSafe = true;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] && solution[j] == color[c]) {
                    isSafe = false;
                    break;
                }
            }
            if (isSafe) {
                solution[i] = color[c];
                break;
            }
        }
    }
    cout << "Coloring of Graph:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << solution[i] << endl;
    }
}

int main() {
    int total_nodes, total_colors;
    cout << "Enter total number of nodes in the graph: ";
    cin >> total_nodes;
    cout << "Enter total number of colors: ";
    cin >> total_colors;
    char color[20];
    accept(total_nodes, total_colors, color);
    display(total_nodes, total_colors, color);
    coloring(total_nodes, total_colors, color);
    return 0;
}


// Enter total number of nodes in the graph: 4
// Enter total number of colors: 3

// Is there an edge between 0 and 1: 1
// Is there an edge between 0 and 2: 1
// Is there an edge between 0 and 3: 0
// Is there an edge between 1 and 2: 1
// Is there an edge between 1 and 3: 0
// Is there an edge between 2 and 3: 1

// Enter color 1 name: r
// Enter color 2 name: b
// Enter color 3 name: g

//     0   1   2   3
// 0   0   1   1   0   
// 1   1   0   1   0   
// 2   1   1   0   1   
// 3   0   0   1   0   
// Red, Blue, Green, 
// Coloring of Graph:
// Node 0: Red
// Node 1: Blue
// Node 2: Green
// Node 3: Red
