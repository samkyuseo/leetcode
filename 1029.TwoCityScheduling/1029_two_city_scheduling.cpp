
#include <vector> 
#include <iostream>
using namespace std;

int twoCitySchedCost(vector<vector<int>>&);

int main() {
    vector<vector<int>> costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
    int minCost = twoCitySchedCost(costs);
    cout << minCost << endl;
    return 0;
}
int twoCitySchedCost(vector<vector<int>>& costs) {
    // sort by cost of going to A instead of be ascending 
    std::sort(costs.begin(), costs.end(), [](const vector<int>& v1, const vector<int>& v2){
        return v1[0]-v1[1] < v2[0]-v2[1]; 
    });
    int minCost = 0;
    // first half choose A values that give u the lowest cost of going to A instead of B
    for (int i=0; i<costs.size(); i++) {
        if (i < costs.size()/2) minCost += costs[i][0]; 
        // remaining choose B
        else minCost += costs[i][1];
    }
    return minCost; 
}