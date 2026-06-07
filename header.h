// FarazHayder_I222687_SajadAhmed_K224826
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <cstdlib>   // For srand and rand
#include <ctime>     // For time
#include <algorithm> // For sort
#include <fstream>   // For file handling
#include "trees.h"

// Platform-specific replacements for Windows-only APIs
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#else
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <chrono>

static int getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

static void Sleep(unsigned int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

#define CLEAR_SCREEN() system("clear")
#endif

using namespace std;

// ANSI escape codes for text color
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

int *carMazeGame();

struct Node
{
    char type;
};

class Graph
{
    // private:
public:
    int rows, columns;
    int cRow, cColumn; // Current row and column of the car (player)
    int numVertices;   // Total number of vertices in the graph
    bool menu;         // Helps traversing to the Main Menu from the game
    vector<vector<Node>> maze;
    vector<vector<int>> adjacencyMatrix;
    stack<int> pathNodes; // Store the nodes in the shortest path
    string name;
    int score;
    list<char> powerUps;
    BinaryTree scoresTree;
    clock_t startTime;

public:
    // Constructor
    Graph(int r, int c);

    // MainMenu
    void MainMenu(int difficulty);
    void Continue();

    // Create a new Maze
    void StartGame(int difficulty);
    void initializeMazeEasy();
    void initializeMazeMedium();
    void initializeMazeHard();
    void addEdges(); // Add edges to the graph
    // Method to add an edge between two vertices
    void addEdge(int source, int destination, char type);
    // Method to check if the node is a valid node in the maze
    bool pathExists(int index);

    // Play the game in:-
    // 1. Manual Mode
    void ManualMode();
    // Method to move the player
    void gamePlay();
    void moveUp();
    bool moveDown();
    void moveLeft();
    bool moveRight();
    bool pauseMenu();

    void saveToFile(string name, int score);
    void loadFromFileIntoTreeAndDisplay();

    // 2. Automatic Mode
    void AutomatedMode();
    // Method to move the player automatically
    void automatedGamePlay();

    // Display the maze
    void displayMaze(bool shortcut);

    void displayAdjacencyMatrix();
    bool dijkstraShortestPath(int start, int end);
};