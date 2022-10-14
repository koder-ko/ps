#include <iostream>
#include <algorithm>

using namespace std;


int memory[10002][3];

int winery[10001] = {
    0,
};

int wine_count;

int wine(int step)
{
    if (step == 0)
    {
        memory[1][0] = winery[0];
        memory[1][2] = 0;
    }
    else
    {
        if (memory[step][2] != -1)
        {
            memory[step + 1][0] = winery[step] + memory[step][2];
        }
        if (memory[step][0] != -1)
        {
            memory[step + 1][1] = winery[step] + memory[step][0];
        }
        if (memory[step][0] != -1 || memory[step][1] != -1 || memory[step][2] != -1)
        {
            memory[step + 1][2] = max({memory[step][0], memory[step][1], memory[step][2]});
        }
    }

    if (step == wine_count)
    {
        return max({memory[step][0], memory[step][1], memory[step][2]});
    }

    return wine(step + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> wine_count;

    for (int i = 0; i < wine_count; i++)
    {
        cin >> winery[i];
    }

    for (int j = 0; j < 10002; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            memory[j][k] = -1;
        }
    }

    cout << wine(0);
}
