#include <iostream>
#include <deque>

using namespace std;

deque<int> spin_q;
int memory[50];
int N, M;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> memory[i];
    }

    for (int k = 0; k < N; k++)
    {
        spin_q.push_back(k + 1);
    }

    int ans = 0;
    for (int j = 0; j < M; j++)
    {
        if (spin_q.front() == memory[j])
        {
            spin_q.pop_front();
            N--;
            continue;
        }

        int right = 0, left = N - 1;
        for (int l = 0; l < N; l++)
        {
            if (spin_q[l] == memory[j])
            {
                if (right <= left)
                {
                    spin_q.push_back(spin_q.front());
                    spin_q.pop_front();
                }
                else
                {
                    spin_q.push_front(spin_q.back());
                    spin_q.pop_back();
                }
                ans++;
                j--;
                break;
            }
            right++;
            left--;
        }
    }

    cout << ans;
}