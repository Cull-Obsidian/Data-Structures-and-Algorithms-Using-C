//Implementation of stack using Arrays
//Code by Lakhan, Date = 2 JAN 2024

//Header files
#include <stdio.h>
#include <conio.h>

//variable definition
#define MAXSIZE 10
int stack[MAXSIZE], top = -1;

//fuction prototypes
void push();
void pop();
void display();

//main function
void main()
{
    int choice;
    do
    {
        printf("========== Stack ==========");
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit");
        printf("\n==========================");
        printf("\n==========================");
        printf("\n Enter Your Choice");

         scanf("%i", &choice);
        switch (choice)
        {
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : display(); break;
            default : printf("Invalid Choice");
        }
    }while(choice != 4);

}


//Push Function
void push()
{
    int n;
    if (top == MAXSIZE - 1)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        printf("Enter an Element");
        scanf("%i", &n);
        top++;
        stack[top] = n;
    }
}

//Display Function
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack Underflow \n");
    }
    else
    {
        printf("Elements of the stack");
        for (i = top; i >= 0; i--)
        {
            printf("\n %i",stack[i]);
        }
    }
}

//Pop function
void pop()
{
    int n;
    if(top == -1)
    {
        printf("Stack Underflow \n");
    }
    else
    {
        //We Cannot Remove an Element from an array in C
        //We Just Assume that it has been Popped
        //They get overwritten when we push new Elements
        n = stack[top];
        top--;
        printf("Popped Element = %i", n);

    }

}

