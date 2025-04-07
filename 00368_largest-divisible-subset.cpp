#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int length = nums.size();

        vector<int> dp(length, 1);
        vector<int> prev(length, -1);

        int maxs = 1;
        int maxi = 0;

        // for (auto k : nums) {
        //     cout << "\t" << k << " ";
        // }cout << endl;
        // for (auto k : dp) {
        //     cout << "\t" << k << " ";
        // }cout << endl;
        // for (auto k : prev) {
        //     cout << "\t" << k << " ";
        // }cout << endl << endl;

        for (int i = 1; i < length; i++)
        {
            for (int j = 0; j < i; j++)
            {

                if (nums[i] % nums[j] == 0 && (dp[j] + 1) > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    if (maxs < dp[i])
                    {
                        maxs = dp[i];
                        maxi = i;
                    }
                    prev[i] = j;
                }
                
                // cout << "i:" << i << " j:" << j << endl;
                // for (auto k : nums) {
                //     cout << "\t" << k << " ";
                // }cout << endl;
                // for (auto k : dp) {
                //     cout << "\t" << k << " ";
                // }cout << endl;
                // for (auto k : prev) {
                //     cout << "\t" << k << " ";
                // }cout << endl << endl;
            }
        }

        vector<int> ans;
        for (int i=maxi; i>=0; i=prev[i]) {
            ans.push_back(nums[i]);
        };

        return ans;
    }
};

int main() {
    vector<int> test = {
        1
    };

    vector<int> ans = Solution().largestDivisibleSubset(test);

    for (auto i : ans) {
        cout << i << " ";
    }
}