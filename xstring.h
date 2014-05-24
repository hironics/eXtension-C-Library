#ifndef _XSTRING_H
#define _XSTRING_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>


void str_strip(char * str, int len);

void str_lower(char * str);

void str_upper(char * str);

int str_startswith(char * stra, char * strb);

int str_endswith(char * left, char * right);

#endif
