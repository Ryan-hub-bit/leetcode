// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int p = 0,sum = 0,ans = nums[0];
        while(p < nums.size()){
            sum += nums[p];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
            p++;
        }
        return ans;
    }
};