#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

class Solution {
    public:

        int shipWithinDays(vector<int>& weights, int days) {
            int n = weights.size();
            int maxWeight = 0;

            vector<int> cumulative(n+1);
            cumulative[0] = 0;

            for (int i=0; i<n; i++) {
                cumulative[i+1] = cumulative[i] + weights[i];
                maxWeight = max(weights[i], maxWeight);
                // cout << cumulative[i+1] << " ";
            }
            // cout << endl;

            // 1 2 3 4  5  6  7  8  9  10
            // 1 3 6 10 15 21 28 36 45 55

            int lower = maxWeight;
            int upper = cumulative[n]+1;

            int minWeight = INT32_MAX;

            while (1) {
                int middle = (lower + upper) / 2;
                // cout << lower << " " << middle << " " << upper << endl;
                int d = calculateDay(cumulative, middle);
                // cout << d << endl;
                if (lower == upper) break;
                if (d <= days) {
                    upper = middle;
                    minWeight = min(minWeight, middle);
                    continue;
                }
                if (d > days) {
                    lower = middle + 1;
                    continue;
                }
            }

            return minWeight;
        }

    private:

        int sumWeight(vector<int>& cumulative, int start, int end) {
            return cumulative[end] - cumulative[start];
        }

        int calculateDay(vector<int>& cumulative, int weight) {
            int day = 0;
            int prev = 0;
            for (int i=0; i<cumulative.size(); i++) {
                while (i+1<cumulative.size() && cumulative[i+1]-prev <= weight) {
                    i++;
                }
                // cout << i << " ";
                day++;
                prev = cumulative[i];
            }
            // cout << endl;
            return day;
        }
    };


int main() {
    vector<int> weights = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    cout << Solution().shipWithinDays(weights, 1);
}