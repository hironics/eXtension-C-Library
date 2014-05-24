#ifndef __XSTRING_H__
#define __XSTRING_H__
/*
xstring library intends to extend current string.h
Currently, some string process functions are widely used across most of program

*/

/* strip trailing whitespace and newline characters from a string */
void str_strip(char * str, int len);

/* convert the characters in a string to lowercase */
void str_lower(char * str);
/* convert the characters in the string to uppercase */
void str_upper(char * str);

/* tests whether stra is starts with the string strb */
int str_startswith(char * stra, char * strb);

/* tests whether stra ends with the string strb */
int str_endswith(char * stra, char * strb);

#endif /* __XSTRING_H__ */
