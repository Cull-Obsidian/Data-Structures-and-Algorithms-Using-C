//Circular queue using Arrays
//Code by Lakhan  date - 9 Jan 2024


#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10  

int cq[MAXSIZE], rear = -1, front = -1;
void insert();
void delete1();
void display();

void main()
{
    int choice;
    do
    {
        printf("========== CIRCULAR QUEUE ==========");
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit");
        printf("\n==========================");
        printf("\n==========================");
        printf("\n Enter Your Choice: ");

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

//insert Function
void insert()
{
    int n;
    if ((rear + 1) % MAXSIZE == front )
    {
        printf("Queue is Overflow \n");
    }
    else
    {
        printf("Enter an Element: ");
        scanf("%i", &n);
        if(rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;  //this statement will be only true for the first time
            cq[rear] = n;
        }
        else{
            rear = (rear + 1) % MAXSIZE;
            cq[rear] = n;
        }

    }
}

//delete1 Fuction
void delete1()
{
    int n;
    if (rear == -1 && front == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        n = cq[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAXSIZE;
            printf("Deleted Element: %d", n);
        }
    }
}

//display Function
void display()
{
    if (rear == -1 && front == -1)
    {
        printf("The Queue is Empty");
    }
    else
    {
        int i;
        printf("Elements of the Queue: ");
        for(i = front; i != rear; (i = (i + 1) % MAXSIZE))
        {
            printf("%5d", cq[i]);
        }
        printf("%5d", cq[i]);  //To print the last element
        printf(" \n");
    }    
}