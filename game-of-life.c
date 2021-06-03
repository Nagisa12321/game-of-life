#include<stdio.h>
#include<stdlib.h>

void change(int** board, int len_i, int len_j);
int countLife(int i, int j, int** board, int len_i, int len_j);
int abs(int i);
int** create_array(int len_i, int len_j);

int main()
{
    system("clear");
    int len_i = 9;
    int len_j = 9;
    int** board = create_array(len_i, len_j);
    int tmp[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for (int i = 0; i < len_i; i++) {
        for (int j = 0; j < len_j; j++) {
            board[i][j] = tmp[i][j];
        }
    }

    while (1) {
        for (int i = 0; i < len_i; i++) {
            for (int j = 0; j < len_j; j++) {
                printf("%s ", board[i][j] ? "◆" : "◇");
            }
            printf("\n");
        }
        change((int**)board, len_i, len_j);
        sleep(1);
        system("clear");
    }
    return 0;
}


void change(int** board, int len_i, int len_j) {
    for (int i = 0; i < len_i; i++) {
        for (int j = 0; j < len_j; j++) {
            int count = countLife(i, j, board, len_i, len_j);
            if (board[i][j] == 1) {
                if (count < 2)
                    board[i][j] = -1;
                else if (count > 3)
                    board[i][j] = -1;
            } else {
                if (count == 3)
                    board[i][j] = 123;
            }
        }
    }

    for (int i = 0; i < len_i; i++) {
        for (int j = 0; j < len_j; j++) {
            int board_i_j = board[i][j];
            if (board_i_j == -1)
                board[i][j] = 0;
            else if (board_i_j == 123)
                board[i][j] = 1;
        }
    }
}

int countLife(int i, int j, int** board, int len_i, int len_j) {
    int num = 0;
    if (i - 1 >= 0 && j - 1 >= 0 && abs(board[i - 1][j - 1]) == 1) num++;
    if (i - 1 >= 0 && abs(board[i - 1][j]) == 1) num++;
    if (i - 1 >= 0 && j + 1 != len_j && abs(board[i - 1][j + 1]) == 1) num++;
    if (j - 1 >= 0 && abs(board[i][j - 1]) == 1) num++;
    if (j + 1 != len_j && abs(board[i][j + 1]) == 1) num++;
    if (i + 1 != len_i && j - 1 >= 0 && abs(board[i + 1][j - 1]) == 1) num++;
    if (i + 1 != len_i && abs(board[i + 1][j]) == 1) num++;
    if (i + 1 != len_i && j + 1 != len_j && abs(board[i + 1][j + 1]) == 1) num++;
    return num;
}

int abs(int i) {
    return i >= 0 ? i : -i;
}

int** create_array(int len_i, int len_j) {
    int** board = (int**) malloc(sizeof(int*) * len_i);
    for (int i = 0; i < len_i; i++) {
        board[i] = (int*) malloc(sizeof(int) * len_j);
    }
    for (int i = 0; i < len_i; i++) {
        for (int j = 0; j < len_j; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}