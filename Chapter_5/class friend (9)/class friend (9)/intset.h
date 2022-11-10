//
//  intset.h
//  class friend (9)
//
//  Created by Serhii Hlushenkov on 10.11.2022.
//

#ifndef intset_h
#define intset_h

class intset{
    int cursize, maxsize;
    int* x;
    friend void set_size(intset& cur, int m, int n);
    friend int member(intset cur, int t);
    friend void insert(intset& cur, int t);
    friend void start (intset cur, int& i);
    friend int ok(intset cur, int& i);
    friend int next(intset cur, int& i);
};

void set_size(intset& cur, int m, int n)
{
    if(m<1||n<m)
    {
        std::cout<<"Error! Size is unacceptable"<<"\n";
    }
    cur.cursize=0;
    cur.maxsize=m;
    cur.x=new int[cur.maxsize];
}

void insert(intset& cur, int t)
{
    if(++cur.cursize > cur.maxsize)
    {
        std::cout<<"Error! Too much elements!"<<"\n";
    }
    else
    {
        int i = cur.cursize-1;
        cur.x[i]=t;
        while(i>0 && cur.x[i-1]>cur.x[i])
        {
            int t = cur.x[i];
            cur.x[i] = cur.x[i-1];
            cur.x[i-1] = t;
            i--;
        }
    }
}

int member(intset cur, int t)
{
    int l=0;
    int u = cur.cursize-1;
    while(l<=u)
    {
        int m = (l+u)/2;
        if(t < cur.x[m])
        {
            u=m-1;
        }
        else if (t > cur.x[m])
        {
            l = m+1;
        }
        else
            return 1;
    }
    return 0;
}

void start(intset cur, int& i)
{
    i=0;
}

int ok(intset cur, int& i)
{
    return i<cur.cursize;
}

int next(intset cur, int& i)
{
    return cur.x[i++];
}

void print_in_order(intset cur)
{
    int var;
    start(cur, var);
    while(ok(cur,var))
    {
        std::cout<<next(cur, var)<<"\n";
    }
}

#endif /* intset_h */
