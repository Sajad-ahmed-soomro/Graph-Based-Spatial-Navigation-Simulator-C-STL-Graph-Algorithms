// FarazHayder_I222687_SajadAhmed_K224826
#include "methods.h"

int main()
{
    int *arr = new int[3];
    while (true)
    {
        arr = carMazeGame();
        Graph Game(arr[0], arr[1]);
        cout << "\n                       Enter your Name: ";
        cin >> Game.name;
        Game.MainMenu(arr[2]);
    }
    return 0;
}

int *carMazeGame()
{
    int *arr = new int[3];
    bool check = true;
    while (check)
    {
        // For clearing console screen
        CLEAR_SCREEN();

        char option;
        cout << "\n          <========== Welcome To Car Maze Game ==========>" << endl;
        cout << "\n                           '1' Easy" << endl;
        cout << "                           '2' Medium" << endl;
        cout << "                           '3' Hard" << endl;
        cout << "\n                           'ESC' QUIT" << endl;
        option = getch();

        while (!(option == '1' || option == '2' || option == '3' || option == '\x1B'))
        {
            option = getch();
        }

        switch (option)
        {
        case '1':
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 1;
            return arr;

        case '2':
            arr[0] = 10;
            arr[1] = 40;
            arr[2] = 2;
            return arr;

        case '3':
            arr[0] = 20;
            arr[1] = 40;
            arr[2] = 3;
            return arr;

        case '\x1B':
            exit(0);
        }
    }
    carMazeGame();
}
