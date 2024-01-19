//program to create a linked list
//code by lakhan Date - 18 JAN 2024

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//function Prototyping
void create();
void display();
void insert_first();
void insert_last();
void insert_mid();
void delete_first();
void delete_last();
void delete_mid();

//structure Declaration
struct node
{
    int data;
    struct node *add;
}; struct node *start = NULL, *temp, *new1, *prev, *next;

void main()
{
    int choice;
    do
    {
        /* Menu Design */
        printf("\n================Linked List==============");
        printf("\n 1. Create \n 2. Traverse \n 3. Insert First \n 4. Insert last \n 5. Insert Middle \n 6. Delete First \n 7. Delete Last \n 8. Delete Middle \n 9. Exit");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        
        case 2:
            display();
            break;
        case 3:
            insert_first();
            break;
        case 4:
            insert_last();
            break;
        case 5:
            insert_mid();
            break;
        case 6:
            delete_first();
            break;
        case 7:
            delete_last();
            break;
        case 8:
            delete_mid();
            break;
        default:
            break;
        }
    } while (choice != 9);
}

//Create Function
void create()
{   
    //first node Creation
    int n;
    printf("\nEnter a Number: ");
    scanf("%d", &n);

    start = (struct node *)malloc(sizeof(struct node));
    start -> data = n;
    start -> add = NULL;
    temp = start;

    //rest node creation
    printf("Want to Continue: ");
    char choices = getche();

    while(choices == 'Y' || choices == 'y')
    {
        printf("Enter an Element: ");
        scanf("%d",&n);
        new1 = (struct node *) malloc(sizeof(struct node));
        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = temp->add;
        printf("Want to Continue: ");
        choices = getche();
    }    
}


//traverse function
void display()
{
    if(start == NULL)
    {
        printf("No List Found");
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("\t \n %d",temp -> data);
            temp = temp -> add;
        }
    }
}


//Insert at First position
void insert_first()
{
    int n;
    if(start == NULL)
    {
        printf("\nList Not Found");
    }
    else
    {
        printf("Enter New Element: ");
        scanf("%d",&n);
        new1 = (struct node *)malloc(sizeof(struct node));
        new1 -> data = n;
        new1 -> add = NULL;
        new1 -> add = start;
        start = new1; 
    }
}

//Insert At last Position
void insert_last()
{
    int n;
    if(start == NULL)
    {
        printf("\n List not found");
    }
    else
    {
        printf("\nEnter New Element");
        scanf("%d",&n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1 -> data = n;
        new1 -> add = NULL;
        temp = start;
        while( temp -> add != NULL)
        {
            temp = temp -> add;
        }

        temp -> add = new1;
    }
}


//Insert at anu Middle Position
void insert_mid()
{
    int n;
    int pos;
    int i = 1;
    if(start == NULL)
    {
        printf("\nList Not Found");
    }
    else
    {
        printf("\nEnter New Element: ");
        scanf("%d",&n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1 -> data = n;
        new1 -> add = NULL;

        printf("\nEnter the Position: ");
        scanf("%d", &pos);

        next = start;
        while(i < pos)
        {
            prev = next;
            next = next -> add;
            i++;
        }
        prev -> add = new1;
        new1 -> add = next;
    }
}


//Delete First node
void delete_first()
{
    if(start == NULL)
    {
        printf("\nList not Found");
    }
    else
    {
        temp = start;
        start = start -> add;
        printf("\nDeleted node is %d", temp -> data);
        free(temp);  //free function is for releasing the memory allocated using malloc function
    }
}


//Delete last node
void delete_last()
{
    if(start == NULL)
    {
        printf("\n list not found");
    }
    else
    {
        temp = start;
        while(temp -> add != NULL)
        {
            prev = temp;
            temp = temp -> add;
        }
        prev -> add = NULL;
        printf("Deleted node: %d", temp -> data);
        free(temp);
    }
}


//Delete any middle node
void delete_mid()
{
    int pos, i = 1;
    if(start == NULL)
    {
        printf("\n List not Found");
    }
    else
    {
        printf("\nEnter the position: ");
        scanf("%d", &pos);

        temp = start;
        while ( i < pos)
        {
            prev = temp;
            temp = temp -> add;
            i++;
        }
        next = temp -> add;
        prev -> add = next;
        printf("\nDeleted node: %d", temp -> data);
        free(temp);
    }
}