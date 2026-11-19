class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size() - 1;
        int left = 0;

        while (left < right) {

            int sum = numbers[right] + numbers[left];

            if (sum == target) {
                return {left + 1, right + 1};
            }
            else if (sum > target) {
                right--;
            }
            else if (sum < target) {
                left++;
            }
        }

        return {-1, -1};
    }
};