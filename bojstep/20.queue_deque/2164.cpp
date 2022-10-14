#include <iostream>
#include <queue>

using namespace std;

queue<int> card;

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        card.push(i);
    }
    int last;
    while(!(card.empty())){
        last = card.front();

        card.pop();
        card.push(card.front());
        card.pop();
    }

    cout << last;
}