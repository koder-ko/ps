#include <iostream>
using namespace std;

int memory[100][10] = {};
int num;

int stairnum(int stair)
{

    if (stair == 0)
    {
        memory[0][0] = 0;
        memory[0][9] = 1;
        for (int i = 1; i < 9; i++)
        {
            memory[0][i] = 1;
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (i == 0)
            {
                memory[stair][1] += memory[stair - 1][0];
            }
            else if (i == 9)
            {
                memory[stair][8] += memory[stair - 1][9];
            }
            else
            {
                memory[stair][i + 1] += memory[stair - 1][i];
                memory[stair][i - 1] += memory[stair - 1][i];
            }
        }
        for (int i = 0; i < 10; i++){
            memory[stair][i] %= 1000000000;
        }
    }

    

    if (num == stair)
    {
        int total = 0;
        for (int j = 0; j < 10; j++)
        {
            total += memory[stair][j];
            total %= 1000000000;
        }
        return total;
    }

    return stairnum(stair + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    num -= 1;
    int answer = stairnum(0);
    cout << answer;
}
