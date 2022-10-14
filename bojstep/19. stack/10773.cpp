#include <iostream>
#include <stack>

using namespace std;

stack<int> numbers;

int main(){
    int K;
    cin >> K;
    while(K--){
        int num;
        cin >> num;
        if(num == 0){
            numbers.pop();
            continue;
        }
        numbers.push(num);
    }

    int sum = 0;
    while(!numbers.empty()){
        sum += numbers.top();
        numbers.pop();
    }

    cout << sum;

}