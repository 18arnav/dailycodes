#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
bool iswavedecreasing(vector<int> &arr){
    bool flag=true;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i]<arr[i-1] and flag==true){
            flag=false;
        }
        else if(arr[i]>arr[i-1] and flag==false){
            flag=true;
        }else{
            return false;
        }
        
    }

    return true;
}  
bool iswaveincreasing(vector<int> &arr){
    bool flag=true;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i]>arr[i-1] and flag==true){
            flag=false;
        }
        else if(arr[i]<arr[i-1] and flag==false){
            flag=true;
        }else{
            return false;
        }
        
    }

    return true;
}
int solve(vector<int> &arr,int n,int m,vector<vector<int>> &dp,unordered_map<int,int> &mp){
    if(n==0){
        // for (int i = 0; i < arr.size(); i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"hello"<<endl;
        return iswaveincreasing(arr) or iswavedecreasing(arr);
    }
    if(n==0){
        return 0;
    }
    // cout<<n<<" "<<m<<endl;
    // if(dp[n][m]!=-1){
    //     return dp[n][m];
    // }
    int ans=0;
    int temp=m;
    if( n==arr.size() and arr[n-1]==-1){
        // cout<<n<<" "<<m<<endl;
        for (int i = 1; i <=m; i++)
        {
            
                // mp[i]++;
                arr[n-1]=i;
                ans=(ans+solve(arr,n-1,m,dp,mp))%mod;
                arr[n-1]=-1;
               
        }
    }
    else if(arr[n-1]==-1){
        for (int i = 1; i <=m; i++)
        {

            if(i!=arr[n]){
                // mp[i]++;
                //  cout<<i<<" "<<arr[n]<<endl;
                arr[n-1]=i;
                ans=(ans+solve(arr,n-1,m,dp,mp))%mod;
                // mp.erase(i);
                arr[n-1]=-1;
            }
        }
    }else if(n<arr.size() and arr[n-1]>arr[n] || arr[n-1]<arr[n]){
        ans=(ans+solve(arr,n-1,m,dp,mp))%mod;
    }
    return  ans%mod;
    
}
int countwaystocreatewave(vector<int> &arr,int m){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(m+1,-1));
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(arr[i]!=-1)
        mp[arr[i]]++;
    }
    // cout<<mp.size()<<endl;
    return solve(arr,n,m,dp,mp);
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<countwaystocreatewave(arr,m)<<endl;


    return 0;
}