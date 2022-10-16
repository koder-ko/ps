#include <iostream>
#include <deque>

using namespace std;

deque<int> cache;
int is_front = 1;

void push(int val)
{
    if (is_front)
    {
        cache.push_back(val);
    }
    else
    {
        cache.push_front(val);
    }
}

void pop()
{
    if (is_front)
    {
        cache.pop_front();
    }
    else
    {
        cache.pop_back();
    }
}

int front()
{
    if (is_front)
    {
        return cache.front();
    }
    else
    {
        return cache.back();
    }
}

void flip()
{
    is_front = !is_front;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        is_front = 1;

        string s;
        cin >> s;

        int len;
        cin >> len;

        char _;
        cin >> _;

        for (int i = 0; i < len; i++)
        {
            int cur;
            cin >> cur;
            push(cur);
            if (i + 1 < len)
            {
                cin >> _;
            }
        }
        cin >> _;

        bool is_err = false;
        for (char c : s)
        {
            if (c == 'R')
            {
                flip();
            }
            else
            {
                if (cache.empty())
                {
                    is_err = true;
                    break;
                }
                pop();
            }
        }

        if (is_err)
        {
            cout << "error"
                 << "\n";
            while (!cache.empty())
                cache.pop_front();
            continue;
        }

        cout << "[";
        while (!cache.empty())
        {
            cout << front();
            pop();
            if (!cache.empty())
            {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}