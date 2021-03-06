// Given an array A of positive integers, let S be the sum of the digits of the minimal element of A.
//
// Return 0 if S is odd, otherwise return 1.
//
//  
//
// Example 1:
//
//
// Input: [34,23,1,24,75,33,54,8]
// Output: 0
// Explanation: 
// The minimal element is 1, and the sum of those digits is S = 1 which is odd, so the answer is 0.
//
//
// Example 2:
//
//
// Input: [99,77,33,66,55]
// Output: 1
// Explanation: 
// The minimal element is 33, and the sum of those digits is S = 3 + 3 = 6 which is even, so the answer is 1.
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 100
// 	1 <= A[i].length <= 100
//


class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min_num = A[0];
        for(int i = 1;i < A.size();i++) min_num = min(min_num, A[i]);
        int sum = 0;
        while(min_num > 0){
            sum += min_num % 10;
            min_num /= 10;
        }
        return (sum + 1) % 2;
    }
};
