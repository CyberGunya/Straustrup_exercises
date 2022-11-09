//
//  main.cpp
//  Distributions (8)
//
//  Created by Serhii Hlushenkov on 09.11.2022.
//

#include <iostream>
#include <random>
#include <cmath>

std::mt19937 gen32 (time(0));
std::uniform_real_distribution<double> dis(0, 1);

class uniform{
    double left, right;
public:
    uniform(double a, double b);
    double draw();
};

uniform::uniform(double a, double b)
{
    if(a>b)
    {
        std::cout<<"Second value must be greater! Values will be switched."<<"\n";
        left=b;
        right=a;
    }
    else
    {
        left=a;
        right=b;
    }
}

double uniform::draw()
{
    return left+dis(gen32)*(right-left);
}


class normal{
    double alpha, sigma;
public:
    normal(double a, double s);
    double draw();
};

normal::normal(double a, double s)
{
    alpha=a;
    sigma=s;
}

double normal::draw()
{
    double x = sqrt(-2*log(dis(gen32)))*sin(2*M_PI*dis(gen32));
    return alpha+sigma*x;
}

class exponential{
    double lambda;
public:
    exponential(double l);
    double draw();
};

exponential::exponential(double l)
{
    lambda=l;
}

double exponential::draw()
{
    return log(1-dis(gen32))/(-lambda);
}

int main(int argc, const char * argv[]) {
    
    uniform first(5,10);
    normal second(7, 1.5);
    exponential third(1.5);
    
    std::cout<<first.draw()<<"\n"<<second.draw()<<"\n"<<third.draw()<<"\n";
    return 0;
}
