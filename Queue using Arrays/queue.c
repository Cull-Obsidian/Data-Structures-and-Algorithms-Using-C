//Implementation of Queue Using Array
//Code by Lakhan, Date = 2 Jan 2024

//header files
#include <stdio.h>
#include <stdlib.h>

//Global Variable Declaration
#define MAXSIZE 10
int queue[MAXSIZE];
int rear = -1, front = 0;

//function Prototypes
void insert();
void delete1();
void display();

void main()
{
    int choice;
    do
    {
        printf("========== QUEUE ==========");
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit");
        printf("\n==========================");
        printf("\n==========================");
        printf("\n Enter Your Choice");

         scanf("%i", &choice);
        switch (choice)
        {
            case 1 : insert(); break;
            case 2 : delete1(); break;
            case 3 : display(); break;
            default : printf("Invalid Choice");
        }
    }while(choice != 4);
    
}

//insert function
void insert()
{
    int n;
    if(rear == MAXSIZE - 1)
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        printf("Enter an Element: ");
        scanf("%i",&n);
        rear++;
        queue[rear] = n;
    }
}

//Delete Function
void delete1()
{
    int n;
    if(front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        n = queue[front];
        printf("Deleted Element = %i", n);
        front++;
    }
}

//Display Function
void display()
{
    if(front > rear)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue Element: \n");
        for(int i = rear; i >= front; i--)
        {
            printf("%i \n", queue[i]);
        }
    }
}

//Queue has some serious drawbacks, Use it Carefully