#include <iostream>

void print_stars(int n);
void see_stars(int count, int stop);

int main(){
    int n;
    std::cout<<"Enter a number between 1 and 30 and see the stars.\n";
    std::cin>>n;
    see_stars(1,n);
    return 0;
}

void print_stars(int n){
    for(size_t i = 0; i < n; ++i){
        std::cout << "*";
    }
    std::cout << std::endl;
    return;
}
void see_stars(int count, int stop){
    print_stars(count);
    count++;
    if(count < stop){
        see_stars(count, stop);
    }
    else if(count == stop){
        print_stars(count);
        print_stars(count);
    }
    count--;

    print_stars(count);
    return;
}