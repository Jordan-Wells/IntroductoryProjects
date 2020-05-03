#include <iostream>
using namespace std;

void convert_to_base(int n, int base);

int main(){
    int num;
    cout<<"Please input an int decimal number:";

    cin>>num;
    cout<<"\nThis number in base 2 is:";
    convert_to_base(num, 2); // shows the number to base 2
    cout<<"\nThis number in base 3 is:";
    convert_to_base(num, 3); // shows the number to base 3
    cout<<"\nThis number in base 7 is:";
    convert_to_base(num, 7);
    return 0;
}

void convert_to_base(int n, int base){
    if(n / base != 0){
        convert_to_base(n / base, base);
    }
    cout << n % base;
    return;
}