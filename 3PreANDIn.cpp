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
int search(int inorder[], int start, int end, int key)
{
    for (int i = 0; i < end; i++)
    {
        if (inorder[i] == key)
        {
            return i;
        }
    }
    return -1;
}
node *buildtree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int key = preorder[idx];
    idx++;
    node *curr = new node(key);
    if (start == end)
    {
        return curr;
    }
    int pos = search(inorder, start, end, key);
    buildtree(preorder, inorder, start, pos - 1);
    buildtree(preorder, inorder, pos + 1, end);
    return curr;
}
void inorder1(node *root)
{
    if (root == NULL)
        return;

    inorder1(root->left);
    cout << root->data << endl;
    inorder1(root->right);
}
int main()
{
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    node *res = buildtree(preorder, inorder, 0, 4);
    inorder1(res);
}