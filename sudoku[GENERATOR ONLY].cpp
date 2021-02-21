void sudoku(int tab2)
{
    int start = (rand() % 9) + 1;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) tab2[i][j] = 0; //clearing previous game
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
        case 0:
        {
            insertion(0, 0, start, tab1);
            break;
        }
        case 1:
        {
            insertion(2, 2, start, tab1);
            break;
        }
        case 2:
        {
            insertion(1, 0, start, tab1);
            break;
        }
        case 3:
        {
            insertion(0, 2, start, tab1);
            break;
        }
        case 4:
        {
            insertion(2, 1, start, tab1);
            break;
        }
        case 5:
        {
            insertion(1, 2, start, tab1);
            break;
        }
        case 6:
        {
            insertion(0, 1, start, tab1);
            break;
        }
        case 7:
        {
            insertion(2, 0, start, tab1);
            break;
        }
        case 8:
        {
            insertion(1, 1, start, tab1);
            break;
        }
        }
        start++;
        if (start == 10) start = 1;
    }
}

void insertion(int x, int y, int start, int tab[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (start == 10) start = 1;
            tab[x + (3 * i)][y + (3 * j)] = start++;
        }
    }
}