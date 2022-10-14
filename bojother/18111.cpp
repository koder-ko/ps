#include <iostream>

using namespace std;

int N, M, B;
int tower[257] = {};
int min_layer, max_layer;

pair<int, int> flattern(int layer, int block, int blocks2fill){
    pair<int, int> return_val;

    if(blocks2fill == 0){
        return_val.first = 0;
        return_val.second = layer;
        return return_val;
    }
    if(layer == 0){
        return_val.first = -1;
        return_val.second = -1;
        return return_val;
    }
    pair<int, int> compare_val;

    compare_val = flattern(layer-1, block + tower[layer], blocks2fill - ((N * M) - tower[layer]));
    if(compare_val.first == -1){
        if(block < blocks2fill){
            return_val.first = -1;
            return_val.second = -1;
            return return_val;
        }
        else{
            return_val.first = blocks2fill;
            return_val.second = layer;
        }
    }
    else if(block >= blocks2fill){
        if(blocks2fill <= compare_val.first + tower[layer] * 2){
            return_val.first = blocks2fill;
            return_val.second = layer;
        }
        else{
            return_val.first = compare_val.first + tower[layer] * 2;
            return_val.second = compare_val.second;
        }
    }
    else{
        return_val.first = compare_val.first + tower[layer] * 2;
        return_val.second = compare_val.second;
    }
    return return_val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> B;

    min_layer = 256;
    max_layer = 0;
    for(int i = 0; i < N; i++){
        for(int k = 0; k < M; k++){
            int cur = 0;
            cin >> cur;
            max_layer = max(max_layer, cur);
            min_layer = min(min_layer, cur);
            for(int s = 1; s <= cur; s++){
                tower[s] += 1;
            }
        }
    }

    int blocks2fill = 0;

    for(int step = 1; step <= max_layer; step++){
        blocks2fill += (N * M) - tower[step];
    }

    pair<int, int> ans = flattern(max_layer, B, blocks2fill);
    cout << ans.first << " " << ans.second;
}