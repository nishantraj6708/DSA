#include <stdio.h>
#include <string.h>
int top = -1;
struct books
{
    char book_name[50];
};
const int size = 1000;
void push(char book_name[50], struct books stack[])
{
    if (top == size - 1)
    {
        printf("memory full");
    }
    else
    {
        top++;
        strcpy(stack[top].book_name, book_name);
        printf("book succesfully returned\n");
    }
}
void pop()
{
    if (top == -1)
    {
        printf("no books are returned\n");
    }
    else
    {
        top--;
    }
}
void peek(struct books stack[])
{
    if (top == -1)
    {
        printf("no books returned or added\n");
    }
    else
    {
        printf("the top book is:%s\n", stack[top]);
    }
}
void show(struct books stack[])
{
    if (top == -1)
    {
        printf("no books returned or added\n");
    }
    else
    {
        int i = 0;
        printf("books are:");
        for (i = 0; i <= top; i++)
        {
            printf("%d . %s\t", i+1, stack[i].book_name);
        }
    }
}

int main()
{
    struct books stack[size];
    struct books name;
    int choice;
    int i = 1;
    while (i)
    {
        printf("Welcome to book management System! \n1.to Add books \n2.to remove recent book \n3.to show most recent book\n4.list all books\n5.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
        {
            printf("enter book name:");
            fgets(name.book_name, 50, stdin);
            push(name.book_name,stack);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            peek(stack);
            break;
        }
        case 4:
        {
            show(stack);
            break;
        }
        case 5:
        {
            i = 0;
            break;
        }
        default:
        {
            printf("wrong input\n");
            break;
        }
        }
    }
    printf("Thank You! for using this software");
    return 0;
}
