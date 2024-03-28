#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// Function to generate a grid of symbols or characters
void generate_grid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 'A' + (rand() % 26);  // Generate a random uppercase letter
        }
    }
}

// Function to display the grid to the user
void display_grid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to clear the screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to get the user's input and check it against the grid
int check_grid(char grid[SIZE][SIZE]) {
    char user_grid[SIZE][SIZE];

    printf("Enter the grid, row by row:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf(" %c", &user_grid[i][j]);  // Read a single character
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] != user_grid[i][j]) {
                return 0;  // The grids do not match
            }
        }
    }

    return 1;  // The grids match
}

int main() {
    srand(time(0));  // Seed the random number generator

    char grid[SIZE][SIZE];
    generate_grid(grid);

    printf("Memorize this grid:\n");
    display_grid(grid);

    printf("Press Enter to continue...");
    getchar();  // Wait for the user to press Enter

    clear_screen();

    if (check_grid(grid)) {
        printf("Congratulations, you remembered the grid correctly!\n");
    } else {
        printf("Sorry, that's not correct. The correct grid was:\n");
        display_grid(grid);
    }

    return 0;
}