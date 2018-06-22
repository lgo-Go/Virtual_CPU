# Симмулятор микрокомпьютера

## Возможности симмулятора:
- имеются 4 регистра общего назначения: A,B,C,D;
- имеются 2 флага: Z – ноль (zero), C – перенос (carry);
- компьютер имеет память размером 1024 байт (хранилище под 256 значений типа int); 
- 100-байтовый (25 элементов) стэк включён в эту память;

## Синтаксис:

### Копирование значений
>MOV reg reg  
>MOV reg address  
>MOV reg constant  
>MOV address reg  
>MOV address constant  

### Инкремент и декремент
>INC reg   
>DEC reg  

### Умножение и деление
>MUL reg  
>MUL address  
>MUL constant  
>DIV reg  
>DIV address  
>DIV constant  

### Сложенеи и вычитание
>ADD reg reg  
>ADD reg address  
>ADD reg constant  
>SUB reg reg  
>SUB reg address  
>SUB reg constant  

### Сравнение. Устанавливает флаг нуля в TRUE, если два значения равны
>CMP reg reg  
>CMP reg address  
>CMP reg constant  

### Условный переход. Переходит на указанную строчку кода, если флаг нуля установлен в FALSE
>JMP constant 

**Адрес с использованием константы: [constant]  
Constant: любое число между  -2 147 483 648 ... 2 147 483 647 (4 байта со знаком)**





## Содержание репозитория

Название файла     | Содержание файла
-------------------|----------------------
README.md          | Файл с описанием репозитория и проекта
Virtual_CPU.c      | Код симмулятора на языке C
Makefile.make      | Makefile проекта
assembler_code.txt | Исполняемый код
.gitignore         | Избавляет от ненужных файлов в репозитории

## Над проектом работали

Игорь Горбунов              | Игорь Байрамалов
----------------------------|------------------
Обработка assembler_code.txt| RAEDME.md
Makefile                    | MUL
CMP                         | DIV
INC                         | ADD
DEC                         | SUB
MOV                         |