// FarazHayder_I222687_SajadAhmed_K224826
#include <iostream>
using namespace std;

// Binary Tree code:
struct TreeNode
{
    string name;
    int score;
    TreeNode *left;
    TreeNode *right;
};
class BinaryTree
{
private:
    TreeNode *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    TreeNode *getRoot()
    {
        return root;
    }

    void setRoot(TreeNode *root)
    {
        this->root = root;
    }

    TreeNode *createNode(string name, int score)
    {
        TreeNode *newNode = new TreeNode();
        newNode->name = name;
        newNode->score = score;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void insertNode(string name, int score)
    {
        TreeNode *newNode = createNode(name, score);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        TreeNode *temp = root;
        while (temp != nullptr)
        {
            if (score < temp->score)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else if (score >= temp->score)
            {
                if (score == temp->score)
                {
                    // Handle duplicates (place to the right, for example)
                    if (temp->right == nullptr)
                    {
                        temp->right = newNode;
                        return;
                    }
                    temp = temp->right;
                }
                else
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newNode;
                        return;
                    }
                    temp = temp->right;
                }
            }
        }
    }
    void clearHelper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        clearHelper(node->left);
        clearHelper(node->right);

        delete node;
    }

    void clear()
    {
        clearHelper(root);
        root = nullptr;
    }

    void displayHelper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        displayHelper(node->right);
        cout << node->name << " ";
        cout << node->score << endl;
        displayHelper(node->left);
    }

    void display()
    {
        displayHelper(root);
        cout << endl;
    }
};