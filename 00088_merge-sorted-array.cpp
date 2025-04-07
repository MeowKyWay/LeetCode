#include<vector>
#include<iterator>
#include<iostream>

using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int ite1 = 0, ite2 = 0;

            vector<int> ans;

            while (ite1 < m || ite2 < n) {
                // cout << ite1 << " " << ite2 << endl;
                if (ite1 >= m) {
                    ans.push_back(nums2[ite2]);
                    ite2++;
                }
                else if (ite2 >= n) {
                    ans.push_back(nums1[ite1]);
                    ite1++;
                }
                else if (nums1[ite1] > nums2[ite2]) {
                    ans.push_back(nums2[ite2]);
                    ite2++;
                }
                else if (nums2[ite2] >= nums1[ite1]) {
                    ans.push_back(nums1[ite1]);
                    ite1++;
                }
            }

            nums1 = ans;
        }
    };

int main() {
    vector<int> v1 = {
        1,2,3,0,0,0
    };
    vector<int> v2 = {
        2,5,6
    };

    Solution().merge(v1, 3, v2, 3);

    for (auto i:v1) {
        cout << i << " ";
    }
}