/*
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.
*/




// Constant Space and linear time
class Solution {
public:
    int maxPower(string s) {
        int n = s.length(), power, maxPower = 1;
        for (int i=0; i<n-1;) {
            power = 1;
            while (i<n-1 and s[i] == s[i+1]) {
                ++power;
                ++i;
            }
            maxPower = max(maxPower, power);
            ++i;
        }
        return maxPower;
    }
};




// Using deque
class Solution {
public:
    int maxPower(string s) {
        deque<char> q;
        int maxPower = 0, power;
        for (char ch : s) {
            if (q.empty())
                q.push_back(ch);
            else if (ch == q.back())
                q.push_back(ch);
            else if (ch != q.back()) {
                power = q.size();
                maxPower = max(maxPower, power);
                q.clear();
                q.push_back(ch);
            }
        }
        power = q.size();
        maxPower = max(power, maxPower);
        return maxPower;
    }
};
