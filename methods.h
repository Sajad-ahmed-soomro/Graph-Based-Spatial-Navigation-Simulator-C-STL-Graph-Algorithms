// FarazHayder_I222687_SajadAhmed_K224826
#include "header.h"

// Constructor implementation
Graph::Graph(int r, int c)
{
    rows = r;
    columns = c;
    numVertices = rows * columns;
    cRow = 0;
    cColumn = 1;
    menu = false;
    maze.resize(rows, vector<Node>(columns));
    adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0)); // Initialize with 0
}

// Make the maze
void Graph::initializeMazeEasy()
{
    queue<char> gameElements;
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');

    // Initialize the maze with '-'
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; j++)
        {
            maze[i][j].type = '-';
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        if (i < 5)
        {
            maze[i][4].type = ' ';
            maze[i][5].type = ' ';
        }
        if ((i < 2) || (i > 2 && i < 5))
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
        }
        if (i > 1 && i < 4)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
        }
        if (i >= 7 && i < 10)
        {
            maze[i][2].type = ' ';
        }
        if (i >= 5 && i < 10)
        {
            maze[i][2].type = ' ';
            maze[i][14].type = ' ';
        }
        if (i >= 4 && i < 8)
        {
            maze[i][0].type = ' ';
        }
        if (i >= 6 && i < 9)
        {
            maze[i][4].type = ' ';
            maze[i][6].type = ' ';
        }
        if (i == 6)
        {
            maze[i][5].type = ' ';
        }
        if (i >= 6 && i < 9)
        {
            maze[i][16].type = ' ';
            maze[i][18].type = ' ';
        }
        if (i == 6)
        {
            maze[i][17].type = ' ';
        }
        if (i >= 0 && i < 3)
        {
            maze[i][17].type = ' ';
            maze[i][19].type = ' ';
        }
        if (i == 0)
        {
            maze[i][18].type = ' ';
        }
        if (i == 1)
        {
            maze[i][14].type = ' ';
            maze[i][15].type = ' ';
            maze[i][16].type = ' ';
        }
        if (i == 5)
        {
            maze[i][6].type = ' ';
        }
        if (i == 2)
        {
            maze[i][1].type = ' ';
            maze[i][2].type = ' ';
            maze[i][3].type = ' ';
        }
        if (i == 3)
        {
            maze[i][14].type = ' ';
            maze[i][16].type = ' ';
        }
        if (i == 4)
        {
            maze[i][2].type = ' ';
        }
        if (i == 9)
        {
            maze[i][18].type = ' ';
        }
        if (i == 5)
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
        }
        if (i > 5 && i < 9)
        {
            maze[i][8].type = ' ';
        }
        if (i == 8)
        {
            maze[i][9].type = ' ';
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
        }
        if (i > 5 && i < 9)
        {
            maze[i][12].type = ' ';
        }
        if (i == 6)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
        }
        if (i == 4)
        {
            maze[i][12].type = ' ';
            maze[i][13].type = ' ';
        }
        if (i == 5)
        {
            maze[i][6].type = '-';
        }
        if (i == 8)
        {
            maze[i][14].type = '-';
        }
    }

    // Add the start and end points
    maze[0][0].type = 'S';
    maze[rows - 1][columns - 1].type = 'E';

    // Add the car
    maze[0][1].type = 'C';

    // Add the obstacles and power-ups
    srand(time(0));
    int randomIndex;
    for (int i = 0; i < gameElements.size(); ++i)
    {
        randomIndex = rand() % (rows * columns);
        int row = randomIndex / columns;
        int col = randomIndex % columns;
        if (maze[row][col].type == '-')
        {
            maze[row][col].type = gameElements.front();
            gameElements.pop();
        }
        else
        {
            --i;
        }
    }
    addEdges();
}

