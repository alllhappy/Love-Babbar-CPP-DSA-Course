class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        // previous submission cant be be converted to dp easily
        // now babbar approach for recuresion
        // first we calcualte sum of whole array , for equal sum of two subsets the
        // totalsum/2 should be the sum of 1 subset then only possibe to
        //make the other half
        // will check this sum using include exclude and a target sum param
        int n=arr.size();
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
        }
        if(total&1) return false; // as if odd sum then cannot be divided in two
        int target=total/2; 
        int ans=solve(0,target,arr,n);
        return ans;
    }
    
    bool solve(int index,int target,vector<int> &arr, int n){
        if(index>=n) return false;
        
        if(target<0) return false;
        if(target==0) return true;
        int include=solve(index+1,target-arr[index],arr,n);
        int exclude=solve(index+1,target,arr,n);
        return (include||exclude)
    }
};