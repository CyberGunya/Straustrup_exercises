//
//  main.cpp
//  Histogram (7)
//
//  Created by Serhii Hlushenkov on 08.11.2022.
//

#include <iostream>
#include <random>

class histogram {
    double left, right;
    int number;
    int* hist;
    int out_of_b;
    double step;
    int total;
public:
    histogram(double l, double r, int n);
    ~histogram();
    void take_num(double x);
    void output();
};

histogram::histogram(double l, double r, int n)
{
    left=l;
    right=r;
    number=n;
    out_of_b=0;
    total=0;
    hist = new int[number];
    for(int i=0;i<number;i++)
    {
        hist[i]=0;
    }
    step = (right-left)/number;
}

histogram::~histogram()
{
    delete hist;
}

void histogram::take_num(double x)
{
    if(x<left||x>right)
    {
        out_of_b++;
        total++;
    }
    else
    {
        double temp = left;
        int counter=0;
        while(temp<=x)
        {
            temp+=step;
            counter++;
        }
        hist[--counter]++;
        total++;
    }
}

void histogram::output()
{
    int* result = new int[number];
    for(int i=0;i<number;i++)
    {
        result[i]=(int)(hist[i]*100/total);
        std::cout<<left+i*step<<"\n"<<"\t";
        for(int j=0;j<result[i];j++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    std::cout<<right<<"\n\n"<<"Number of values out of bounds: "<<out_of_b<<" ("<<out_of_b*100/total<<"%)"<<"\n";
    
}

int main(int argc, const char * argv[]) {
    
    //uniform distribution
    //std::mt19937 gen32 (time(0));
    //std::uniform_real_distribution<double> dis(-0.5, 5.5);
    
    //normal distribution
    std::default_random_engine gen32(time(0));
    std::normal_distribution<double> dis(2.5,1.0);
    
    histogram hist(0,5,10);     //values from 0 to 5: 10 intervals
    for(int i=0;i<100000;i++)
    {
        hist.take_num(dis(gen32));
    }
    hist.output();
    return 0;
}
