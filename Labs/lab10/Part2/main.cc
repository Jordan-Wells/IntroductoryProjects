#include <queue>
#include "chore.h"

using namespace std;
int main(){
    priority_queue<Chore> q;
    Chore tmp;
    for(size_t i = 0; i < 5; i++){
        tmp.input();
        q.push(tmp);
        cin.ignore();
        cin.clear();
    }
    while(!q.empty()){
        tmp = q.top();
        tmp.output();
        //tmp.output();
        q.pop();
    }

    return 0;
}