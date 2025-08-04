class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here\
        // dp soln, bool problem in prev submission
        // converting prev recursivv soln to dp soln

        int n=arr.size();
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
        }
        if(total&1) return false; // as if odd sum then cannot be divided in two
        int target=total/2; 
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans=solve(0,target,arr,n,dp);
        return ans;
    }
    
    bool solve(int index,int target,vector<int> &arr, int n,vector<vector<int>> &dp){
        if(index>=n) return false;
        if(target<0) return false;
        if(target==0) return true;
        
        if(dp[index][target]!=-1) return dp[index][target];
        int include=solve(index+1,target-arr[index],arr,n,dp);
        int exclude=solve(index+1,target,arr,n,dp);
        return dp[index][target]=(include||exclude);
    }
};