#include <iostream>

using namespace std;

bool is_palindrome(int num)
{
    int d = 1;
    int i;
    int num_arr[5] = {-1, -1, -1, -1, -1};
    for (i = 0; num >= d; i++)
    {
        num_arr[i] = ((num % (10 * d)) - (num % d)) / d;
        d *= 10;
    }

    for (int j = 0; j < 5; j++)
    {
        if (num_arr[j] == -1)
        {
            break;
        }
        if (num_arr[j] != num_arr[i - 1 - j])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    while (true)
    {
        cin >> num;
        if (num == 0)
        {
            break;
        }
        if (is_palindrome(num))
        {
            cout << "yes"
                 << "\n";
        }
        else
        {
            cout << "no"
                 << "\n";
        }
    }
}