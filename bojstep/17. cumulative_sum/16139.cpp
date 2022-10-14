#include <iostream>

using namespace std;

string S;
int q;

int cache[200001][26] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    cin >> q;

    int c;
    for (int i = 1; i <= S.length(); i++)
    {
        c = S[i - 1] - 97;
        for (int j = 0; j < 26; j++)
        {
            cache[i][j] = cache[i - 1][j];
            if (j == c)
            {
                cache[i][j] += 1;
            }
        }
    }

    char cur;
    int a, b;
    for (int k = 0; k < q; k++)
    {
        cin >> cur;
        cin >> a >> b;
        cout << cache[b+1][cur - 97] - cache[a][cur - 97] << "\n";
    }
}