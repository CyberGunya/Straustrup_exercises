//
//  main.cpp
//  Swap (10)
//
//  Created by Serhii Hlushenkov on 25.03.2022.
//

#include <iostream>
using namespace std;

void swap1(int* first, int* second)
{
    int temp;
    temp=*first;
    *first=*second;
    *second=temp;
}

void swap2(int& first, int& second)
{
    int temp;
    temp=first;
    first=second;
    second=temp;
}

int main() {
    int x=1;
    int y=2;
    cout<<"\n"<<"First swap:"<<"\n";
    swap1(&x, &y);
    cout<<"x = "<<x<<"\n";
    cout<<"y = "<<y<<"\n";
    cout<<"\n"<<"Second swap:"<<"\n";
    swap2(x, y);
    cout<<"x = "<<x<<"\n";
    cout<<"y = "<<y<<"\n";
    return 0;
}
