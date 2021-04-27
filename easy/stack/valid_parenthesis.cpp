/*Question Link: https://leetcode.com/problems/valid-parentheses/*/

class Solution {
public:
    bool isValid(string s) {
        int i=0;
        stack<char>st;
        while(s[i]!='\0'){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(s[i]==')' && (st.empty() || st.top()!='(')){
                    return false;
                }
                else if(s[i]==')' && (!st.empty() && st.top()=='(')){
                    st.pop();
                }
                else if(s[i]=='}' && (st.empty() || st.top()!='{')){
                    return false;
                }
                else if(s[i]=='}' && (!st.empty() && st.top()=='{')){
                    st.pop();
                }
                else if(s[i]==']' && (st.empty() || st.top()!='[')){
                    return false;
                }
                else if(s[i]==']' && (!st.empty() && st.top()=='[')){
                    st.pop();
                }
            }
            i++;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};