#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    int task_id;
    char task_des[100];
    char status[12];
};
struct node
{
    struct data *info;
    struct node *next;
};
struct node *head;
struct node *last;
struct node *create_node(struct data *details)
{
    struct node *newnode;
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("memory full!");
        return NULL;
    }
    newnode->info = (struct data *)malloc(sizeof(struct data));
    
    if (!newnode->info) {
        printf("Memory full!\n");
        free(newnode);
        return NULL;
    }

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            if (temp->info->task_id == details->task_id)
            {
                printf("Task Id already exits");
                free(newnode->info);
                free(newnode);
                return NULL;
            }
            temp = temp->next;
        }
    }
    newnode->next = NULL;
    newnode->info->task_id = details->task_id;
    strcpy(newnode->info->task_des, details->task_des);
    strcpy(newnode->info->status, details->status);
    return newnode;
}
void add_end(struct data *details)
{
    struct node *newnode = create_node(details);
    if (newnode == NULL) return;
    if (head == NULL)
    {
        head = newnode;
        last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
}
void removed(int id)
{
    if(head==NULL){
        printf("no task found");
        return;
    }
    if(head->info->task_id==id){
        head=head->next;
        printf("Task deleted succesfully\n");
        return;
    }
    int i = 0;
    struct node *curr = head->next;
    struct node *prev = head;
    while (curr != NULL) {
        if (curr->info->task_id == id) {
            prev->next = curr->next;
            if (curr == last) {
                last = prev; // Update the last node if the last node is being deleted
            }
            free(curr->info);
            free(curr);
            printf("Task deleted successfully.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
        }
        printf("id not found");
    }
void update_task(int id, char str[])
{
    if(head==NULL){
        printf("no task found");
        return;
    }
    struct node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->info->task_id == id)
        {
            strcpy(temp->info->status, str);
            printf("status update succesfully\n");
            return;
        }
        temp = temp->next;
    }
    printf("id not found\n");
}
void display()
{
    int i = 1;
    struct node *temp = head;
    if(temp==NULL){
        printf("no task found\n");
    }
    while (temp != NULL)
    {
        printf("Task %d:->\n", i);
        printf("Task ID: %d\t", temp->info->task_id);
        printf("Task Status: %s\t", temp->info->status);
        printf("Task Description: %s", temp->info->task_des);
        temp = temp->next;
        i++;
    }
}
int main()
{
    struct data *info;
    int i = 1;
    info=(struct data*)malloc(sizeof(struct data));
    if(!info){
        printf("memory full!");
        i=0;
    }
    int choice;
    int id;
    while (i)
    {
        printf("\nWelcome to Task Management System! \n1.to Add Task \n2.to remove particular task \n3.to mark task as complete\n4.to display task\n5.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
        {
            printf("Task id:");
            scanf("%d",&info->task_id);
            printf("Task description:");
            getchar();
            fgets(info->task_des,100,stdin);
            printf("Task status:");
            scanf("%s", info->status);
            add_end(info);
            break;
        }
        case 2:
        {
            printf("enter id of task to remove:");
            scanf("%d", &id);
            removed(id);
            break;
        }
        case 3:
        {
            printf("enter id of task to update:");
            scanf("%d", &id);
            char str[12] = "complete\0";
            update_task(id, str);
            break;
        }
        case 4:
        {
            display();
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