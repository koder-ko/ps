#include <iostream>
#include <vector>


using namespace std;



int main(){

    int d;

    cin >> d;

    vector<int> dp(d+1);

    dp[1] = 0;

    for(int i = 2; i <= d; i++){
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0)
        dp[i] = min(dp[i/2] + 1, dp[i]);
        if(i % 3 == 0)
        dp[i] = min(dp[i/3] + 1, dp[i]);
    }

    cout << dp[d];
}