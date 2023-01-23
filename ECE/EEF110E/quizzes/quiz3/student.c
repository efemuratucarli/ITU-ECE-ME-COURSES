#include <stdlib.h>
#include <stdio.h>

struct sNode
{
    int x;
    int y;
    struct sNode* next;
};
typedef struct sNode Node;

typedef struct
{
    Node* head;
} Snake;

Snake snake={.head=NULL};

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void snake_spawn()
{
    // implementation goes here
    snake.head = malloc(sizeof(Node));
    snake.head->x = 8;
    snake.head->y = 8;
    snake.head->next = malloc(sizeof(Node));
    snake.head->next->x = 9;
    snake.head->next->y = 8;
    snake.head->next->next = malloc(sizeof(Node));
    snake.head->next->next->x = 10;
    snake.head->next->next->y = 8;
    snake.head->next->next->next = NULL;
}

void snake_grow()
{    
    // implementation goes here
   Node* tmp = snake.head;
   while(tmp->next != NULL)
   {
    tmp = tmp->next;
   }
   tmp->next = malloc(sizeof(Node));
   tmp->next->x = tmp->x;
   tmp->next->y = tmp->y;
   tmp->next->next = NULL;
}

void snake_dump()
{
    // implementation goes here
    if(snake.head == NULL)
    {
        printf("Snake is not spawned yet");
    }
    else
    {
        Node* tmp = snake.head;
        while(tmp != NULL)
        {
            if(tmp->x > 9 && tmp->y > 9)
            {
                printf("(%d,%d) ",tmp->x,tmp->y);
            }
            else if(tmp->x > 9 && tmp->y < 10)
            {
                printf("(%d, %d) ",tmp->x,tmp->y);
            }
            else if(tmp->x < 10 && tmp->y > 9)
            {
                printf("( %d,%d) ",tmp->x,tmp->y);
            }
            else
            {
                printf("( %d, %d) ",tmp->x,tmp->y);
            }
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void snake_move(int dir)
{       
    // implementation goes here
    if(dir == UP)
    {
        Node* tmp = malloc(sizeof(Node));
        tmp->x = snake.head->x;
        tmp->y = snake.head->y - 1;
        tmp->next = snake.head;
        snake.head = tmp;
        Node* tmp_prev = tmp;
        while(tmp->next != NULL)
        {
            tmp_prev = tmp;
            tmp = tmp->next;
        }
        free(tmp_prev->next);
        tmp_prev->next=NULL; 
    }
    else if (dir == RIGHT)
    {
        Node* tmp = malloc(sizeof(Node));
        tmp->x = snake.head->x + 1;
        tmp->y = snake.head->y;
        tmp->next = snake.head;
        snake.head = tmp;
        Node* tmp_prev = tmp;
        while(tmp->next != NULL)
        {
            tmp_prev = tmp;
            tmp = tmp->next;
        }
        free(tmp_prev->next);
        tmp_prev->next=NULL; 
    }
    else if (dir == LEFT)
    {
        Node* tmp = malloc(sizeof(Node));
        tmp->x = snake.head->x - 1;
        tmp->y = snake.head->y;
        tmp->next = snake.head;
        snake.head = tmp;
        Node* tmp_prev = tmp;
        while(tmp->next != NULL)
        {
            tmp_prev = tmp;
            tmp = tmp->next;
        }
        free(tmp_prev->next);
        tmp_prev->next=NULL; 
    }
    else if (dir == DOWN)
    {
        Node* tmp = malloc(sizeof(Node));
        tmp->x = snake.head->x;
        tmp->y = snake.head->y+1;
        tmp->next = snake.head;
        snake.head = tmp;
        Node* tmp_prev = tmp;
        while(tmp->next != NULL)
        {
            tmp_prev = tmp;
            tmp = tmp->next;
        }
        free(tmp_prev->next);
        tmp_prev->next=NULL; 
    }
}