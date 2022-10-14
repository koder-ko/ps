#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int line_count;
pair <int, int> line[100];
int len[100] = {0, };


bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> line_count;

    for(int i = 0; i < line_count; i++){
        cin >> line[i].first;
        cin >> line[i].second;    
    }

    sort(line, line + line_count, compare);

    int max_len = 0;

    for(int n = 0; n < line_count; n++){
        len[n] = 1;
        for(int m = 0; m < n; m++){
            if(line[m].second < line[n].second){
                len[n] = max(len[n], len[m] + 1);
            }
        }

        max_len = max(len[n], max_len);
    }

    cout << line_count - max_len;
}