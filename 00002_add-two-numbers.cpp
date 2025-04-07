#include<math.h>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            string n1, n2;

            for (ListNode* i = l1; i != nullptr; i = (*i).next) {
                n1.append(to_string(i->val));
            }
            for (ListNode* i = l2; i != nullptr; i = (*i).next) {
                n2.append(to_string(i->val));
            }

            string num = "";

            bool carry = false;
            for (char i = 0; i < n1.length() || i < n2.length(); i++) {

                int v1, v2;
                if (i >= n1.length()) v1 = 0;
                else v1 = n1[i] - '0';
                if (i >= n2.length()) v2 = 0;
                else v2 = n2[i] - '0';

                int r = v1 + v2;
                if (carry) {
                    r++; 
                    carry = false;
                }
                if (r >= 10) {
                    r-=10;
                    carry = true;
                }
                num.insert(num.begin(), '0' + r);
            }
            if (carry) {
                num.insert(num.begin(), '1');
            }

            // cout << num << endl;

            ListNode* ans = new ListNode;

            ListNode* current = ans;

            for (int i=num.length()-1; i>=0; i--) {
                current->val = (num[i]-'0');
                if (i!=0) {
                    current->next = new ListNode;
                }

                current = current->next;
            }

            return ans;
        }
    };

int main() {
    ListNode* l1 = new ListNode(1, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(1)))))))))))))))))))))))))))))))))))))))))))))))));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* ans = Solution().addTwoNumbers(l1, l2);

    for (ListNode* i = ans; i != nullptr; i=i->next) {
        cout << i->val;
    }
}