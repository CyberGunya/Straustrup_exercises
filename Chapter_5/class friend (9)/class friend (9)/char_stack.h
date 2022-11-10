//
//  char_stack.h
//  class friend (9)
//
//  Created by Serhii Hlushenkov on 10.11.2022.
//

#ifndef char_stack_h
#define char_stack_h

class char_stack {
    int size;
    char* top;
    char* s;
    friend void alloc_mem(char_stack& cur, int sz);
    friend void push(char_stack& cur, char c);
    friend char pop(char_stack& cur);
};

void alloc_mem(char_stack& cur, int sz)
{
    cur.size=sz;
    cur.top=cur.s=new char[sz];
}

void push(char_stack& cur, char c)
{
    *cur.top++=c;
}

char pop(char_stack& cur)
{
    return *--cur.top;
}

#endif /* char_stack_h */
