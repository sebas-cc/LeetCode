class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int numsLength = nums.size();
        vector<int> result(numsLength, 0);

        int leftSum = 0;
        for (int i = 0; i < numsLength; ++i) {
            result[i] += i * nums[i] - leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = numsLength - 1; i >= 0; --i) {
            result[i] += rightSum - (numsLength - i - 1) * nums[i];
            rightSum += nums[i];
        }

        return result;
    }
};