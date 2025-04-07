#include<vector>
#include<iostream>

using namespace std;

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total = 0;
            // Calculate total sum
            for (int i : nums) {
                total += i;
            }

            // If total is odd, It is impossible to partition
            if (total%2 != 0) {
                return false;
            }

            int target = total/2;
            vector<bool> dp(target+1, false);
            dp[0] = true;

            for (int i=0; i<nums.size(); i++) {
                for (int j=target; j>=nums[i]; j--) {
                    dp[j] = dp[j] || dp[j-nums[i]];

                    // cout << "i:" << i << " j:" << j << endl;
                    // for (auto k : dp) {
                    //     cout << k << " ";
                    // }cout << endl;

                    if (dp[j] && j == target) return true;
                }
            }
            return dp[target];

            // 1 2 3 6
            // 0 1 2 3 4 5 6
            // 1 0 0 0 0 0 0
            
            // i:0 j:6
            // 1 0 0 0 0 0 0

            // i:0 j:5
            // 1 0 0 0 0 0 0

            // i:0 j:4
            // 1 0 0 0 0 0 0

            // i:0 j:3
            // 1 0 0 0 0 0 0

            // i:0 j:2
            // 1 0 0 0 0 0 0

            // i:0 j:1
            // 1 1 0 0 0 0 0

            // i:1 j:6
            // 1 1 0 0 0 0 0

            // i:1 j:5
            // 1 1 0 0 0 0 0

            // i:1 j:4
            // 1 1 0 0 0 0 0

            // i:1 j:3
            // 1 1 0 1 0 0 0

            // i:1 j:2
            // 1 1 1 1 0 0 0

            // i:2 j:6
            // 1 1 1 1 0 0 1 true
        }
    };

int main() {
    vector<int> test = {
        1, 2, 3, 6
    };

    cout << Solution().canPartition(test);
}