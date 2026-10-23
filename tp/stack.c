#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node;
 
typedef struct stack
{
    node *top
} stack;

 void init(stack *s)
    {
        s->top=NULL;
    }
    int isEmpty(stack *s)
    {
        return s->top==NULL;
    }
    void push(stack *s,int x)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->data=x;
        temp->next=s->top;
        s->top=temp;
    }
    char pop(stack *s)
    {
        if(isEmpty(s))
        {
            printf("Stack is empty\n");
            return -1;
        }
        node *temp=s->top;
        int x=temp->data;
        s->top=s->top->next;
        free(temp);
        return x;
    }
    char peek(stack *s)
    {
        if(isEmpty(s))
        {
            printf("Stack is empty\n");
            return -1;
        }
        return s->top->data;
    }

    
   int postfix(char *exp)
    {
        stack s;
        init(&s);
        for(int i=0;exp[i]!='\0';i++)
        {
            if(exp[i]>='0' && exp[i]<='9')
            {
                push(&s,exp[i]-'0');
            }
            else
            {
                int x1=pop(&s);
                int x2=pop(&s);
                switch(exp[i])
                {
                    case '+':
                        push(&s,x2+x1);
                        break;
                    case '-':
                        push(&s,x2-x1);
                        break;
                    case '*':
                        push(&s,x2*x1);
                        break;
                    case '/':
                        push(&s,x2/x1);
                        break;
                }
            }
        }
        return pop(&s);
    }
   int main()
    {
        stack s;
        init(&s);
        push(&s,16);
        push(&s,2);
        push(&s,33);
        printf("%d\n",peek(&s));
        printf("%d\n",pop(&s));
        printf("%d\n",peek(&s));
          char expr[] = "63+2*4/"; 
        printf("Postfix result: %d\n", postfix(expr));
        return 0;

    }