void Graph::initializeMazeMedium()
{
    queue<char> gameElements;
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('#');

    // Initialize the maze with '-'
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; j++)
        {
            maze[i][j].type = '-';
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        if (i < 5)
        {
            maze[i][4].type = ' ';
            maze[i][5].type = ' ';
            maze[i][4 + 20].type = ' ';
            maze[i][5 + 20].type = ' ';
        }
        if ((i < 2) || (i > 2 && i < 5))
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
            maze[i][7 + 20].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i > 1 && i < 4)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i >= 7 && i < 10)
        {
            maze[i][2].type = ' ';
            maze[i][2 + 20].type = ' ';
        }
        if (i >= 5 && i < 10)
        {
            maze[i][2].type = ' ';
            maze[i][14].type = ' ';
            maze[i][2 + 20].type = ' ';
            maze[i][14 + 20].type = ' ';
        }
        if (i >= 4 && i < 8)
        {
            maze[i][0].type = ' ';
            maze[i][0 + 20].type = ' ';
        }
        if (i >= 6 && i < 9)
        {
            maze[i][4].type = ' ';
            maze[i][6].type = ' ';
            maze[i][4 + 20].type = ' ';
            maze[i][6 + 20].type = ' ';
        }
        if (i == 6)
        {
            maze[i][5].type = ' ';
            maze[i][5 + 20].type = ' ';
        }
        if (i >= 6 && i < 9)
        {
            maze[i][16].type = ' ';
            maze[i][18].type = ' ';
            maze[i][16 + 20].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 6)
        {
            maze[i][17].type = ' ';
            maze[i][17 + 20].type = ' ';
        }
        if (i >= 0 && i < 3)
        {
            maze[i][17].type = ' ';
            maze[i][19].type = ' ';
            maze[i][17 + 20].type = ' ';
            maze[i][19 + 20].type = ' ';
        }
        if (i == 0)
        {
            maze[i][18].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 1)
        {
            maze[i][14].type = ' ';
            maze[i][15].type = ' ';
            maze[i][16].type = ' ';
            maze[i][14 + 20].type = ' ';
            maze[i][15 + 20].type = ' ';
            maze[i][16 + 20].type = ' ';
        }
        if (i == 5)
        {
            maze[i][6].type = ' ';
            maze[i][6 + 20].type = ' ';
        }
        if (i == 2)
        {
            maze[i][1].type = ' ';
            maze[i][2].type = ' ';
            maze[i][3].type = ' ';
            maze[i][1 + 20].type = ' ';
            maze[i][2 + 20].type = ' ';
            maze[i][3 + 20].type = ' ';
        }
        if (i == 3)
        {
            maze[i][14].type = ' ';
            maze[i][16].type = ' ';
            maze[i][14 + 20].type = ' ';
            maze[i][16 + 20].type = ' ';
        }
        if (i == 4)
        {
            maze[i][2].type = ' ';
            maze[i][2 + 20].type = ' ';
        }
        if (i == 9)
        {
            maze[i][18].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 5)
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
            maze[i][7 + 20].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i > 5 && i < 9)
        {
            maze[i][8].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i == 8)
        {
            maze[i][9].type = ' ';
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][9 + 20].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i > 5 && i < 9)
        {
            maze[i][12].type = ' ';
            maze[i][12 + 20].type = ' ';
        }
        if (i == 6)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i == 4)
        {
            maze[i][12].type = ' ';
            maze[i][13].type = ' ';
            maze[i][12 + 20].type = ' ';
            maze[i][13 + 20].type = ' ';
        }
        if (i == 5)
        {
            maze[i][6].type = '-';
            maze[i][6 + 20].type = '-';
        }
        if (i == 8)
        {
            maze[i][14].type = '-';
            maze[i][14 + 20].type = '-';
        }
    }

    // Add the start and end points
    maze[0][0].type = 'S';
    maze[rows - 1][columns - 1].type = 'E';

    // Add the car
    maze[0][1].type = 'C';

    // Add the obstacles and power-ups
    srand(time(0));
    int randomIndex;
    for (int i = 0; i < gameElements.size(); ++i)
    {
        randomIndex = rand() % (rows * columns);
        int row = randomIndex / columns;
        int col = randomIndex % columns;
        if (maze[row][col].type == '-')
        {
            maze[row][col].type = gameElements.front();
            gameElements.pop();
        }
        else
        {
            --i;
        }
    }
    addEdges();
}

