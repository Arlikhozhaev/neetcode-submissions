class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxGlobal = nums[0];
        int currentSum = nums[0];

        for(size_t i = 1; i < nums.size(); ++i) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxGlobal = max(maxGlobal, currentSum);
        }

        return maxGlobal;
    }
};
