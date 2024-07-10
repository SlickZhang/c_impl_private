#include "private.h"
#include <stdlib.h>
#include <stdio.h>

int public_add(int a, int b)
{
    return a+b;
}

int main()
{
    Public *p = private_new(0,2);

    p->add = public_add;

    // public value, can be accessed directly
    p->a = 3;
    p->b = 4;
    p->c = 5;

    // private value, can not be accessed
    // p->val1 = 9; 

    printf("old val1: %d\n", GetVal1(p));
    ResetVal1(p, 1);
    printf("new val1: %d\n", GetVal1(p));
    printf("val2:     %d\n", GetVal2(p));
    printf("a   :     %d\n", p->a);
    printf("b   :     %d\n", p->b);
    printf("c   :     %d\n", p->c);

    printf("public  add: %d\n", p->add(6, 7));

    printf("private add: %d\n", Private_Add_example(p));

    return 0;
}