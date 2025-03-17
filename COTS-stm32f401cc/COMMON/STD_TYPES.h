#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char 	       u8;
typedef unsigned short int     u16;
typedef unsigned long int 	   u32;
typedef unsigned long long     u64;   

typedef signed char 	       s8;
typedef signed short int       s16;
typedef signed long int        s32;
typedef signed long long       s64;   

typedef unsigned char *	       pu8;
typedef unsigned short int *   pu16;
typedef unsigned long int *    pu32;
typedef unsigned long long *   pu64;

typedef signed char *	        ps8;
typedef signed short int *      ps16;
typedef signed long int *       ps32;
typedef signed long long *      ps64;

typedef float                  f32;
typedef double                 f64;
typedef long double            f128;

#define NULL  ((void *) 0)

typedef struct{
	pu8 Data;
	u32	Size;
	u32 Used;
}Buffer_t;

#endif