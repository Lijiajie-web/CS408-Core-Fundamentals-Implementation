/**
 * @file Bankers_Algorithm_OS.cpp
 * @brief Operating Systems - Banker's Algorithm for Deadlock Avoidance
 * @note CS408 Operating System Core Concept Implementation.
 */

#include <iostream>
using namespace std;

int main() {
    // P0, P1, P2, P3, P4 are the Process names here
    int n = 5; // Number of processes
    int m = 3; // Number of resources
    
    // Allocation Matrix
    int alloc[5][3] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };
    // MAX Matrix
    int max[5][3] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, { 4, 3, 3 } };
    // Available Resources
    int avail[3] = { 3, 3, 2 }; 

    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++) f[k] = 0;
    
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) need[i][j] = max[i][j] - alloc[i][j];
    }
    
    int y = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++) avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    
    cout << "Following is the SAFE Sequence: \n";
    for (int i = 0; i < n - 1; i++) cout << " P" << ans[i] << " ->";
    cout << " P" << ans[n - 1] << endl;

    return 0;
}