#include <iostream>

using namespace std;

int binomial(int n, int k)
{
    if(n == k){
        return 1;
    }
    if (k == 0)
    {
        return 1;
    }
    return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << binomial(N, K);
}