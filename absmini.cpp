#include <iostream>
#include <vector>
using namespace std;

int f(int idx, int sum, int arr[], int n, int totalSum,
      vector<vector<int>> &dp)
{
    if (idx == n)
    {
        
        return abs((totalSum - sum) - sum);
    }

    if (dp[idx][sum] != -1)
    {
        
        return dp[idx][sum];
    }

    int pick = f(idx + 1, sum + arr[idx], arr, n, totalSum, dp);

    int notPick = f(idx + 1, sum, arr, n, totalSum, dp);

    return dp[idx][sum] = min(pick, notPick);
}

int findMin(int arr[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    vector<vector<int>> dp(n + 1,
                           vector<int>(totalSum + 1, -1));

    return f(0, 0, arr, n, totalSum, dp);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << findMin(arr, n);

    return 0;
}
