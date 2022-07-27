//
//  main.cpp
//  Months and Days (12)
//
//  Created by Serhii Hlushenkov on 26.03.2022.
//

#include <iostream>
using namespace std;

struct month
{
    string name;
    short days;
};

void print1(string months[12], short days[12])
{
    for(int i=0;i<12;i++)
    {
        cout<<months[i]<<" : "<<days[i]<<" days"<<"\n";
    }
}

void print2(month arr[])
{
    for(int i=0;i<12;i++)
    {
        cout<<arr[i].name<<" : "<<arr[i].days<<" days"<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    string months[12]={"January","February","March","April","May","June",
                    "July","August","September","October","November","December"};
    short days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    //print1(months,days);
    
    month array[12]={{"December",31},{"February",28},{"March",31},{"April",30},
        {"May",31},{"June",30},{"July",31},{"August",31},{"September",30},
        {"October",31},{"November",30},{"December",31}};
    print2(array);
    return 0;
}
