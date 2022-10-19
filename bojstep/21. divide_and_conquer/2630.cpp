#include <iostream>

using namespace std;

int paper[128][128];
int blue = 0, white = 0;
int N;

void dq(int x1, int y1, int x2, int y2){

    if(x1 == x2 && y1 == y2){
        if(paper[x1][y1] == 1){
            blue++;
        }
        else{
            white++;
        }
        return;
    }

    int check = paper[x1][y1];
    for(int x = x1; x <= x2; x++){
        for(int y = y1; y <= y2; y++){
            if(check != paper[x][y]){
                int dist = (x2 - x1 + 1) / 2 - 1;
                dq(x1, y1, x1 + dist, y1 + dist);
                dq(x1 + dist + 1, y1, x2, y2 - dist - 1);
                dq(x1, y1 + dist + 1, x2 - dist - 1, y2);
                dq(x2 - dist, y2 - dist, x2, y2);
                return;
            }
        }
    }

    if(check == 1){
        blue++;
    }
    else{
        white++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            cin >> paper[x][y];
        }
    }
    dq(0, 0, N-1, N-1);
    cout << white << "\n" << blue;
}