#include <iostream>
#include <queue>
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
void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        if (curr != NULL)
        {
            cout << curr->data << endl;
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    levelorder(root);
}