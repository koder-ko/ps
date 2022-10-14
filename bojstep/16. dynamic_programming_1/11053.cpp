#include <iostream>

using namespace std;


int num;
int A[1000];
int len[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    // 입력 구간
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> A[i]; 
    }

    int maxlen = 0;

    // dp 구간
    for(int j = 0; j < num; j++){
        len[j] = 1;
        for(int k = 0; k < j; k++){
            if(A[k] < A[j]){
                len[j] = max(len[k] + 1, len[j]);
            }
        }

        if(maxlen < len[j]){
            maxlen = len[j];
        }
    }

    cout << maxlen;
}