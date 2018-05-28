#include <stdio.h>
#include <stdlib.h>

typedef void (*myown_call)(void);

typedef struct fun{
	char *name;
	myown_call call;
}fun_t;

extern struct fun _myown_start;
extern struct fun _myown_end;

#define MKENT_COMPLETE(name,fun) \
		{#name,fun}

#define Struct_fun __attribute__((unused, section(".myown")))
#define cmd(name,fun) \
	fun_t _fn_##name Struct_fun = \
	MKENT_COMPLETE(name,fun)


void func3()
{
	printf("\tthis is section 3\n");
}

cmd(section3,func3);

void func2()
{
	printf("\tthis is section 2\n");
}

cmd(section2,func2);
void func1()
{
	printf("\tthis is section 1\n");
}

cmd(section1,func1);

void do_initcalls(void)
{
	struct fun *call_ptr = &_myown_start;
	do{
		fprintf(stdout,"call ptr:%p\n",call_ptr);
		fprintf(stdout,"name:%p %s \n",call_ptr->name,call_ptr->name);
		(*call_ptr->call)();
		call_ptr++;
	}while(call_ptr < &_myown_end);
}

int main(int argc,void *argv[])
{
	printf("startadd: %p\n endadd:%p\n",
			&_myown_start,
			&_myown_end);
	do_initcalls();
}