void Graph::initializeMazeHard()
{
    queue<char> gameElements;
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('*');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('#');
    gameElements.push('*');
    gameElements.push('*');

    // Initialize the maze with '-'
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; j++)
        {
            maze[i][j].type = '-';
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        if (i < 5)
        {
            maze[i][4].type = ' ';
            maze[i][5].type = ' ';
            maze[i][4 + 20].type = ' ';
            maze[i][5 + 20].type = ' ';
        }
        if ((i < 2) || (i > 2 && i < 5))
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
            maze[i][7 + 20].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i > 1 && i < 4)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i >= 7 && i < 10)
        {
            maze[i][2].type = ' ';
            maze[i][2 + 20].type = ' ';
        }
        if (i >= 5 && i < 10)
        {
            maze[i][2].type = ' ';
            maze[i][14].type = ' ';
            maze[i][2 + 20].type = ' ';
            maze[i][14 + 20].type = ' ';
        }
        if (i >= 4 && i < 8)
        {
            maze[i][0].type = ' ';
            maze[i][0 + 20].type = ' ';
        }
        if (i >= 6 && i < 9)
        {
            maze[i][4].type = ' ';
            maze[i][6].type = ' ';
            maze[i][4 + 20].type = ' ';
            maze[i][6 + 20].type = ' ';
        }
        if (i == 6)
        {
            maze[i][5].type = ' ';
            maze[i][5 + 20].type = ' ';
        }
        if (i >= 6 && i < 9)
        {
            maze[i][16].type = ' ';
            maze[i][18].type = ' ';
            maze[i][16 + 20].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 6)
        {
            maze[i][17].type = ' ';
            maze[i][17 + 20].type = ' ';
        }
        if (i >= 0 && i < 3)
        {
            maze[i][17].type = ' ';
            maze[i][19].type = ' ';
            maze[i][17 + 20].type = ' ';
            maze[i][19 + 20].type = ' ';
        }
        if (i == 0)
        {
            maze[i][18].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 1)
        {
            maze[i][14].type = ' ';
            maze[i][15].type = ' ';
            maze[i][16].type = ' ';
            maze[i][14 + 20].type = ' ';
            maze[i][15 + 20].type = ' ';
            maze[i][16 + 20].type = ' ';
        }
        if (i == 5)
        {
            maze[i][6].type = ' ';
            maze[i][6 + 20].type = ' ';
        }
        if (i == 2)
        {
            maze[i][1].type = ' ';
            maze[i][2].type = ' ';
            maze[i][3].type = ' ';
            maze[i][1 + 20].type = ' ';
            maze[i][2 + 20].type = ' ';
            maze[i][3 + 20].type = ' ';
        }
        if (i == 3)
        {
            maze[i][14].type = ' ';
            maze[i][16].type = ' ';
            maze[i][14 + 20].type = ' ';
            maze[i][16 + 20].type = ' ';
        }
        if (i == 4)
        {
            maze[i][2].type = ' ';
            maze[i][2 + 20].type = ' ';
        }
        if (i == 9)
        {
            maze[i][18].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 5)
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
            maze[i][7 + 20].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i > 5 && i < 9)
        {
            maze[i][8].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i == 8)
        {
            maze[i][9].type = ' ';
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][9 + 20].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i > 5 && i < 9)
        {
            maze[i][12].type = ' ';
            maze[i][12 + 20].type = ' ';
        }
        if (i == 6)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i == 4)
        {
            maze[i][12].type = ' ';
            maze[i][13].type = ' ';
            maze[i][12 + 20].type = ' ';
            maze[i][13 + 20].type = ' ';
        }
        if (i == 5)
        {
            maze[i][6].type = '-';
            maze[i][6 + 20].type = '-';
        }
        if (i == 8)
        {
            maze[i][14].type = '-';
            maze[i][14 + 20].type = '-';
        }
    }
    for (int i = 10; i < rows; ++i)
    {
        if (i < 5 + 10)
        {
            maze[i][4].type = ' ';
            maze[i][5].type = ' ';
            maze[i][4 + 20].type = ' ';
            maze[i][5 + 20].type = ' ';
        }
        if ((i < 2 + 10) || (i > 2 + 10 && i < 5 + 10))
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
            maze[i][7 + 20].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i > 1 + 10 && i < 4 + 10)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i >= 7 + 10 && i < 10 + 10)
        {
            maze[i][2].type = ' ';
            maze[i][2 + 20].type = ' ';
        }
        if (i >= 5 + 10 && i < 10 + 10)
        {
            maze[i][2].type = ' ';
            maze[i][14].type = ' ';
            maze[i][2 + 20].type = ' ';
            maze[i][14 + 20].type = ' ';
        }
        if (i >= 4 + 10 && i < 8 + 10)
        {
            maze[i][0].type = ' ';
            maze[i][0 + 20].type = ' ';
        }
        if (i >= 6 + 10 && i < 9 + 10)
        {
            maze[i][4].type = ' ';
            maze[i][6].type = ' ';
            maze[i][4 + 20].type = ' ';
            maze[i][6 + 20].type = ' ';
        }
        if (i == 6 + 10)
        {
            maze[i][5].type = ' ';
            maze[i][5 + 20].type = ' ';
        }
        if (i >= 6 + 10 && i < 9 + 10)
        {
            maze[i][16].type = ' ';
            maze[i][18].type = ' ';
            maze[i][16 + 20].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 6 + 10)
        {
            maze[i][17].type = ' ';
            maze[i][17 + 20].type = ' ';
        }
        if (i >= 0 + 10 && i < 3 + 10)
        {
            maze[i][17].type = ' ';
            maze[i][19].type = ' ';
            maze[i][17 + 20].type = ' ';
            maze[i][19 + 20].type = ' ';
        }
        if (i == 0 + 10)
        {
            maze[i][18].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 1 + 10)
        {
            maze[i][14].type = ' ';
            maze[i][15].type = ' ';
            maze[i][16].type = ' ';
            maze[i][14 + 20].type = ' ';
            maze[i][15 + 20].type = ' ';
            maze[i][16 + 20].type = ' ';
        }
        if (i == 5 + 10)
        {
            maze[i][6].type = ' ';
            maze[i][6 + 20].type = ' ';
        }
        if (i == 2 + 10)
        {
            maze[i][1].type = ' ';
            maze[i][2].type = ' ';
            maze[i][3].type = ' ';
            maze[i][1 + 20].type = ' ';
            maze[i][2 + 20].type = ' ';
            maze[i][3 + 20].type = ' ';
        }
        if (i == 3 + 10)
        {
            maze[i][14].type = ' ';
            maze[i][16].type = ' ';
            maze[i][14 + 20].type = ' ';
            maze[i][16 + 20].type = ' ';
        }
        if (i == 4 + 10)
        {
            maze[i][2].type = ' ';
            maze[i][2 + 20].type = ' ';
        }
        if (i == 9 + 10)
        {
            maze[i][18].type = ' ';
            maze[i][18 + 20].type = ' ';
        }
        if (i == 5 + 10)
        {
            maze[i][7].type = ' ';
            maze[i][8].type = ' ';
            maze[i][7 + 20].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i > 5 + 10 && i < 9 + 10)
        {
            maze[i][8].type = ' ';
            maze[i][8 + 20].type = ' ';
        }
        if (i == 8 + 10)
        {
            maze[i][9].type = ' ';
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][9 + 20].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i > 5 + 10 && i < 9 + 10)
        {
            maze[i][12].type = ' ';
            maze[i][12 + 20].type = ' ';
        }
        if (i == 6 + 10)
        {
            maze[i][10].type = ' ';
            maze[i][11].type = ' ';
            maze[i][10 + 20].type = ' ';
            maze[i][11 + 20].type = ' ';
        }
        if (i == 4 + 10)
        {
            maze[i][12].type = ' ';
            maze[i][13].type = ' ';
            maze[i][12 + 20].type = ' ';
            maze[i][13 + 20].type = ' ';
        }
        if (i == 5 + 10)
        {
            maze[i][6].type = '-';
            maze[i][6 + 20].type = '-';
        }
        if (i == 8 + 10)
        {
            maze[i][14].type = '-';
            maze[i][14 + 20].type = '-';
        }
    }

    // Add the start and end points
    maze[0][0].type = 'S';
    maze[rows - 1][columns - 1].type = 'E';

    // Add the car
    maze[0][1].type = 'C';

    // Add the obstacles and power-ups
    srand(time(0));
    int randomIndex;
    for (int i = 0; i < gameElements.size(); ++i)
    {
        randomIndex = rand() % (rows * columns);
        int row = randomIndex / columns;
        int col = randomIndex % columns;
        if (maze[row][col].type == '-')
        {
            maze[row][col].type = gameElements.front();
            gameElements.pop();
        }
        else
        {
            --i;
        }
    }
    addEdges();
}

