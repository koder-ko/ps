#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int coin_arr[10];

    int coin;
    int last = 100000000;
    for (int i = 0; i < N; i++)
    {
        cin >> coin;
        coin_arr[i] = coin;

        if (coin > K)
        {
            continue;
        }

        int sum = 0;
        int cur = 0;
        for (int j = i; j >= 0; j--)
        {
            if(K - sum <= 0){
                break;
            }
            if(K - sum < coin_arr[j]){
                continue;
            }
            cur += int((K - sum) / coin_arr[j]);
            sum += (K - sum) - (K - sum) % coin_arr[j];
        }

        last = min(cur, last);
    }
    cout << last;
}