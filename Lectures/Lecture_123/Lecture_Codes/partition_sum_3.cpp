class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here\
        // dp soln, bool problem in prev submission
        // tabulation soln

        int n=arr.size();
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
        }
        if(total&1) return false; // as if odd sum then cannot be divided in two
        int target=total/2; 
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        
        // base case target=0 column is 1
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                
                bool include=false;
                if(j-arr[i]>=0){
                    include=dp[i+1][j-arr[i]];
                }
                bool exclude=dp[i+1][j];
                dp[i][j]=(include||exclude);
            }
        }
        
        return dp[0][target];
    }

};