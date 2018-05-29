#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	char ch;
	char comand[30];
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

	while((ch = getc(pf)) != '\n')
	{
		comand[i] == ch;
		++i;
	}

	printf("%s\n", comand);

	return 0;
}