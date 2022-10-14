#include <iostream>

using namespace std;

long long memory[1000] = {};
long long ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;

    cin >> N >> M;
    int cur;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> cur;
        sum += cur;
        sum %= M;
        if(sum == 0){
            ans++;
        }
        memory[sum] += 1;
    }

    for (int k = 0; k < M; k++)
    {
        ans += (memory[k]-1) * memory[k] / 2;
    }

    cout << ans;
}