#include<unordered_map>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> map;

            for (int i=0; i<nums.size(); i++) {
                map[nums[i]] = i;
            }

            vector<int> ans;

            for (int i=0; i<nums.size(); i++) {
                if (map.count(target-nums[i]) && map[target-nums[i]] != i) {
                    return {i, map[target-nums[i]]};
                }
            }

            return {};
        }
    };

int main() {
    vector<int> test = {
        2,7,11,15
    };
    int target = 9;

    vector<int> ans = Solution().twoSum(test, 9);

    for (auto i : ans) {
        cout << i << " ";
    }
}