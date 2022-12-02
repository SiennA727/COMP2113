# C Programming

Compilation: gcc -pedantic-errors -std=c11 program.c

## Background

- More low-level language (no classes and STL)
- Used extensively in Unix or Linux
- C++ extends C to include support for Object Oriented Programming and features facilitate large software development projects

## `printf()`

*hello.c*
```c
#include <stdio.h>
int main(){
    printf( "Hello world!\n" );
    return 0;
}
```

- standard I/O: `include <stdio.h>`
- no namespace
- filename: xxx.c
- printf("xxx\n")

### Conversion Specifiers

```c
int a = 1, b=2;
double c = 10.5;
printf("Input %d %d %f.\n",a,b,c);
printf("Their sum is %f.\n", a+b+c);
```

| Variable Type | Conversion Specifier|
| :----: | :----:|
|int|%d|
|float / double|%f|
|float/double without trailing zeros|%g|
|char | %c|
|string| %s|

Example of wrong conversion specifier: double is changed to 0

```c
int a = 1, b=2;
double c = 10.5;
printf("Input %d %d %d.\n",a,b,c);
// 1 2 0
```

### No String Class

String in C is just an array of char.

```c
char name[] = "SA"; // do not need specify length
printf("Hi %s!",name);
```

|S|i|e|n|n|a|\0|
|-|-|-|-|-|-|-|
|0|1|2|3|4|5|6|

Print with right-adjusted column width:
`printf("%8s%8s%8s\n", "Name", "Age", "Weight")`

## `scanf()`

```c
int a;
float b;
scanf("Enter an integer and a float: %d%f", a, b);
```
Note the value is **pass by reference.**

### Read a string

```c
char name[100];
scanf("%s", name); // no []!!
```
Note: no `&` because `name` is already a pointer! (to the first slot)

## C Basics

### Variables and Flow Control

`for (int i=0; i<10; i++)` needs `-std=c99`

### Function (pass by reference)

Only valid in C++:

```c++
void swap(double &a, double &b){
    double temp = a;
    a=b;
    b=temp;
}
```

Valid in C as well:

```c++
void swap(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}
// call the function:
swap(&a, &b);
```

### Function (pass an array)

```c
void salary_increase(int sal[]){
    for (int i=0; i<4; i++){
        sal[i] *= 1.1;
    }
}

int main(){
    int salary[] = {15000, 20000, 36000, 24000};
    salary_increase(salary);
}
```

Note: compile with **c99** standard!

Using pointer

```c
void salary_increase(int *sal){
    for (int i=0; i<4; i++){
        (*sal) = (*sal) * 1.1;
        sal++; // sal[i] = *(sal+i)
    }
}
```

### C-String

`#include <string.h>`

can be accessed by index: str[i]

|Function|Effect|
|:-:|:-:|
|`strcpy(char s1[], char s2[])`|copy s2 to s1, s2 not changed|
|`strcat(char s1[], char s2[])`|append s2 after s1|
|`strcmp(char s1[], char s2[])`|return negative if s1<s2, 0 if s1==s2, positive if s1>s2|
|`strlen(char s1[])`|return the length|

Note: when doing copy and concat, pay attention to when the string has enough slots to hold the change

## Memory Allocation and Struct

C does not have `new` operator

### `malloc()` Function

`void * malloc(int size);`

size: specify the number of bytes of memory required

return: a pointer to the space allocated, or null if memory allocation fails

`#include <stdlib.h>` to use `malloc()`, `free()`, and `NULL`

*memory1.c*

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int size, *a;
    scanf("%d", &size);
    a = (int*) malloc (size *sizeof(int));
    for (int i=0; i<size; i++)
        a[i] = i;
    for (int i=0; i<size; i++)
        printf("%d", a[i]);
    return 0;
}
```

### `free()`

`void free(void *ptr);`

**Ensure** the pointer value passed to free() is a value returned from malloc() function

```c
int *a = (int*) malloc(10*sizeof(int));
free(a);
```

### Struct

structs cannot have member functions

```c
struct student{
    char name[20];
    int uid;
};
int main(){
    struct student a; // important!!!
    strcpy(a.name, "Kit");
    a.uid = 3035637424;
    return 0;
}
```
Note: need to repeat the `struct` keyword before the `name` student

### `typedef`

example:

```c
typedef struct student Student;
Student a;
```

**Important Example: *employee.c* **

### Struct Constructors

- name of constructor = name of struct

example:

```c
struct Student{
    char* name;
    char* id;
    int age;
    Student (char* nm, char* d, int a){
        name = nm;
        id = d;
        age = a;
    }
    // can have multiple constructors
    Student (char* nm, char* d){
        name = nm;
        id = d;
    }
};
```

Use the constructor:

`Student s("Tim", "3035637424", 20);`

`Student* s = new Student("Tim", "3035637424", 20);`

`Student s = Student("Tim", "3035637424", 20);`

## GDB Debugger

- Breakpoint
- Watching variables

### GNU Debugger

Compile with option -g: `g++ -pedantic-errors -std=c++11 -g hello.cpp -o hello`

|Console|Action|
|:-:|:-:|
|gdb hello|launch GDB with hello|
|b 8|set breakpoint at line 8|
|r|run the program (stop at set breakpoint)|
|p i|view the current values of i|
|n|execute the next line of code|
|q|exit GDB|