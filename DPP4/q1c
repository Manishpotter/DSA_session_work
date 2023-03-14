class Solution{
public:
    int solve(int arr[],int i,int j,vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minm=INT_MAX;
        for(int k=i ; k<=j-1 ; k++){
            // cout<<arr[i-1]<<" "<<arr[k]<<" "<<arr[j]<<endl;
            int temp = solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            minm=min(temp,minm);
        }
        return dp[i][j]=minm;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int> (N,-1));
        int i=1;
        int j=N-1;
        return solve(arr,i,j,dp);
    }
};
