#include <stdio.h>
#include <stdlib.h>

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

    int address_1 = 0;                                        // Если пользователь хочет произвести действие с памятью через адрес,
    int address_2 = 0;                                        // сюда сораняется номер ячейки памяти, который он ввёл

    int memory[256];
    int reg_a, reg_b, reg_c, reg_d,
        carry_flag, zero_flag,
        *stack_pointer, *instruction_pointer;
    FILE *pf;


    if((pf = fopen("assembler_code.txt", "r")) == NULL)       // Открытие файла с исходным кодом
    {
        fprintf(stderr, "file open error");
        exit(EXIT_FAILURE);
    }

    stack_pointer = & memory[231];
    instruction_pointer = memory;

    while((comand[i_comand] = getc(pf)) != ' ')               // > Расчленяем строку из исходного кода на команду, аргумент 1 и аргумент 2 
    {                                                         //   и записываем их в отдельные строки
        if(comand[i_comand] == EOF)
            break;
        ++i_comand;
        ++size_comand;
    }
    comand[i_comand] = '\n';

    while((argument_1[i_argument_1] = getc(pf)) != ' ')
    {
            if(argument_1[i_argument_1] == EOF)
                break;
            ++i_argument_1;
            ++size_argument_1;
    }
    argument_1[i_argument_1] = '\n';

    while((argument_2[i_argument_2] = getc(pf)) != ' ')
    {
        if(argument_2[i_argument_2] == EOF)
            break;
        ++i_argument_2;
        ++size_argument_2;
    }
    argument_2[i_argument_2] = '\n';                          // <

    if (argument_1[0] == 91)                                  // > Для работы пользователя с памятью через адреса
    {                                                         //   (atoi() переводит строку в соответствующий integer; 91 -- номер '[' в ASCII)
        address_1 = atoi(argument_1 + 1);
    }

    if (argument_2[0] == 91)
    {
        address_2 = atoi(argument_2);
    }                                                         // <

    // switch(comand)                                            // > Собственно, главная часть нашего симулятора. Данный кусок кода предназначен
    // {                                                              выполнять одну строку исходного кода. Потом это всё будет запихнуто в ещё один
    //     case "MOV":                                                switch(), чтобы выполнять весь исходный код из файла. Ииии да... Пока не работает.
    //         switch(argument_1)
    //         {
    //             case "A":
    //                 switch(argument_2)
    //                 {
    //                     case "A":
    //                         reg_a = reg_a;
    //                         break;
    //                     case "B":
    //                         reg_b = reg_a;
    //                         break;
    //                     case "C":
    //                         reg_c = reg_a;
    //                         break;
    //                     case "D":
    //                         reg_d = reg_a;
    //                         break;
    //                     // ещё не всё
    //                 }
    //             default:
    //                 switch(argument_2)
    //                 {
    //                     case "A":
    //                         memory[address_1] = reg_a;
    //                         break;
    //                     case "B":
    //                         memory[address_1] = reg_a;
    //                         break;
    //                     case "C":
    //                         memory[address_1] = reg_a;
    //                         break;
    //                     case "D":
    //                         memory[address_1] = reg_a;
    //                         break;
    //                     // ещё не всё
    //                 }
    //         }
    // }                                                         // <

    printf("%i %i\n", sizeof(int), sizeof(char));                       // > Это я проверял всякую парашу. Не обращай внимания

    printf("%s %i %i\n", comand, i_comand, size_comand);
    printf("%s %i %i\n", argument_1, i_argument_1, size_argument_1);
    printf("%s %i %i\n", argument_2, i_argument_2, size_argument_2);
    printf("%i, %i\n", address_1, address_2);                           // <

    return 0;
}