/*Question link: https://leetcode.com/problems/roman-to-integer/*/

class Solution {
public:
    int romanToInt(string s) {
        if(s.length()==0){
            return 0;
        }
        
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int ans=mp[s[0]];
        
        for(int i=1;i<s.length();i++){
            if(mp[s[i]]>mp[s[i-1]]){
                ans+=(mp[s[i]]-2*mp[s[i-1]]);
            }
            else{
                ans+=mp[s[i]];
            }
        }
        return ans;
    }
};