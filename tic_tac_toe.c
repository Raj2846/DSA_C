#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

void resetBoard(void)
{
    char k = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = k++;
}

void displayBoard(void)
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("\n---+---+---\n");
    }
    printf("\n\n");
}

int cellTaken(int r, int c)
{
    return board[r][c] == 'X' || board[r][c] == 'O';
}

int hasWinner(void)
{
    // Rows & columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
            (board[i][0] == 'X' || board[i][0] == 'O'))
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
            (board[0][i] == 'X' || board[0][i] == 'O'))
            return 1;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        (board[0][0] == 'X' || board[0][0] == 'O'))
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        (board[0][2] == 'X' || board[0][2] == 'O'))
        return 1;

    return 0;
}

int isDraw(void)
{
    if (hasWinner())
        return 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0; // still an empty cell
    return 1;
}

void flushLine(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

void promptMove(int player)
{
    char mark = (player == 1) ? 'X' : 'O';
    int choice, ok = 0;

    while (!ok)
    {
        printf("Player %d [%c], enter your move (1-9): ", player, mark);
        int read = scanf("%d", &choice);
        if (read != 1)
        {
            printf("Invalid input. Please enter a number 1-9.\n");
            flushLine();
            continue;
        }
        if (choice < 1 || choice > 9)
        {
            printf("Out of range. Choose 1-9.\n");
            continue;
        }
        int r = (choice - 1) / 3;
        int c = (choice - 1) % 3;
        if (cellTaken(r, c))
        {
            printf("Cell already taken. Try another.\n");
            continue;
        }
        board[r][c] = mark;
        ok = 1;
    }
    flushLine(); // clear leftover newline
}

int main(void)
{
    int player = 1;
    resetBoard();

    while (1)
    {
        displayBoard();
        promptMove(player);

        if (hasWinner())
        {
            displayBoard();
            printf("🎉 Player %d wins!\n", player);
            break;
        }
        if (isDraw())
        {
            displayBoard();
            printf("It's a draw.\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
