#include <iostream>
#include <string>
using namespace std;

void reversing(string &s,int start,int end);

 int main(){
    string s;
    int start, end;
    cout<<"Enter a string:";
    getline(cin,s);
    cout<<"Now enter two numbers that are within the bounds of the string.";
    cin>>start>>end;
    cout<<"This is how your words look now:\n";
    reversing(s,start,end);
    cout<<s<<endl;
    return 0;
}

void reversing(string &s,int start,int end){
    if(end >= s.size() || start >= s.size()){
        cout << "Values are too large for the array\n";
        return;
    }

    if(start < end){
        reversing(s, start+1, end-1);
        char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    }
    

    return;
}