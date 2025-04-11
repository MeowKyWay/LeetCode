#include<vector>
#include<iostream>

using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {

            int i=0;
            int j=matrix[0].size()-1;

            while (1) {
                // cout << i << " " << j << " " << matrix[i][j] << endl;
                if (i >= matrix.size() || j < 0) {
                    return false;
                }
                if (matrix[i][j] < target) {
                    i++;
                }
                else if (matrix[i][j] > target) {
                    j--;
                }
                else {
                    return true;
                }
            }
        }
    };

int main() {
    vector<vector<int> > matrix = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };

    cout << Solution().searchMatrix(matrix, 3);
}