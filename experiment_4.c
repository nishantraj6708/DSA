#include<stdio.h>
#include<string.h>
struct queue{
    char name[50];
};
int size=50;
int front=-1,rear=-1;
void enqueue(char name[50],struct queue line[]){
    if((rear==size-1)){
        printf("line is full");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        strcpy(line[rear].name,name);
        printf("person added in queue");
    }
}
void dequeue(){
    if((front==-1 ) || front>rear){
        printf("\nNo customer");
        front=-1,rear=-1;
    }
    else{
        front++;
        printf("customer remove succesfully");
        if(front>rear){
        front=-1,rear=-1;
    }
}
}
void peek(struct queue line[]){
    if((front==-1) || front>rear){
        printf("No customer");
        front=-1,rear=-1;
    }
    else{
        printf("front customer is: %s",line[front].name);
    }
}
void show(struct queue line[]){
    if((front==-1) || front>rear){
        printf("\nNo customer");
        front=-1,rear=-1;
    }
    else{
        int i;
        printf("\nthe customers are:\n");
        for(i=front;i<=rear;i++){
            printf("%d. %s",i+1,line[i].name);
        }
    }
}
int main(){
    struct queue line[size];
    char name[50];
    int choice;
    int i = 1;
    while (i)
    {
        printf("\nWelcome Customer Queue Management System! \n1.to Add Customer \n2.to remove Customer from line \n3.to show Customer name in front\n4.list all Customers\n5.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
        {
            printf("enter Customer name:");
            fgets(name, 50, stdin);
            enqueue(name,line);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            peek(line);
            break;
        }
        case 4:
        {
            show(line);
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