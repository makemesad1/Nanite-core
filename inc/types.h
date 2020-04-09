#ifndef MTX_BASE_TYPES_H
#define MTX_BASE_TYPES_H

/* BOOL >> TRUE | FALSE*/
typedef int bool;

/* 8 Bit integer */
typedef char int8_t;
typedef unsigned char uint8_t;

/* 16 Bit integer */
typedef short int16_t;
typedef unsigned short uint16_t;

/* 32 Bit integer */
typedef int int32_t;
typedef unsigned int uint32_t;

/* 64 Bit integer */
typedef long long int64_t;
typedef unsigned long long uint64_t;

/* Sizes */
typedef uint32_t size_t;  //usinged size_t
typedef int32_t  ssize_t; //signed size_t for error returns

/* Addressing */
typedef uint32_t paddr_t;

#endif