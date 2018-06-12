#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *pf;

    if((pf = fopen("assembler_code.txt", "r")) == NULL)       // Открытие файла с исходным кодом
    {
        fprintf(stderr, "file open error");
        exit(EXIT_FAILURE);
    }

    return 0;
}