#include<bits/stdc++.h>
using namespace std;
vector<int> predictday(vector<int> arr,int k){
    int n=arr.size();
    vector<int> left(n);
    left[0]=1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]<=arr[i-1]){
            left[i]=left[i-1]+1;
        }else{
            left[i]=1;
        }
    }
    vector<int> right(n);
    right[n-1]=1;
    for (int i = n-2; i >=0; i--)
    {
        if(arr[i]<=arr[i+1]){
            right[i]=right[i+1]+1;
        }else{
            right[i]=1;
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(left[i]>k and right[i]>k){
            ans.push_back(i+1);
        }
    }
    return ans;

    
}
int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int> ans=predictday(arr,k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}