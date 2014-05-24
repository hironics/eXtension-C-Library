#include <stdio.h>
#include <string.h>
#include <ctype.h>

void str_strip(char * str, int len)
{
    int i;
    char c;
    for(i=len-1; i>=0; i--){
        if(str[i]==' ' || str[i]=='\r'|| str[i]=='\t'|| str[i]=='\n')
            str[i] = '\0';
        else 
            break;
    }
}

void str_lower(char * str)
{
    int i;
    for(i=0; str[i]; i++){
        if(isupper(str[i])){
            str[i] = tolower(str[i]);
        }
    }
}

void str_upper(char * str)
{
    int i;
    for(i=0; str[i]; i++){
        if(islower(str[i])){
            str[i] = toupper(str[i]);
        }
    }
}

int str_startswith(char * stra, char * strb)
{
    int len = strlen(strb);
    return strncmp(stra, strb, len) == 0;
}

int str_endswith(char * left, char * right)
{
    int lena = strlen(left);
    int lenb = strlen(right);
    
    if(lenb > lena) return 0;
    
    return strcmp(left+(lena-lenb), right) == 0;
}
