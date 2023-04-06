#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0; i < n; ++i) {
            nums[i << 1] |= (nums[i] << 10);
            nums[(i << 1) + 1] |= (nums[i + n] << 10);
        }
        for(auto &num : nums) {
            num >>= 10;
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int>test = {2,5,1,3,4,7};
    vector<int>ans = s.shuffle(test, 3);
}