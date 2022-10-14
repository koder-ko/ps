#include <iostream>
#include <queue>
using namespace std;
string s;

int main()
{
    queue<int> a;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int push_num;
        if (s == "push")
        {
            cin >> push_num;
            a.push(push_num);
        }
        else if (s == "pop")
        {
            if (a.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << a.front() << "\n";
            a.pop();
        }
        else if (s == "size")
        {
            cout << a.size() << "\n";
        }
        else if (s == "empty")
        {
            cout << int(a.empty()) << "\n";
        }
        else if (s == "front")
        {
            if (a.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << a.front() << "\n";
        }
        else if (s == "back")
        {
            if (a.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << a.back() << "\n";
        }
    }
}