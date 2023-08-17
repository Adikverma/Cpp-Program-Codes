#include <bits/stdc++.h>
using namespace std;

vector<int> matrix(101, 0);

void setMatrix()
{
    matrix[1] = 99;
    matrix[90] = 91;
    matrix[66] = 60;
}

void printMatrix()
{
    bool change = true;
    for (int i = 10; i >= 1; i--)
    {
        if (change)
        {
            for (int j = i * 10; j > (i - 1) * 10; j--)
            {
                cout << matrix[j] << " ";
            }
        }
        else
        {
            for (int j = (i - 1) * 10 + 1; j <= i * 10; j++)
            {
                cout << matrix[j] << " ";
            }
        }
        change = !change;
        cout << '\n';
    }
}

int dice()
{
    srand(time(0));
    int lb = 1, ub = 6;
    int dc = (rand() % (ub - lb + 1)) + lb;
    return dc;
}

void giveOptions()
{
    cout << "\nChoose options: \n";
    cout << "1. Roll Dice\n";
    cout << "2. Exit\n";
}

void selected(int &playerPos)
{
    int dc = dice();

    cout << "Dice Rolled: " << dc << "\n";

    if (playerPos == 0)
    {
        if (dc == 6)
        {
            playerPos = 1;
        }
    }
    else
    {
        if (dc + playerPos <= 100)
        {
            playerPos += dc;
        }
    }
    if (matrix[playerPos] != 0)
    {
        playerPos = matrix[playerPos];
    }
}

int main()
{
    string player1 = "";
    string player2 = "";
    cout << "Enter Player 1 name: ";
    cin >> player1;

    cout << "Enter Player 2 name: ";
    cin >> player2;

    cout << "\n---------Lets begin!---------\n";
    setMatrix();
    printMatrix();

    bool player = true;
    int player1Pos = 0;
    int player2Pos = 0;
    int win = 0;

    while (!win)
    {
        int input = 0;
        if (player)
        {
            giveOptions();
            cout << player1 << " input: ";
            cin >> input;

            if (input == 1)
            {
                selected(player1Pos);
                cout << player1 << " Moved to : " << player1Pos << "\n";
            }
            else if (input == 2)
            {
                break;
            }
            else
            {
                cout << "Please Enter a valid input!";
                continue;
            }
            if (player1Pos == 100)
            {
                win = 1;
            }
        }
        else
        {
            giveOptions();
            cout << player2 << " input: ";
            cin >> input;

            if (input == 1)
            {
                selected(player2Pos);
                cout << player2 << " Moved to : " << player2Pos << "\n";
            }
            else if (input == 2)
            {
                break;
            }
            else
            {
                cout << "Please Enter a valid input!";
                continue;
            }
            if (player2Pos == 100)
            {
                win = 2;
            }
        }
        player = !player;
    }

    if (win == 0)
    {
        cout << "\nSorry to hear that one of you don't want to play ;(\n";
    }
    else if (win == 1)
    {
        cout << "\n---------------------\n";
        cout << "     " << player1 << " wins\n";
        cout << "---------------------\n";
    }
    else
    {
        cout << "\n---------------------\n";
        cout << "     " << player2 << " wins\n";
        cout << "---------------------\n";
    }

    return 0;
}