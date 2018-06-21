#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i_comand = 0;                                         // > Счётчики символов в комаде и аргументах
    int i_argument_1 = 0;
    int i_argument_2 = 0;                                     // <
    int size_comand = 1;                                      // > Размеры строк, в которые сохраняются команда и два аргумента
    int size_argument_1 = 1;
    int size_argument_2 = 1;                                  // <
    char comand[size_comand];
    char argument_1[size_argument_1];
    char argument_2[size_argument_2];
    FILE *pf;

    int memory[256] = {0};
    int reg_a, reg_b, reg_c, reg_d,
        carry_flag, zero_flag,
        *stack_pointer, *instruction_pointer;


    if((pf = fopen("assembler_code.txt", "r")) == NULL)       // Открытие файла с исходным кодом
    {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    stack_pointer = & memory[231];
    instruction_pointer = memory;

    while(feof(pf) == 0)
    {
        while((comand[i_comand] = getc(pf)) != ' ')                                           // > Расчленяем строку из исходного кода на команду, аргумент 1 и аргумент 2, 
        {                                                                                     //   и записываем их в отдельные строки
            if(comand[i_comand] == EOF)
                break;
            ++i_comand;
            ++size_comand;
        }
        comand[i_comand] = '\0';

        while((argument_1[i_argument_1] = getc(pf)) != ' ')
        {
                if(argument_1[i_argument_1] == EOF || argument_1[i_argument_1] == '\n')
                    break;
                ++i_argument_1;
                ++size_argument_1;
        }

        if(argument_1[i_argument_1] != '\n')
        {
            while((argument_2[i_argument_2] = getc(pf)) != ' ')
            {
                if(argument_2[i_argument_2] == EOF || argument_2[i_argument_2] == '\n')
                    break;
                ++i_argument_2;
                ++size_argument_2;
            }
            argument_2[i_argument_2] = '\0';
        }

        argument_1[i_argument_1] = '\0';
                                                                                              // <


        if(strcmp(comand, "MOV") == 0)                                                        // > Команда MOV
        {
            if(strcmp(argument_1, "A") == 0)                                              // > Запись в регистр А
            {
                if(strcmp(argument_2, "B") == 0)
                    reg_a = reg_b;
                else if(strcmp(argument_2, "C") == 0)
                    reg_a = reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    reg_a = reg_d;
                else if(argument_2[0] == '[')
                    reg_a = memory[atoi(argument_2 + 1)];
                else
                    reg_a = atoi(argument_2);                                             // <
            }
            else if(strcmp(argument_1, "B") == 0)                                         // > Запись в регистр В
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_b = reg_a;
                else if(strcmp(argument_2, "C") == 0)
                    reg_b = reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    reg_b = reg_d;
                else if(argument_2[0] == '[')
                    reg_b = memory[atoi(argument_2 + 1)];
                else
                    reg_b = atoi(argument_2);                                             // <
            }
            else if(strcmp(argument_1, "C") == 0)                                         // > Запись в регистр С
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_c = reg_a;
                else if(strcmp(argument_2, "B") == 0)
                    reg_c = reg_b;
                else if(strcmp(argument_2, "D") == 0)
                    reg_c = reg_d;
                else if(argument_2[0] == '[')
                    reg_c = memory[atoi(argument_2 + 1)];
                else
                    reg_c = atoi(argument_2);                                             // <
            }
            else if(strcmp(argument_1, "D") == 0)                                         // > Запись в регистр D
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_d = reg_a;
                else if(strcmp(argument_2, "B") == 0)
                    reg_d = reg_b;
                else if(strcmp(argument_2, "C") == 0)
                    reg_d = reg_c;
                else if(argument_2[0] == '[')
                    reg_d = memory[atoi(argument_2 + 1)];
                else
                    reg_d = atoi(argument_2);                                             // <
            }
            else if(argument_1[0] == '[')                                                 // > Запись по адресу
            {
                if(strcmp(argument_2, "A") == 0)
                    memory[atoi(argument_1 + 1)] = reg_a;
                else if(strcmp(argument_2, "B") == 0)
                    memory[atoi(argument_1 + 1)] = reg_b;
                else if(strcmp(argument_2, "C") == 0)
                    memory[atoi(argument_1 + 1)] = reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    memory[atoi(argument_1 + 1)] = reg_d;
                else if(argument_2[0] == '[')
                    memory[atoi(argument_1 + 1)] = memory[atoi(argument_2 + 1)];
                else
                    memory[atoi(argument_1 + 1)] = atoi(argument_2);                      // <
            }
        }                                                                                     // < Комадна MOV

        if(strcmp(comand, "INC") == 0)                                                        // > Команда INC
        {
            if(strcmp(argument_1, "A") == 0)
                ++reg_a;
            else if(strcmp(argument_1, "B") == 0)
                ++reg_b;
            else if(strcmp(argument_1, "C") == 0)
                ++reg_c;
            else if(strcmp(argument_1, "D") == 0)
                ++reg_d;
            printf("%c\n", argument_1[i_argument_1]);
        }                                                                                     // <

        if(strcmp(comand, "DEC") == 0)                                                        // > Команда DEC
        {
            if(strcmp(argument_1, "A") == 0)
                --reg_a;
            else if(strcmp(argument_1, "B") == 0)
                --reg_b;
            else if(strcmp(argument_1, "C") == 0)
                --reg_c;
            else if(strcmp(argument_1, "D") == 0) 
                --reg_d;
        }                                                                                     // <

        if(strcmp(comand, "MUL") == 0)                                                        // > Команда MUL(умножение)
        {
            if(strcmp(argument_1, "A") == 0)
                reg_a *= reg_a;
            else if(strcmp(argument_1, "B") == 0)
                reg_a *= reg_b;
            else if(strcmp(argument_1, "C") == 0)
                reg_a *= reg_c;
            else if(strcmp(argument_1, "D") == 0) 
                reg_a *= reg_d;
            else if(argument_1[0] == '[')
                reg_a *= memory[atoi(argument_1 + 1)];
            else
                reg_a *= atoi(argument_1);
        }                                                                                     // <

        if(strcmp(comand, "DIV") == 0)                                                        // > Команада DIV(деление)
        {
            if(strcmp(argument_1, "A") == 0)
                reg_a /= reg_a;
            else if(strcmp(argument_1, "B") == 0)
                reg_a /= reg_b;
            else if(strcmp(argument_1, "C") == 0)
                reg_a /= reg_c;
            else if(strcmp(argument_1, "D") == 0) 
                reg_a /= reg_d;
            else if(argument_1[0] == '[')
                reg_a /= memory[atoi(argument_1 + 1)];
            else
                reg_a /= atoi(argument_1);
        }                                                                                     // <

        if(strcmp(comand, "ADD") == 0)                                                        // > Команда ADD(сложение)
        {
                    if(strcmp(argument_1, "A") == 0)                                          // > сложение с регистром A
            {
                if(strcmp(argument_2, "B") == 0)
                    reg_a += reg_b;
                else if(strcmp(argument_2, "A") == 0)
                	reg_a += reg_a;
                else if(strcmp(argument_2, "C") == 0)
                    reg_a += reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    reg_a += reg_d;
                else if(argument_2[0] == '[')
                    reg_a += memory[atoi(argument_2 + 1)];
                else
                    reg_a += atoi(argument_2);                                                // <
            }
            else if(strcmp(argument_1, "B") == 0)                                             // > сложение с регистром B
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_b += reg_a;
                else if(strcmp(argument_2, "B") == 0)
                    reg_b += reg_b;
                else if(strcmp(argument_2, "C") == 0)
                    reg_b += reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    reg_b += reg_d;
                else if(argument_2[0] == '[')
                    reg_b += memory[atoi(argument_2 + 1)];
                else
                    reg_b += atoi(argument_2);                                                // <
            }
            else if(strcmp(argument_1, "C") == 0)                                             // > сложение с регистром C
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_c += reg_a;
                else if(strcmp(argument_2, "C") == 0)
                    reg_c += reg_c;
                else if(strcmp(argument_2, "B") == 0)
                    reg_c += reg_b;
                else if(strcmp(argument_2, "D") == 0)
                    reg_c += reg_d;
                else if(argument_2[0] == '[')
                    reg_c += memory[atoi(argument_2 + 1)];
                else
                    reg_c += atoi(argument_2);                                                // <
            }
            else if(strcmp(argument_1, "D") == 0)                                             // > сложение с регистром D
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_d += reg_a;
                else if(strcmp(argument_2, "D") == 0)
                    reg_d += reg_d;
                else if(strcmp(argument_2, "B") == 0)
                    reg_d += reg_b;
                else if(strcmp(argument_2, "C") == 0)
                    reg_d += reg_c;
                else if(argument_2[0] == '[')
                    reg_d += memory[atoi(argument_2 + 1)];
                else
                    reg_d += atoi(argument_2);                                                // <
            }
            else if(argument_1[0] == '[')                                                     // > сложение по адресу
            {
                if(strcmp(argument_2, "A") == 0)
                    memory[atoi(argument_1 + 1)] += reg_a;
                else if(strcmp(argument_2, "B") == 0)
                    memory[atoi(argument_1 + 1)] += reg_b;
                else if(strcmp(argument_2, "[") == 0)
                    memory[atoi(argument_1 + 1)] += memory[atoi(argument_2 + 1)];
                else if(strcmp(argument_2, "C") == 0)
                    memory[atoi(argument_1 + 1)] += reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    memory[atoi(argument_1 + 1)] += reg_d;
                else if(argument_2[0] == '[')
                    memory[atoi(argument_1 + 1)] += memory[atoi(argument_2 + 1)];
                else
                    memory[atoi(argument_1 + 1)] += atoi(argument_2);                         // <
            }
        }                                                                                     // <

        if(strcmp(comand, "SUB") == 0)                                                        // > Команда SUB(вычитание)
        {
                    if(strcmp(argument_1, "A") == 0)                                          // > вычитание из регистра A
            {
                if(strcmp(argument_2, "B") == 0)
                    reg_a -= reg_b;
                else if(strcmp(argument_2, "A") == 0)
                	reg_a -= reg_a;
                else if(strcmp(argument_2, "C") == 0)
                    reg_a -= reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    reg_a -= reg_d;
                else if(argument_2[0] == '[')
                    reg_a -= memory[atoi(argument_2 + 1)];
                else
                    reg_a -= atoi(argument_2);                                                // <
            }
            else if(strcmp(argument_1, "B") == 0)                                             // > вычитание из регистра B
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_b -= reg_a;
                else if(strcmp(argument_2, "B") == 0)
                    reg_b -= reg_b;
                else if(strcmp(argument_2, "C") == 0)
                    reg_b -= reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    reg_b -= reg_d;
                else if(argument_2[0] == '[')
                    reg_b -= memory[atoi(argument_2 + 1)];
                else
                    reg_b -= atoi(argument_2);                                                // <
            }
            else if(strcmp(argument_1, "C") == 0)                                             // > вычитание из регистра C
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_c -= reg_a;
                else if(strcmp(argument_2, "C") == 0)
                    reg_c -= reg_c;
                else if(strcmp(argument_2, "B") == 0)
                    reg_c -= reg_b;
                else if(strcmp(argument_2, "D") == 0)
                    reg_c -= reg_d;
                else if(argument_2[0] == '[')
                    reg_c -= memory[atoi(argument_2 + 1)];
                else
                    reg_c -= atoi(argument_2);                                                // <
            }
            else if(strcmp(argument_1, "D") == 0)                                             // > вычитание из регистра D
            {
                if(strcmp(argument_2, "A") == 0)
                    reg_d -= reg_a;
                else if(strcmp(argument_2, "D") == 0)
                    reg_d -= reg_d;
                else if(strcmp(argument_2, "B") == 0)
                    reg_d -= reg_b;
                else if(strcmp(argument_2, "C") == 0)
                    reg_d -= reg_c;
                else if(argument_2[0] == '[')
                    reg_d -= memory[atoi(argument_2 + 1)];
                else
                    reg_d -= atoi(argument_2);                                                // <
            }
            else if(argument_1[0] == '[')                                                     // > вычитание из адреса
            {
                if(strcmp(argument_2, "A") == 0)
                    memory[atoi(argument_1 + 1)] -= reg_a;
                else if(strcmp(argument_2, "B") == 0)
                    memory[atoi(argument_1 + 1)] -= reg_b;
                else if(strcmp(argument_2, "[") == 0)
                    memory[atoi(argument_1 + 1)] -= memory[atoi(argument_2 + 1)];
                else if(strcmp(argument_2, "C") == 0)
                    memory[atoi(argument_1 + 1)] -= reg_c;
                else if(strcmp(argument_2, "D") == 0)
                    memory[atoi(argument_1 + 1)] -= reg_d;
                else if(argument_2[0] == '[')
                    memory[atoi(argument_1 + 1)] -= memory[atoi(argument_2 + 1)];
                else
                    memory[atoi(argument_1 + 1)] -= atoi(argument_2);                         // <
            }
        }                                                                                     // <

        printf("%s %i %i\n", comand, i_comand, size_comand);
        printf("%s %i %i\n", argument_1, i_argument_1, size_argument_1);
        printf("%s %i %i\n", argument_2, i_argument_2, size_argument_2);
        printf("\n");

        i_comand = 0;
        i_argument_1 = 0;
        i_argument_2 = 0;
        size_comand = 1;
        size_argument_1 = 1;
        size_argument_2 = 1;
    }

    printf("_________________________________________________________\n");
    printf("%i %i\n", reg_a, reg_b);

    if (fclose(pf) != 0)
        fprintf(stderr, "Error closing file.\n");

    return 0;
}