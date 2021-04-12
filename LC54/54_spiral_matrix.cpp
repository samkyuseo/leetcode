#include <vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix);
int main() {
    return 0;
}
// solution does not work lol
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // dimensions 
    int rows = matrix.size(); 
    int cols = matrix[0].size(); 
    vector<int> res; 
    pair<int,int> start = make_pair(0,0); 
    while (rows > 0 && cols > 0) {
        // traversal logic 

        // top 
        for (int i=start.second; i<start.second+cols; i++) {
            res.push_back(matrix[start.first][i]);
        }
         
        if (rows > 1) {
            // left 
            for (int i=start.first+1; i<start.first+rows; i++) {
                res.push_back(matrix[i][cols-1]);
            }
            // bottom
            for (int i=start.second+cols-2; i>=start.second; i--) {
                res.push_back(matrix[start.first+rows-1][i]);
            }
        }

        //left 
        if (rows > 2) {
            for (int i=start.first+rows-2; i>=start.first; i--) {
                res.push_back(matrix[i][start.second]);
            }   
        }
        // updates - dimensions + start indices
        rows -= 2;
        cols -= 2; 
        start.first++;
        start.second++; 
    }
    return res; 
}