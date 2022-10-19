#include <stdio.h>
#include <iostream>

int paper[64][64];

using namespace std;

string start_s = "(";
string end_s = ")";

string quad_tree(int x1, int y1, int x2, int y2)
{

    if (x1 == x2 && y1 == y2)
    {
        if (paper[x1][y1] == 1)
        {
            return "1";
        }
        else
        {
            return "0";
        }
    }

    int check = paper[x1][y1];
    for (int x = x1; x <= x2; x++)
    {
        for (int y = y1; y <= y2; y++)
        {
            if (check != paper[x][y])
            {
                int dist = (x2 - x1 + 1) / 2 - 1;
                string a = quad_tree(x1, y1, x1 + dist, y1 + dist);
                string b = quad_tree(x1 + dist + 1, y1, x2, y2 - dist - 1);
                string c = quad_tree(x1, y1 + dist + 1, x2 - dist - 1, y2);
                string d = quad_tree(x2 - dist, y2 - dist, x2, y2);
                return start_s + a + c + b + d + end_s;
            }
        }
    }

    if (paper[x1][y1] == 1)
    {
        return "1";
    }
    else
    {
        return "0";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    scanf("%d", &N);

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            scanf("%1d", &paper[x][y]);
        }
    }

    cout << quad_tree(0, 0, N - 1, N - 1);
}