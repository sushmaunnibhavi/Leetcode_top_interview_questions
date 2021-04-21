/*Question Link: https://leetcode.com/problems/word-search-ii/*/

/*Using DFS and Map*/

class Solution {
public:
    bool findIfWordPresent(vector<vector<char>>& board,int i,int j,string word,int idx){
        if(idx == word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$'){
            return false;
        }
        if(board[i][j] != word[idx]){
            return false;
        }
        
        //to mark it as visited
        char e=board[i][j];
        board[i][j]='$';
        
        bool a=findIfWordPresent(board,i+1,j,word,idx+1);
        bool b=findIfWordPresent(board,i-1,j,word,idx+1);
        bool c=findIfWordPresent(board,i,j+1,word,idx+1);
        bool d=findIfWordPresent(board,i,j-1,word,idx+1);
        
        board[i][j]=e;
        
        return (a || b || c || d);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<char,vector<pair<int,int>>>mp;
        
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[board[i][j]].push_back({i,j});
            }
        }
        
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            if(mp.find(words[i][0]) == mp.end()){
                continue;
            }
            else{
                vector<pair<int,int>>temp=mp[words[i][0]];
                for(int j=0;j<temp.size();j++){
                    bool wordPresent=findIfWordPresent(board,temp[j].first,temp[j].second,words[i],0);
                    
                    if(wordPresent){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};

/*

Time Complexity:
O(nm * nm * size_of_word)

Say we have a 2*2 board and word: aaaaa

a a
a a

Here each character in board is a valid starting idx to search.And we never get aaaaa because max we can get only aaaa,
hence we search through all the a's to find the ans

*/