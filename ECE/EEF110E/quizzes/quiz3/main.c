#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void snake_spawn();
void snake_grow();
void snake_dump();
void snake_move(int);

int main()
{
    snake_spawn();
    snake_grow();
    snake_grow();
    snake_grow();
    snake_dump();

    for(int i=0;i<8;i++)
    {
        snake_move(UP);
        snake_dump();
    }
    for(int i=0;i<8;i++)
    {
        snake_move(LEFT);
        snake_dump();
    }
}