//
//  date.h
//  class friend (9)
//
//  Created by Serhii Hlushenkov on 10.11.2022.
//

#ifndef date_h
#define date_h

class date{
    int month, day, year;
    bool leap;
    friend void set(date&, int, int, int);
    friend void get(date, int*, int*, int*);
    friend void next(date&);
    friend void print(const date);
};

void set(date& cur, int m, int d, int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)
            {
                cur.leap=true;
            }
            else
            {
                cur.leap=false;
            }
        }
        else
        {
            cur.leap=true;
        }
    }
    else
    {
        cur.leap=false;
    }
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(d<1||d>31)
            {
                std::cout<<"Wrong date!"<<"\n";
            }
            else
            {
                cur.month=m;
                cur.day=d;
                cur.year=y;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(d<1||d>30)
            {
                std::cout<<"Wrong date!"<<"\n";
            }
            else
            {
                cur.month=m;
                cur.day=d;
                cur.year=y;
            }
            break;
        case 2:
            if(cur.leap)
            {
                if(d<1||d>29)
                {
                    std::cout<<"Wrong date!"<<"\n";
                }
                else
                {
                    cur.month=m;
                    cur.day=d;
                    cur.year=y;
                }
            }
            else
            {
                if(d<1||d>28)
                {
                    std::cout<<"Wrong date!"<<"\n";
                }
                else
                {
                    cur.month=m;
                    cur.day=d;
                    cur.year=y;
                }
            }
            break;
        default:
            break;
    }
}

void get(date current, int* m, int* d, int* y)
{
    m=&current.month;
    d=&current.day;
    y=&current.year;
}

void next(date& cur)
{
    switch (cur.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(cur.day==31)
            {
                cur.day=1;
                if(cur.month==12)
                {
                    cur.month=1;
                    cur.year++;
                }
                else
                {
                    cur.month++;
                }
            }
            else
            {
                cur.day++;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(cur.day==30)
            {
                cur.day=1;
                cur.month++;
            }
            else
            {
                cur.day++;
            }
            break;
        case 2:
            if(cur.leap)
            {
                if(cur.day==29)
                {
                    cur.day=1;
                    cur.month++;
                }
                else
                {
                    cur.day++;
                }
            }
            else
            {
                if(cur.day==28)
                {
                    cur.day=1;
                    cur.month++;
                }
                else
                {
                    cur.day++;
                }
            }
            break;
        default:
            break;
    }
}

void print(const date cur)
{
    std::cout<<"Date is: "<<cur.month<<"/"<<cur.day<<"/"<<cur.year<<"\n";
}

#endif /* date_h */
