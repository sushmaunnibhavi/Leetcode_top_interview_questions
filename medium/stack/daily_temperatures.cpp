/*Question Link: https://leetcode.com/problems/daily-temperatures/*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //We find nearest greater to left
        stack<int>st;//stack stores indexes of elements
        
        vector<int>res;
        for(int i=T.size()-1;i>=0;i--){
            if(st.empty()){
                res.push_back(0);
            }
            else{
                while(!st.empty() && T[st.top()] <= T[i]){
                    st.pop();
                }
                if(st.empty()){
                    res.push_back(0);
                }
                else{
                    res.push_back(st.top()-i);
                }
            }
            
            st.push(i);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};