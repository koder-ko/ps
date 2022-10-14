#include <iostream>
#include <algorithm>

using namespace std;

int down[1000] = {};
int up[1000] = {};
int A[1000];
int A_len;
int answer = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 구간
    cin >> A_len;
    for (int i = 0; i < A_len; i++)
    {
        cin >> A[i];
    }


    for(int j = 0; j < A_len; j++){
        for(int k = 0; k < j; k++){
            if(A[k] < A[j]){
                down[j] = max(down[k] + 1, down[j]);
            }
        }
    }

    for(int j = A_len - 1; j >= 0; j--){
        for(int k = A_len - 1; k > j; k--){
            if(A[k] < A[j]){
                up[j] = max(up[k] + 1, up[j]);
            }
        }
    }

    for (int b = 0; b < A_len; b++)
    {

        if (answer < down[b] + up[b] + 1)
        {
            answer = down[b] + up[b] + 1;
        }
    }

    cout << answer;
}