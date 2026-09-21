class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        unordered_map<int, int> numMap;

        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if(numMap.find(complement) != numMap.end()) {
                output.push_back(numMap[complement]);
                output.push_back(i);

                return output;
            }

            numMap[nums[i]] = i;
        }

        return output; 
    }
};
