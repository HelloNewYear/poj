#include <stdio.h>
#define stacksize 100
typedef char datatype;
typedef struct{
    datatype data[100];
    int top;
}seqstack; 

void initstack(seqstack *s) 
{
	s->top=-1;
}

void push(seqstack *s,datatype x) 
{
	if (s->top==stacksize-1)
		printf("stack overflow");
	else 
	{
		s->top++;
        s->data[s->top]=x;
	}
}

datatype pop(seqstack *s)  
{
    if (s->top==-1)
       printf("stack empty\n");
    else
       return  s->data[s->top--];
}

datatype gettop(seqstack *s)  
{
   if (s->top==-1)
      printf("stack empty");
   else
      return s->data[s->top];
}

int main(){
	seqstack stack;
	initstack(&stack);
	pop(&stack);
	return 0;
}
