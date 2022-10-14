#include <iostream>

using namespace std;
int N, K;
int weight[100];
int value[100];

int cache[100001][100] = {};

int backpack(int weight_left, int index)
{
    if (index == N || weight_left <= 0)
    {
        return 0;
    }
    if (cache[weight_left][index] != 0)
    {
        return cache[weight_left][index];
    }
    if (weight_left < weight[index])
    {
        cache[weight_left][index] = backpack(weight_left, index + 1);
        return cache[weight_left][index];
    }
    cache[weight_left][index] =
        max(
            backpack(weight_left - weight[index], index + 1) + value[index],
            backpack(weight_left, index + 1));
    return cache[weight_left][index];
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    } 

    cout << backpack(K, 0);
}