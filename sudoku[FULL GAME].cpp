#include <iostream>
#include <windows.h>

using namespace std;

int sud[9][9] = { {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0} };
int pla[9][9] = { {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0} };

int main_menu(); //shows main menu, returns option number from menu
void map(int); //fills matrix "pla" with digits from matrix "sud"
int game( int, int); //let's play! returns number of mistakes
bool win(); //checks if player won
void board(); //shows gameboard
void sudoku(); //makes unique sudoku to solve
void insertion(int, int, int); //inserts digits to matrix "sud"
char end(int); //summarize last game, asks if player want to play one more time
void bye(); //end screen

int main()
{
    srand(time(NULL));
    char again = 'y';
    do
    {
        int rev = 0, mistakes = 3, hints = 1;
        int choice = main_menu();
        sudoku();
        switch (choice)
        {
            case 1:
            {
                rev = 38;
                break;
            }
            case 2:
            {
                rev = 32;
                break;
            }
            case 3:
            {
                rev = 26;
                break;
            }
            case 4:
            {
                rev = 20;
                break;
            }
            case 5:
            {
                
                cout << "Number of revealed squares: ";
                cin >> rev;
                cout << "Number of acceptable mistakes: ";
                cin >> mistakes;
                cout << "Number of avaible hints: ";
                cin >> hints;
                break;
            }
            case 6: 
            {
                again = 'n';
                break;
            }
            default:
            {
                cout << "Illegal action! Shutting down...";
                Sleep(2000);
                exit(-1);
            }
        }
        if (again != 'n')
        {
            map(rev);
            again = end(game(mistakes, hints));
        }
    } while (again == 'y');
    bye();
    return 0;
}

int main_menu()
{
    int choice;
    system("cls");
    cout << endl;
    cout << "------------------" << endl;
    cout << "------SUDOKU------" << endl;
    cout << "------------------" << endl << endl;
    cout << "Choose difficulty:" << endl;
    cout << "1. Easy (38 digits given)" << endl;
    cout << "2. Medium (32 digits given)" << endl;
    cout << "3. Hard (26 digits given)" << endl;
    cout << "4. Expert (20 digits given)" << endl;
    cout << "5. Custom" << endl << endl;
    cout << "6. Exit" << endl << endl;
    cout << "Your choice: ";
    cin >> choice;
    return choice;
}
void map(int dif)
{
    int tempX = 0, tempY = 0;
    for (int i = 0; i < dif; i++)
    {
        do
        {
            tempX = (rand() % 9);
            tempY = (rand() % 9);
        } while (pla[tempX][tempY] != 0);
        pla[tempX][tempY] = sud[tempX][tempY];
    }
}
int game(int mis, int hin)
{
    int errors = 0, digit = 0, hints = hin, col = 0, row = 0;
    while ((errors < mis) && win() == false)
    {
        system("CLS");
        board();
        cout << "Mistakes: " << errors << "/" << mis << endl;
        cout << "Hints: " << hints << "/" << hin << endl;
        cout << "Choose the digit You want to insert (insert 0 to get a hint): ";
        cin >> digit;
        cout << "Choose the row and column (from 1 to 9, separated by space button): ";
        cin >> row >> col;
        if (digit == 0)
        {
            if (hints > 0)
            {
                pla[row - 1][col - 1] = sud[row - 1][col - 1];
                hints--;
            }
            else
            {
                cout << "You've already used all avaible hints!";
                Sleep(1000);
            }
        }
        else if (pla[row - 1][col - 1] != 0)
        {
            cout << "This square is filled! Choose another one.";
            Sleep(1500);
        }
        else if (sud[row -1][col-1] != digit)
        {
            cout << "A mistake!";
            errors++;
            Sleep(1000);
        }
        else
        {
            pla[row -1][col-1] = digit;
            cout << "Nice!";
            Sleep(1000);
        }
    }
    return errors;
}
bool win()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (pla[i][j] != sud[i][j]) return false;
        }
    }
    return true;
}
void board()
{
    cout << endl;
    cout << "   |-----------|-----------|-----------|" << endl;
    int k = 0;
    for (int i = 0; i < 12; i++)
    {
        if ((i + 1) % 4 == 0) cout << "   |-----------|-----------|-----------|" << endl;
        else
        {
            cout << "   | ";
            for (int j = 0; j < 9; j++)
            {
                if ((j + 1) % 3 == 0)
                {
                    if (pla[k][j] == 0) cout << "-" << " | ";
                    else cout << sud[k][j] << " | ";
                }
                else
                {
                    if (pla[k][j] == 0) cout << "-" << "   ";
                    else cout << sud[k][j] << "   ";
                }
            }
            cout << endl;
            k++;
        }
    }
    cout << endl;
}
void sudoku()
{
    int start = (rand() % 9) + 1;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) pla[i][j] = 0; //clearing previous game
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
            case 0: 
            {
                insertion(0, 0, start);
                break;
            }
            case 1:
            {
                insertion(2, 2, start);
                break;
            }
            case 2:
            {
                insertion(1, 0, start);
                break;
            }
            case 3:
            {
                insertion(0, 2, start);
                break;
            }
            case 4:
            {
                insertion(2, 1, start);
                break;
            }
            case 5:
            {
                insertion(1, 2, start);
                break;
            }
            case 6:
            {
                insertion(0, 1, start);
                break;
            }
            case 7:
            {
                insertion(2, 0, start);
                break;
            }
            case 8:
            {
                insertion(1, 1, start);
                break;
            }
        }
        start++;
        if (start == 10) start = 1;
    }
}
void insertion(int x, int y, int start)
{
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (start == 10) start = 1;
            sud[x + (3*i)][y + (3*j)] = start++;
        }
    }
}
char end(int err)
{
    char choice;
    cout << endl << endl;
    if (err < 3) cout << "CONGRATULATIONS! You won!" << endl;
    else cout << "So close! Maybe next time You'll have the better luck!" << endl;
    cout << "Do You want to play one more time? [y/n]" << endl;
    cin >> choice;
    return choice;
}
void bye()
{
    system("CLS");
    cout << "Hope to see You again!";
    Sleep(2000);
}