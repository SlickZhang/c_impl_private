/**
  ******************************************************************************
  *@file      private.c
  *@author    hongyu zhang (zhy_5262@163.com)
  *@brief     
  ******************************************************************************
  *@date      2024-07-10
  *@version   0.1
  *@copyright Copyright (c) 2024 
  *
  *All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "private.h"
#include <stdlib.h>

/* Private typedef -----------------------------------------------------------*/
typedef struct _pri_internal {
    union 
    {
        Public public;
    };

    // private value
    int val1;
    int val2; 
    
    // private function
    int (*add)(struct _pri_internal* self, int add1, int add2);

} Private;
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static int private_add(struct _pri_internal* self, int a, int b)
{
    return self->val1 + self->val2 + a + b;
}
/* Private variables ---------------------------------------------------------*/

/* public functions ---------------------------------------------------------*/
Public* private_new(int a, int b)
{
    Private *p = (Private*)malloc(sizeof(Private));
    p->val1 = a;
    p->val2 = b;
    p->add  = private_add;

    return &p->public;
}

int GetVal1(Public const *p)
{
    return ((Private*)p)->val1;
}

int GetVal2(Public const *p)
{
    return ((Private*)p)->val2;
}

void ResetVal1(Public * p, int newval)
{
    ((Private*)p)->val1 = newval;
}

void ResetVal2(Public* p, int newval)
{
    ((Private*)p)->val2 = newval;
}

int Private_Add_example(Public* p)
{
    return ((Private*)p)->add((Private*)p, 1, 1);
}
