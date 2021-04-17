/*Question Link: https://leetcode.com/problems/valid-anagram/*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if(s.length() != t.length()){
            return false;
        }
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]+=1;
        }
        
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])==mp.end()){
                return false;
            }
            else{
                mp[t[i]]-=1;
                if(mp[t[i]]==0){
                    mp.erase(t[i]);
                }
            }
        }
        
        if(mp.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};


/*

Time Complexity:
Let length of s be m and t be n
For inserting elements in unordered map->log m =>For m chars
it is O(mlogm)
Finding element in unordered map is constant,hence for loop takes
O(n) time

=>Time Complexity is O(mlogm + n)

*/