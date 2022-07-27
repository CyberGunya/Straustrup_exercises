//
//  main.cpp
//  Double type (7)
//
//  Created by Serhii Hlushenkov on 24.03.2022.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string before_to_bit(long int x)
{
    string temp="";
    if(x==0)
    {
        return "0";
    }
    while (x!=1)
    {
        temp+=to_string(x%2);
        x=x/2;
    }
    temp+="1";
    string result="";
    for(long int i=temp.length()-1;i>=0;i--)
    {
        result+=temp[i];
    }
    return result;
}

string after_to_bit(double x, long num)
{
    string result="";
    for(int i=0;i<num;i++)
    {
        result+=to_string(int(x*2.0));
        if(x*2>=1)
        {
            x=(x*2.0)-1;
        }
        else
        {
            x=x*2.0;
        }
    }
    return result;
}

double st_to_real(string first, string second)
{
    double rez=0;
    int count=0;
    int pow=2;
    string total=first+second;
    int i=0;
    while(total[i]=='0')
    {
        i++;
        count--;
    }
    i++;
    if(count==0)
    {
        int j=0;
        while(first[j]=='0')
        {
            j++;
        }
        count=int(first.length())-1-j;
    }
    for(i;i<total.length()-1;i++)
    {
        if(total[i]=='1')
        {
            rez+=1.0/double(pow);
            pow=pow*2;
        }
        else
        {
            pow=pow*2;
        }
    }
    cout<<"Основа: 2"<<"\n";
    cout<<"Порядок: "<<count<<"\n";
    return 1.0+rez;
}

void manteece(double x)
{
    long before = long(x);
    if(before<0)
    {
        before=before*(-1);
    }
    string main="";
    string second="";
    main=before_to_bit(before);
    if(x<0)
    {
        second=after_to_bit(-x-double(before),31-(main.length()-2));
    }
    else
    {
        second=after_to_bit(x-double(before),31-(main.length()-2));
    }
    double rez=st_to_real(main,second);
    cout<<"Мантиса: ";
    if(x<0)
    {
        cout<<"-";
    }
    cout<<std::setprecision(15)<<rez<<"\n";
}


int main(int argc, const char * argv[]) {
    double insert;
    cout<<"Введіть значення: ";
    cin>>insert;
    manteece(insert);
    return 0;
}
