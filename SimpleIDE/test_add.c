/*
Test Add Function.c
*/
#include "simpletools.h"
int subtract(int a, int b);

int main()
{
int rslt = subtract(2, 3);
print("val = %d\n", rslt);
}

int subtract(int a, int b)
{
return a - b;
}