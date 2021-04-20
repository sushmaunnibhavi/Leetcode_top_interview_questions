/*Question Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/*/

class Solution {
public:
    class ArrayElement{
      public:
        int val;
        int idx;
    };
    
    void merge(vector<ArrayElement> &converted_array,vector<int>& ans,int low,int mid,int high){
        int size_of_first_array=mid-low+1;
        int size_of_second_array=high-mid;
       
        ArrayElement temp1[size_of_first_array];
        ArrayElement temp2[size_of_second_array];
        
        for (int i = 0; i < size_of_first_array; i++)
            temp1[i] = converted_array[low + i];
        for (int j = 0; j < size_of_second_array; j++)
            temp2[j] = converted_array[mid + 1 + j];
        
        int i=0;//Starting idx for 1st subarray
        int j=0;//Starting idx for second subarray
        int k=low,count=0;
        
        while(i<size_of_first_array && j<size_of_second_array){
            ArrayElement ae1=temp1[i];
            ArrayElement ae2=temp2[j];
            if(ae2.val<ae1.val){
                count++;
                j++;
                converted_array[k]=ae2;
            }
            else{
                ans[ae1.idx]+=count;
                i++;
                converted_array[k]=ae1;
            }
            k++;
        }
        
        if(i<size_of_first_array){
            while(i<size_of_first_array){
                ArrayElement ae1=temp1[i];
                ans[ae1.idx]+=count;
                i++;
                converted_array[k]=ae1;
                k++;
            }
        }
        else if(j<size_of_second_array){
            while(j<size_of_second_array){
                ArrayElement ae2=temp2[j];
                j++;
                converted_array[k]=ae2;
                k++;
            }
        }
        
        return;
    }
    void performMergeSort(vector<ArrayElement>& converted_array,vector<int>& ans,int low,int high){
        if(low>=high)
            return;
        int mid=low+(high-low)/2;
        performMergeSort(converted_array,ans,low,mid);
        performMergeSort(converted_array,ans,mid+1,high);
        merge(converted_array,ans,low,mid,high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        if(nums.size()==0){
            return ans;
        }
        
        vector<ArrayElement>converted_array;
        for(int i=0;i<nums.size();i++){
            ArrayElement ae;
            ae.val=nums[i];
            ae.idx=i;
            converted_array.push_back(ae);
        }
        performMergeSort(converted_array,ans,0,nums.size()-1);
        
        return ans;
    }
};