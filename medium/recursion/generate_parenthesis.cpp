/*Question link: https://leetcode.com/problems/generate-parentheses/*/

class Solution {
public:
    void generateParen(int n,int num_open_brac,int num_closed_brac,string temp,vector<string>& ans){
        if(n<=0 && num_open_brac==num_closed_brac){
            ans.push_back(temp);
            return;
        }
        
        else if(n<=0 && num_open_brac!=num_closed_brac){
            return;
        }
        if(num_open_brac > num_closed_brac){
            generateParen(n-1,num_open_brac+1,num_closed_brac,temp+'(',ans);
            generateParen(n-1,num_open_brac,num_closed_brac+1,temp+')',ans);
        }
        else{
            generateParen(n-1,num_open_brac+1,num_closed_brac,temp+'(',ans);
        }
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        if(n==0){
            return ans;
        }
        
        int num_open_brac=0,num_closed_brac=0;
        
        string temp="";
        generateParen(n*2,num_open_brac,num_closed_brac,temp,ans);
        return ans;
    }
};


/*

Time complexity:
We have 2 choices for each, so 2^(2n) => 2^(2n)

*/