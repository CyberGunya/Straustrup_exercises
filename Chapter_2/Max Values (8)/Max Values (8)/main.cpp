//
//  main.cpp
//  Max Values (8)
//
//  Created by Serhii Hlushenkov on 25.03.2022.
//

#include <iostream>
using namespace std;

int main()
{
    cout<<CHAR_MAX<<"\t"<<CHAR_MIN<<"\n";
    cout<<SHRT_MAX<<"\t"<<SHRT_MIN<<"\n";
    cout<<INT_MAX<<"\t"<<INT_MIN<<"\n";
    cout<<LONG_MAX<<"\t"<<LONG_MIN<<"\n";
    cout<<__FLT_MAX__<<"\t"<<__FLT_MIN__<<"\n";
    cout<<__DBL_MAX__<<"\t"<<__FLT_MIN__<<"\n";
    cout<<__LDBL_MAX__<<"\t"<<__LDBL_MIN__<<"\n";
    cout<<UINT_MAX<<"\t"<<"0"<<"\n";
    return 0;
}
