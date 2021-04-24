/*Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0){
            return 0;
        }
        //find nearest smaller histogram to left
        vector<int>nsl;
        int pseudo_idx=-1;
        stack<pair<int,int>>st;
        st.push({heights[0],0});
        for(int i=0;i<heights.size();i++){
            if(st.empty()){
                nsl.push_back(pseudo_idx);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                nsl.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i]){
                    st.pop();
                }
                if(st.size()==0){
                    nsl.push_back(pseudo_idx);
                }
                else{
                    nsl.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        
        //find nearest smaller histogram to right
        stack<pair<int,int>>st1;
        vector<int>nsr;
        pseudo_idx=heights.size();
        
        for(int i=heights.size()-1;i>=0;i--){
            if(st1.empty()){
                nsr.push_back(pseudo_idx);
            }
            else if(st1.size()>0 && st1.top().first<heights[i]){
                nsr.push_back(st1.top().second);
            }
            else if(st1.size()>0 && st1.top().first>=heights[i]){
                while(st1.size()>0 && st1.top().first>=heights[i]){
                    st1.pop();
                }
                if(st1.size()==0){
                    nsr.push_back(pseudo_idx);
                }
                else{
                    nsr.push_back(st1.top().second);
                }
            }
            st1.push({heights[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        int max_area=0;
        for(int i=0;i<heights.size();i++){
            max_area=max(max_area,(nsr[i]-nsl[i]-1)*heights[i]);
        }
        
        return max_area;
        
    }
};