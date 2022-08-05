//
//  main.cpp
//  atoi (11)
//
//  Created by Serhii Hlushenkov on 05.08.2022.
//

#include <iostream>

int pow(const int val, const int pow)
{
    int rez=1;
    for(int i=0;i<pow;i++)
    {
        rez*=val;
    }
    return rez;
}

int atoi(const char val[])
{
    const char* p = val;
    const char* start = val;
    bool minus=false;
    bool oct=false;
    bool hex=false;
    int rez=0;
    if(*p=='-')
    {
        *p++;
        *start++;
        minus=true;
    }
    if(*p=='0')
    {
        *p++;
        *start++;
        oct=true;
        if(*p=='x')
        {
            *p++;
            *start++;
            oct=false;
            hex=true;
        }
    }
    if(hex)
    {
        while (*p!='\0')
        {
            int len = (int)strlen(p)-1;
            switch (*p) {
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                    rez+=((int)*p++-55)*pow(16, len--);
                    break;
                default:
                    rez+=((int)*p++-48)*pow(16, len--);
                    break;
            }
        }
    }
    else
    {
        if(oct)
        {
            int len = (int)strlen(p)-1;
            while(*p!='\0')
            {
                if((int)*p>55)
                {
                    std::cout<<"ERROR! Will be converted as decimal"<<"\n";
                    p=start;
                    rez=0;
                    while(*p!='\0')
                    {
                        rez*=10;
                        rez+=(int)*p++-48;
                    }
                }
                else
                {
                    rez+=((int)*p++-48)*pow(8, len--);
                }
            }
        }
        else
        {
            while(*p!='\0')
            {
                rez*=10;
                rez+=(int)*p++-48;
            }
        }
    }
    if(minus)
    {
        rez=rez*-1;
    }
    return rez;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char* insert = new char();
    std::cin>>insert;
    std::cout <<atoi(insert)<<"\n";
    return 0;
}
