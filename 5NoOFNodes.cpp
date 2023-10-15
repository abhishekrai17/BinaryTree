#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int number = countNodes(root->left) + countNodes(root->right) + 1;
    return number;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int result = countNodes(root);
    cout << "The number of node in the tree is : " << result << endl;
}