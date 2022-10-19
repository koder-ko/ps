#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> time_table[100000] = {};

bool compare(pair<int,int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> time_table[i].first >> time_table[i].second;
    }

    sort(time_table, time_table + N, compare);

    int len = 0;
    int end_min;
    for(int i = 0; i < N; i++){
        int start = time_table[i].first, end = time_table[i].second;
        if(i == 0){
            end_min = end;
            len = 1;
            continue;
        }
        if(start >= end_min){
            len++;
            end_min = end;
        }
        else if(len == 1 && end < end_min){
            end_min = end;
        }
    }

    cout << len;
}