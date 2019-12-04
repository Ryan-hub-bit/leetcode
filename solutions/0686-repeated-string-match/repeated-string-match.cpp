// Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
//
// For example, with A = "abcd" and B = "cdabcdab".
//
// Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
//
// Note:
// The length of A and B will be between 1 and 10000.
//


class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string tmp = A;
        int cnt = 1;
        while(tmp.size() <= 2 * A.size() + B.size()){
            if(tmp.find(B) != -1) return cnt;
            tmp = tmp + A;
            cnt++;
        }
        return -1;
    }
};
