#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char *replace(char *str, char const *from, char const *to);

char *replace(char *str, char const *from, char const *to)
{
    char* ptr;
    char* second_part_str;
    int from_len, to_len, str_len;

    
    str_len = strlen(str);
    from_len = strlen(from);
    to_len = strlen(to);
    second_part_str = (char*) malloc((str_len + 1) * sizeof(char));

    ptr = str;
    while ((ptr = strstr(ptr, from)) != NULL)
    {
        //ptr = strstr(ptr, from);
        strcpy(second_part_str, ptr + from_len);
        *ptr = '\0';
        strcat(str, to);
        strcat(str, second_part_str);
        ptr += to_len;
    }

    free(second_part_str);
    return str;
}

int main() {

    char str[] =  "Hello, %username, how are you, %username";
    char from[] =  "%username";
    char to[] =  "Eric, the Blood Axe";
    printf("%s", replace(str, from, to));
    return 0;
}
