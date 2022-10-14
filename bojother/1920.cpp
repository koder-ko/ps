#include <iostream>
#include <algorithm>

using namespace std;

int A[100010] = {};
int B[100010] = {};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    sort(A, A + n);
    for (int k = 0; k < m; k++)
    {
        cout << int(binary_search(A, A + n, B[k])) << "\n";
    }
}