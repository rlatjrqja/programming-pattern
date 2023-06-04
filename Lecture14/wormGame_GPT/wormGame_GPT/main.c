#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20
#define INITIAL_LENGTH 3
#define MAX_LENGTH WIDTH * HEIGHT

enum Direction { UP, DOWN, LEFT, RIGHT };

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int score;
    Position head;
    Position tail[MAX_LENGTH];
    int length;
    enum Direction direction;
} Snake;

typedef struct {
    Position position;
    int eaten;
} Food;

int isGameOver = 0;/////////////////////
Snake snake;
Food food;

void initialize() {
    snake.length = INITIAL_LENGTH;
    snake.direction = RIGHT;
    snake.head.x = WIDTH / 2;
    snake.head.y = HEIGHT / 2;
    for (int i = 0; i < INITIAL_LENGTH; i++) {
        snake.tail[i].x = snake.head.x - i;
        snake.tail[i].y = snake.head.y;
    }
    snake.score = 0;

    food.position.x = rand() % WIDTH;
    food.position.y = rand() % HEIGHT;
    food.eaten = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0) {
                printf("#");
            }

            if (x == snake.head.x && y == snake.head.y) {
                printf("O");
            }
            else if (food.position.x == x && food.position.y == y) {
                printf("X");
            }
            else {
                int isTail = 0;
                for (int i = 0; i < snake.length; i++) {
                    if (snake.tail[i].x == x && snake.tail[i].y == y) {
                        printf("o");
                        isTail = 1;
                        break;
                    }
                }
                if (!isTail) {
                    printf(" ");
                }
            }

            if (x == WIDTH - 1) {
                printf("#");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    printf("Score: %d\n", snake.score);
}

void handleInput() {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
        case 72:  // Up arrow
            if (snake.direction != DOWN) {
                snake.direction = UP;
            }
            break;
        case 80:  // Down arrow
            if (snake.direction != UP) {
                snake.direction = DOWN;
            }
            break;
        case 75:  // Left arrow
            if (snake.direction != RIGHT) {
                snake.direction = LEFT;
            }
            break;
        case 77:  // Right arrow
            if (snake.direction != LEFT) {
                snake.direction = RIGHT;
            }
            break;
        case 27:  // Esc key
            isGameOver = 1;
            break;
        }
    }
}

void update() {
    Position prevTail = snake.tail[snake.length - 1];
    for (int i = snake.length - 1; i > 0; i--) {
        snake.tail[i] = snake.tail[i - 1];
    }
    snake.tail[0] = snake.head;

    switch (snake.direction) {
    case UP:
        snake.head.y--;
        break;
    case DOWN:
        snake.head.y++;
        break;
    case LEFT:
        snake.head.x--;
        break;
    case RIGHT:
        snake.head.x++;
        break;
    }

    if (snake.head.x < 0 || snake.head.x >= WIDTH || snake.head.y < 0 || snake.head.y >= HEIGHT) {
        isGameOver = 1;  // Hit the wall
    }

    for (int i = 0; i < snake.length; i++) {
        if (snake.head.x == snake.tail[i].x && snake.head.y == snake.tail[i].y) {
            isGameOver = 1;  // Hit itself
            break;
        }
    }

    if (snake.head.x == food.position.x && snake.head.y == food.position.y) {
        snake.score++;
        snake.length++;
        food.eaten = 1;
    }

    if (food.eaten) {
        food.position.x = rand() % WIDTH;
        food.position.y = rand() % HEIGHT;
        food.eaten = 0;
    }
}

int main() {
    srand((unsigned int)time(NULL));

    initialize();

    while (!isGameOver) {
        draw();
        handleInput();
        update();
        Sleep(100);  // Delay for smoother animation
    }

    printf("Game Over! Your score: %d\n", snake.score);

    return 0;
}