// Display the maze
void Graph::displayMaze(bool shortcut)
{
    // For clearing screen
    CLEAR_SCREEN();

    if (shortcut)
    {
        // Store the path nodes in a vector and sort it
        vector<int> pathNodesVector;
        while (!pathNodes.empty())
        {
            pathNodesVector.push_back(pathNodes.top());
            pathNodes.pop();
        }
        sort(pathNodesVector.begin(), pathNodesVector.end());
        // Now making a queue of the path nodes so that I can pop the front element
        queue<int> pathNodesQueue;
        for (int i = 0; i < pathNodesVector.size(); ++i)
        {
            pathNodesQueue.push(pathNodesVector[i]);
        }
        // Display the maze
        for (int i = 0; i < rows; ++i)
        {
            cout << " ";
            for (int j = 0; j < columns; j++)
            {
                if (pathNodesQueue.front() / columns == i && pathNodesQueue.front() % columns == j)
                {
                    if (maze[i][j].type == '*')
                    {
                        cout << GREEN << maze[i][j].type << " ";
                    }
                    else if (maze[i][j].type == 'C')
                    {
                        cout << CYAN << maze[i][j].type << " ";
                    }
                    else if (maze[i][j].type == '-')
                    {
                        cout << YELLOW << maze[i][j].type << " ";
                    }
                    else if (maze[i][j].type == 'E')
                    {
                        cout << YELLOW << maze[i][j].type << " ";
                    }
                    else
                    {
                        cout << WHITE << maze[i][j].type << " ";
                    }
                    pathNodesQueue.pop();
                }
                else if (maze[i][j].type == '-')
                {
                    cout << MAGENTA << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == '#')
                {
                    cout << RED << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == '*')
                {
                    cout << GREEN << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == 'S' || maze[i][j].type == 'E')
                {
                    cout << YELLOW << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == 'C')
                {
                    cout << CYAN << maze[i][j].type << " ";
                }
                else
                {
                    cout << WHITE << maze[i][j].type << " ";
                }
            }
            cout << endl;
        }
    }
    else
    {
        // Display the maze
        for (int i = 0; i < rows; ++i)
        {
            cout << " ";
            for (int j = 0; j < columns; j++)
            {
                if (maze[i][j].type == '-')
                {
                    cout << MAGENTA << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == '#')
                {
                    cout << RED << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == '*')
                {
                    cout << GREEN << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == 'S' || maze[i][j].type == 'E')
                {
                    cout << YELLOW << maze[i][j].type << " ";
                }
                else if (maze[i][j].type == 'C')
                {
                    cout << CYAN << maze[i][j].type << " ";
                }
                else
                {
                    cout << WHITE << maze[i][j].type << " ";
                }
            }
            cout << endl;
        }
    }
}

