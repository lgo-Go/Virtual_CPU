# Virtual_CPU

#h1 Симмулятор микрокомпьютера

#h2 Возможности симмулятора:
-ul имеются 4 регистра общего назначения: A,B,C,D;
-ul имеются 2 флага: Z – ноль (zero), C – перенос (carry);
-ul компьютер имеет память размером 1024 байт (хранилище под 256 значений типа int); 
-ul 100-байтовый (25 элементов) стэк включён в эту память.

#h2 Синтаксис:
значения
#h3 Копирование 
MOV reg reg
MOV reg address
MOV reg constant
MOV address reg
MOV address constant

#h3 Инкремент и декремент
INC reg 
DEC reg

#h3 Умножение и деление
MUL reg
MUL address
MUL constant
DIV reg
DIV address
DIV constant

#h3 Сложенеи и вычитание
ADD reg reg
ADD reg address
ADD reg constant
SUB reg reg
SUB reg address
SUB reg constant

#h3 Сравнение. Устанавливает флаг нуля в TRUE, если два значения равны
CMP reg reg
CMP reg address
CMP reg constant

#h3 Условный переход. Переходит на указанную строчку кода, если флаг нуля установлен в FALSE
JMP constant

Адрес с использованием константы: [constant]
Constant: любое число между  -2 147 483 648 ... 2 147 483 647 (4 байта со знаком)

Название файла     | Содержание файла
-------------------|----------------------
README.md          | Файл с описанием репозитория и проекта
Virtual_CPU.c      | Код симмулятора на языке C
Makefile.make      | Makefile проекта
assembler_code.txt | Исполняемый код
.gitignore         | Избавляет от ненужных файлов в репозитории