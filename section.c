#include <stdio.h>
#include <stdlib.h>

typedef void (*myown_call)(void);

extern myown_call _myown_start;
extern myown_call _myown_end;

#define _init __attribute__((unused, section(".myown")))
#define func_init(func) myown_call _fn##func _init = func

void func3()
{
	printf("this is section 3\n");
}

func_init(func3);

void func2()
{
	printf("this is section 2\n");
}

func_init(func2);
void func1()
{
	printf("this is section 1\n");
}

func_init(func1);

void do_initcalls(void)
{
	myown_call *call_ptr = &_myown_start;
	do{
		fprintf(stdout,"call ptr:%p\n",call_ptr);
		(*call_ptr)();
		call_ptr++;

	}while(call_ptr < &_myown_end);
}

int main(int argc,void *argv[])
{
	do_initcalls();
}
