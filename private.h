/**
  ******************************************************************************
  *@file      private.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _PRIVATE_H
#define _PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif  

/* Includes ------------------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/



/* Exported types ------------------------------------------------------------*/ 
typedef struct _public {
    // public value
    int a;
    int b;
    int c;

    // public function
    int (*add)(int add1, int add2);
    
    // Placeholder
    void* _Placeholder;
} Public;


/* Exported functions --------------------------------------------------------*/
Public* private_new(int a, int b);

int GetVal1(Public const *p);

int GetVal2(Public const *p);

void ResetVal1(Public* p, int newval);

void ResetVal2(Public* p, int newval);

int Private_Add_example(Public* p);

#ifdef __cplusplus
}
#endif

#endif /* _PRIVATE_H */
