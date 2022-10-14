#include <iostream>

using namespace std;

string first;
string second;

int dp[1000] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> first;
    cin >> second;

    for (int i = 0; i < second.size(); i++)
    {
        int maxcount = 0;
        for (int j = 0; j < first.size(); j++)
        {
            if (second[i] == first[j])
            {
                int c = max(maxcount + 1, dp[j]);
                maxcount = max(dp[j], maxcount);
                dp[j] = c;
            }
            else{
                maxcount = max(dp[j], maxcount);
            }
        }
    }

    int ans = 0;
    for (int k = 0; k < first.size(); k++)
    {
        ans = max(ans, dp[k]);
    }

    cout << ans;
}