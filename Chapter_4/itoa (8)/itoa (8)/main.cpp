//
//  main.cpp
//  itoa (8)
//
//  Created by Serhii Hlushenkov on 03.10.2022.
//

#include <iostream>

int pow(int val, int q)
{
    int rez=1;
    while(q-->1)
    {
        rez=rez*val;
    }
    return rez;
}

char* itoa (const int val)
{
    char* q = new char();
    char* rez = q;
    int counter = 0;
    int temp = val;
    while (temp>0)
    {
        temp=temp/10;
        counter++;
    }
    temp=val;
    int temp2=0;
    while (counter>0)
    {
        temp2=temp/pow(10,counter);
        if(temp2==0)
        {
            *q++=static_cast<char>('0');;
        }
        else
        {
            *q++=static_cast<char>(temp2);
        }
        temp=temp%pow(10,counter);
        counter--;
    }
    return rez;
}

int main(int argc, const char * argv[]) {
    int x;
    std::cin>>x;
    char* r = new char();
    r=itoa(x);
    while(*r!='\0')
    {
        std::cout<<(int)*r++<<"\n";
    }
    return 0;
}
