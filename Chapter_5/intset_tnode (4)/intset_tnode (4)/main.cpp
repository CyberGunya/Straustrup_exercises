//
//  main.cpp
//  intset_tnode (4)
//
//  Created by Serhii Hlushenkov on 03.11.2022.
//

#include <iostream>

void error (const char* s)
{
    std::cerr<<"set: "<<s<<"\n";
    exit(1);
}
struct tnode
{
    tnode(){prev=NULL; val=0; next=NULL;};
    tnode* prev;
    int val;
    tnode* next;
};

class nodeset{
    int cursize, maxsize;
    tnode* x;
public:
    nodeset(int m);
    ~nodeset();
    int member (tnode t) const;
    void insert (tnode t);
    void start (int& i) const {i=0;}
    int ok(int& i) const {return i<cursize;}
    tnode next(int& i) const {return x[i++];}
};

nodeset::nodeset(int m)
{
    cursize=0;
    maxsize=m;
    x = new tnode[m];
}

nodeset::~nodeset()
{
    delete x;
}

void nodeset::insert(tnode t)
{
    if(++cursize>maxsize) error("too much elements");
    int i=cursize-1;
    x[i]=t;
    while(i>0 && x[i-1].val>x[i].val)
    {
        tnode l = x[i];
        x[i]=x[i-1];
        x[i-1]=l;
        i--;
    }
    if(i>0)
    {
        x[i-1].next=&x[i];
        x[i].prev=&x[i-1];
    }
}

int nodeset::member(tnode t) const
{
    int l = 0;
    int u = cursize-1;
    while (l<=u)
    {
        int m = (l+u)/2;
        if(t.val<x[m].val)
            u = m-1;
        else if (t.val> x[m].val)
            l = m+1;
        else
            return 1;
    }
    return 0;
}

void print_in_order (nodeset* set)
{
    int var;
    set->start(var);
    while (set->ok(var)) std::cout<<set->next(var).val<<"\n";
}

int main(int argc, const char * argv[]) {
    if(argc != 2) error("only one number need to be input");
    int count = 0;
    int m = atoi(argv[1]);
    nodeset s(m);
    std::cout<<"You need to enter a set of "<< m <<" values"<<"\n";
    while (count<m)
    {
        tnode temp;
        std::cout<< "Enter your value: ";
        std::cin>>temp.val;
        if(s.member(temp)==0)
        {
            s.insert(temp);
            count++;
            std::cout<<m-count<<" values left"<<"\n";
        }
        else
        {
            std::cout<<"Such value already exists in set, enter another one"<<"\n";
        }
    }
    std::cout<<"You entered those values:"<<"\n";
    print_in_order(&s);
    return 0;
}
