#include "age.h"
static const float Price = 1.5;
float computePrice(int age, int tourist)
{
    int limitAge;
    int *plimit = &limitAge;
    recupAge(plimit);
    if (age > limitAge)
    {
        if (tourist)
            return Price * 2;
        return Price;
    }
    else
    {
        if (tourist)
            return Price;
        return Price / 2;
    }
}
