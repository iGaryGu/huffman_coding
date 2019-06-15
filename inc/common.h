#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include <stdlib.h>

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

#endif
