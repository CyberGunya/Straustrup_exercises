//
//  main.cpp
//  class friend (9)
//
//  Created by Serhii Hlushenkov on 09.11.2022.
//

#include <iostream>
#include <random>
#include "date.h"
#include "char_stack.h"
#include "intset.h"

int randint(int u)
{
    int r = rand();
    if(r<0)
        r = -r;
    return 1+r%u;
}

int main(int argc, const char * argv[]) {
    
    std::cout<<"Date example:"<<"\n";
    date today;
    set(today, 12, 31, 2022);
    print(today);
    next(today);
    print(today);
    std::cout<<"\n";
    
    std::cout<<"Char_stack example:"<<"\n";
    char_stack stack;
    alloc_mem(stack, 4);
    push(stack, '1');
    push(stack, '2');
    std::cout<<pop(stack)<<"\n";
    push(stack, '3');
    std::cout<<pop(stack)<<"\n"<<pop(stack)<<"\n\n";
    
    std::cout<<"intset example:"<<"\n";
    intset set;
    int count = 0;
    set_size(set, 5, 20);
    while (count<5)
    {
        int t = randint(20);
        if(member(set, t)==0)
        {
            insert(set, t);
            count++;
        }
    }
    print_in_order(set);
    return 0;
}
