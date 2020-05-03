#include <queue>
#include "chore.h"
#include <iostream>

using namespace std;
int main(){
    priority_queue<int> q;
    for(int i = 0; i < 5; i++){
        q.push(i);
    }
    for(int i = 0; i < 5; i++){
       cout << q.top();
       q.pop();
    }
}