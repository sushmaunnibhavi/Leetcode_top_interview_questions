/*Question Link: https://leetcode.com/problems/palindromic-substrings/*/

class Solution {
public:
    int countSubstrings(string s) {
        int count_of_palindromic_sub=0;
        for(int i=0;i<s.length();i++){
            int start=i,end=i;
            while(end<s.length() && s[start]==s[end]){
                end++;
                count_of_palindromic_sub++;
            }
            start=start-1;
            while(start>=0 && end<s.length() && s[start]==s[end]){
                count_of_palindromic_sub++;
                start--;
                end++;
            }
        }
        
        return count_of_palindromic_sub;
    }
};