// Method to add an edge between two vertices
// void Graph::addEdge(int source, int destination, Node node)
void Graph::addEdge(int source, int destination, char type)
{
    // Assuming undirected graph for simplicity
    adjacencyMatrix[source][destination] = type;
    adjacencyMatrix[destination][source] = type;
}

// Method to display the graph
void Graph::displayAdjacencyMatrix()
{
    for (int i = 0; i < numVertices; ++i)
    {
        cout << i << ": ";
        for (int j = 0; j < numVertices; ++j)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool Graph::dijkstraShortestPath(int start, int end)
{
    vector<int> distances;    // Store the distances from the start vertex
    vector<int> previousNode; // Store the previous node in the shortest path
    while (!pathNodes.empty())
    {
        pathNodes.pop(); // Emptying the already present path in it
    }

    // Initialize distances vector with infinity (INT_MAX) for all vertices
    distances.assign(numVertices, INT_MAX);
    previousNode.assign(numVertices, -1);

    // The distance from the start vertex to itself is 0
    distances[start] = 0;

    // Create a vector to keep track of visited vertices
    vector<bool> visited(numVertices, false);

    // Perform Dijkstra's algorithm
    for (int count = 0; count < numVertices - 1; ++count)
    {
        // Find the vertex with the minimum distance value
        int minDistance = INT_MAX, minIndex;
        for (int v = 0; v < numVertices; ++v)
        {
            if (!visited[v] && distances[v] <= minDistance)
            {
                minDistance = distances[v];
                minIndex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = true;

        // Update the distance value of the neighboring vertices
        for (int v = 0; v < numVertices; ++v)
        {
            if (!visited[v] && adjacencyMatrix[minIndex][v] && distances[minIndex] != INT_MAX &&
                distances[minIndex] + adjacencyMatrix[minIndex][v] < distances[v])
            {
                distances[v] = distances[minIndex] + adjacencyMatrix[minIndex][v];
                previousNode[v] = minIndex;
            }
        }
    }

    // Print the shortest path from S to E
    // cout << "Shortest path from S to E: " << distances[end] << endl; // For Testing

    // Print the nodes in the shortest path
    // cout << "Nodes in the path: "; // For Testing
    int currentNode = end;
    while (currentNode != -1)
    {
        pathNodes.push(currentNode);
        currentNode = previousNode[currentNode];
    }

    // while (!pathNodes.empty())
    // {
    //     cout << pathNodes.top() << " "; // For Testing
    //     pathNodes.pop();
    // }
    // cout << endl; // For Testing

    if (distances[end] == INT_MAX)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// MainMenu
void Graph::MainMenu(int difficulty)
{
    bool check = true;
    while (check)
    {
        // For clearing console screen
        CLEAR_SCREEN();

        // Create a new maze
        StartGame(difficulty);

        char option;
        cout << "\n                 <=============== Main Menu ================>" << endl
             << "\n                             '1' 'Manual Mode'" << endl
             << "                             '2' 'Automated Mode'" << endl
             << "                             '3' 'Leaderboard'" << endl
             << "                             '4' 'Go Back'" << endl;
        option = getch();

        while (!(option == '1' || option == '2' || option == '3' || option == '4'))
        {
            option = getch();
        }

        switch (option)
        {
        case '1':
            // For clearing console screen
            CLEAR_SCREEN();
            score = 0;
            ManualMode();
            break;

        case '2':
            // For clearing console screen
            CLEAR_SCREEN();
            score = 0;
            AutomatedMode();
            break;

        case '3':
            // For clearing console screen
            CLEAR_SCREEN();
            loadFromFileIntoTreeAndDisplay();
            Continue();
            break;

        case '4':
            // For clearing console screen
            system("cls");
            return;
        }
    }
    MainMenu(difficulty);
}
// Function to continue the program after a task is completed
void Graph::Continue()
{
    char ch;
    cout << "\nPress any key to continue..." << endl;
    ch = getch();

    // For clearing console screen
    CLEAR_SCREEN();
}

// Create the Maze
void Graph::StartGame(int difficulty)
{
    // Initialize the maze
    bool check = false;
    while (!check)
    {
        if (difficulty == 1)
        {
            initializeMazeEasy();
        }
        else if (difficulty == 2)
        {
            initializeMazeMedium();
        }
        else if (difficulty == 3)
        {
            initializeMazeHard();
        }
        // Check if the maze is solvable, if not, then re-initialize the maze
        check = dijkstraShortestPath(1, rows * columns - 1);
    }
}

void Graph::addEdges()
{
    // initializing adjacency matrix with 0
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < numVertices; ++i)
    {
        int adjacentToRight = i + 1;
        int adjacentToBelow = i + columns;

        // Check if adjacent to the right
        if (adjacentToRight % columns != 0)
        {
            if (pathExists(i) && pathExists(adjacentToRight))
            {
                addEdge(i, adjacentToRight, 1);
            }
        }

        // Check if adjacent below
        if (adjacentToBelow < numVertices)
        {
            if (pathExists(i) && pathExists(adjacentToBelow))
            {
                addEdge(i, adjacentToBelow, 1);
            }
        }
    }
}

bool Graph::pathExists(int index)
{
    int row = index / columns;
    int col = index % columns;

    if (maze[row][col].type == ' ' || maze[row][col].type == '#' || maze[row][col].type == 'S')
    {
        return false;
    }

    return true;
}

// Play the game in:-
// 1. Manual Mode
void Graph::ManualMode()
{
    gamePlay();
    Continue();
}
// 2. Automatic Mode
void Graph::AutomatedMode()
{
    automatedGamePlay();
    Continue();
}

// Method to move the player automatically
void Graph::automatedGamePlay()
{
    // Storing the pathNodes stack in a tempStack
    stack<int> tempStack = pathNodes;
    char option;
    while (true)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (i == tempStack.top() / columns && j == tempStack.top() % columns)
                {
                    maze[cRow][cColumn].type = '-';
                    cRow = i;
                    cColumn = j;
                    maze[i][j].type = 'C';
                    tempStack.pop();
                    if (tempStack.empty())
                    {
                        return;
                    }
                    dijkstraShortestPath(cRow * columns + cColumn, rows * columns - 1);
                    displayMaze(true);
                    Sleep(500);
                }
            }
        }
    }
}

// Method to move the player
void Graph::gamePlay()
{
    clock_t startTime = clock(); // Record the starting time
    char option;
    menu = false;
    bool shortcut = false;
    int seconds = 0;
    while (!menu)
    {
        displayMaze(shortcut);
        cout << endl;
        cout << "Score: " << score << endl;
        cout << "Your Trophies: "; // Displaying the char list using iterators
        for (list<char>::iterator it = powerUps.begin(); it != powerUps.end(); ++it)
        {
            cout << *it << " ";
        }
        shortcut = false;
        option = getch();
        if (option == 'w' || option == 'W' || option == 72)
        {
            moveUp();
        }
        else if (option == 's' || option == 'S' || option == 80)
        {
            menu = moveDown();
        }
        else if (option == 'a' || option == 'A' || option == 75)
        {
            moveLeft();
        }
        else if (option == 'd' || option == 'D' || option == 77)
        {
            menu = moveRight();
        }
        else if (option == 'p' || option == 'P' || option == 27)
        {
            shortcut = pauseMenu();
        }
    }
    loadFromFileIntoTreeAndDisplay();
}
void Graph::moveUp()
{
    if (cRow > 0)
    {
        if (maze[cRow - 1][cColumn].type == '*')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow - 1][cColumn].type = 'C';
            cRow--;
            score *= 2;
            powerUps.push_back('*');
        }
        else if (maze[cRow - 1][cColumn].type == '-')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow - 1][cColumn].type = 'C';
            cRow--;
            score++;
        }
        else if (maze[cRow - 1][cColumn].type == '#')
        {
            score /= 2;
        }
    }
}
bool Graph::moveDown()
{
    if (cRow < rows - 1)
    {
        if (maze[cRow + 1][cColumn].type == '*')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow + 1][cColumn].type = 'C';
            cRow++;
            score *= 2;
            powerUps.push_back('*');
        }
        else if (maze[cRow + 1][cColumn].type == '-')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow + 1][cColumn].type = 'C';
            cRow++;
            score++;
        }
        else if (maze[cRow + 1][cColumn].type == '#')
        {
            score /= 2;
        }
        else if (maze[cRow + 1][cColumn].type == 'E')
        {
            cout << "\nCongratulations! You have won the game!" << endl; // Calculate time elapsed
            clock_t currentTime = clock();
            double timeElapsed = static_cast<double>(currentTime - startTime) / CLOCKS_PER_SEC;
            timeElapsed /= 1000;
            if (timeElapsed < 1)
            {
                timeElapsed *= -1;
            }
            score /= timeElapsed;
            saveToFile(name, score);
            return true;
        }
    }
    return false;
}
bool Graph::moveRight()
{
    if (cColumn < columns - 1)
    {
        if (maze[cRow][cColumn + 1].type == '*')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow][cColumn + 1].type = 'C';
            cColumn++;
            score *= 2;
            powerUps.push_back('*');
        }
        else if (maze[cRow][cColumn + 1].type == '-')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow][cColumn + 1].type = 'C';
            cColumn++;
            score++;
        }
        else if (maze[cRow][cColumn + 1].type == '#')
        {
            score /= 2;
        }
        else if (maze[cRow][cColumn + 1].type == 'E')
        {
            cout << "\nCongratulations! You have won the game!" << endl; // Calculate time elapsed
            clock_t currentTime = clock();
            double timeElapsed = static_cast<double>(currentTime - startTime) / CLOCKS_PER_SEC;
            timeElapsed /= 1000;
            if (timeElapsed < 1)
            {
                timeElapsed *= -1;
            }
            score /= timeElapsed;
            saveToFile(name, score);
            return true;
        }
    }
    return false;
}
void Graph::moveLeft()
{
    if (cColumn > 0)
    {
        if (maze[cRow][cColumn - 1].type == '*')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow][cColumn - 1].type = 'C';
            cColumn--;
            score *= 2;
            powerUps.push_back('*');
        }
        else if (maze[cRow][cColumn - 1].type == '#')
        {
            score /= 2;
        }
        else if (maze[cRow][cColumn - 1].type == '-')
        {
            maze[cRow][cColumn].type = '-';
            maze[cRow][cColumn - 1].type = 'C';
            cColumn--;
            score++;
        }
    }
}
bool Graph::pauseMenu()
{
    // For clearing console screen
    system("cls");

    char option;
    cout << "\n                     <===================== Pause Menu =====================>" << endl
         << "\n                                           '1' 'Resume'" << endl
         << "                                           '2' 'Hint'" << endl
         << "                                           '3' 'Main Menu'" << endl;
    option = getch();

    while (!(option == '1' || option == '2' || option == '3'))
    {
        option = getch();
    }

    switch (option)
    {
    case '1':
        // For clearing console screen
        CLEAR_SCREEN();
        break;

    case '2':
        // For clearing console screen
        system("cls");
        dijkstraShortestPath(cRow * columns + cColumn, rows * columns - 1);
        return true;

    case '3':
        // For clearing console screen
        system("cls");
        menu = true;
        break;
    }
    return false;
}
void Graph::saveToFile(string name, int score)
{
    ofstream fout;
    fout.open("scores.txt", ios::app);
    fout << name << " " << score << endl;
    fout.close();
}
void Graph::loadFromFileIntoTreeAndDisplay()
{
    ifstream fin;
    fin.open("scores.txt");
    string name;
    int score;
    while (fin >> name >> score)
    {
        scoresTree.insertNode(name, score);
    }
    cout << "\nLeaderboard:- \n"
         << endl;
    scoresTree.display();
    fin.close();
}