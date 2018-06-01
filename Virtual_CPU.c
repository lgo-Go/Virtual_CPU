#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i_comand = 0;
	int i_argument_1 = 0;
	int i_argument_2 = 0;
	int size_comand = 1;
	int size_argument_1 = 1;
	int size_argument_2 = 1;
	char comand[size_comand];
	char argument_1[size_argument_1];
	char argument_2[size_argument_2];
	int memory[256];
	int reg_a, reg_b, reg_c, reg_d,
		carry_flag, zero_flag,
		*stack_pointer, *instruction_pointer;
	FILE *pf;


	if((pf = fopen("assembler_code.txt", "r")) == NULL)
	{
		fprintf(stderr, "file open error");
		exit(EXIT_FAILURE);
	}

	stack_pointer = & memory[231];
	instruction_pointer = memory;

	while((comand[i_comand] = getc(pf)) != ' ')
	{
		if(comand[i_comand] == EOF)
			break;
		++i_comand;
		++size_comand;
	}

	while((argument_1[i_argument_1] = getc(pf)) != ' ')
	{
		if(argument_1[i_argument_1] == EOF)
			break;
		++i_argument_1;
		++size_argument_1;
	}

	while((argument_2[i_argument_2] = getc(pf)) != ' ')
	{
		if(argument_2[i_argument_2] == EOF)
			break;
		++i_argument_2;
		++size_argument_2;
	}

	printf("%s\n", comand);
	printf("%s\n", argument_1);
	printf("%s\n", argument_2);

	return 0;
}