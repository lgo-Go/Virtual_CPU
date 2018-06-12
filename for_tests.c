#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *str = "frffr";
    str[0] = 'a';
    // *str = 'b';
    printf("%c\n", *str);
    return 0;
}