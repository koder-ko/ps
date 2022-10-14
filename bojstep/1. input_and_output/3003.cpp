#include <iostream>

using namespace std;

int list[6] = {1, 1, 2, 2, 2, 8};

int main(){
    for(int i = 0; i < 6; i++){
        int num;
        cin >> num;
        cout << list[i] - num;
        if(i != 5){
            cout << " ";
        }
    }
}