#include <iostream>
#include <memory>
#define N 7
struct Node
{
    int val;
    Node *l = NULL;
    Node *r = NULL;
};
int height(Node *root)
{
    if (!root)
        return -1;
    return std::max(height(root->l), height(root->r)) + 1;
}
int getBalance(Node *root)
{
    if (!root)
        return -1;
    return height(root->l) - height(root->r);
}
Node *FindMin(Node *root)
{
    Node *node = root;

    while (node->l != NULL)
    {
        node = node->l;
    }
    return node;
}
Node *rightRotate(Node *y)
{
    Node *x = y->l;
    Node *T2 = x->r;
    x->r = y;
    y->l = T2;
    return x;
}
Node *leftRotate(Node *y)
{
    Node *x = y->r;
    Node *T2 = x->l;
    x->l = y;
    y->r = T2;
    return x;
}
void preOrderBST(Node *root)
{
    if (!root)
        return;
    std::cout << root->val << " ";
    preOrderBST(root->l);
    preOrderBST(root->r);
}
void inOrderBST(Node *root)
{
    if (!root)
        return;
    preOrderBST(root->l);
    std::cout << root->val << " ";
    preOrderBST(root->r);
}
void postOrderBST(Node *root)
{
    if (!root)
        return;
    preOrderBST(root->l);
    preOrderBST(root->r);
    std::cout << root->val << " ";
}
void printBST(Node *root)
{
    int choice;
    std::cout << "\n1.Preorder\n2.Inorder\n3.Postorder\nEnter: ";
    std::cin >> choice;
    if (choice == 1)
    {
        preOrderBST(root);
    }
    else if (choice == 2)
    {
        inOrderBST(root);
    }
    else if (choice == 3)
    {
        postOrderBST(root);
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Please enter a valid value i.e. 1 or 2 or 3.";
    }
    return;
}
Node *insertNode(Node *root, int val)
{
    if (!root)
    {
        Node *temp = new Node;
        temp->val = val;
        return temp;
    }
    else if (val < root->val)
    {
        root->l = insertNode(root->l, val);
    }
    else if (val > root->val)
    {
        root->r = insertNode(root->r, val);
    }
    else
    {
        std::cout << "Value already exists" << std::endl;
        return root;
    }
    int bf = getBalance(root);
    if (bf > 1 && val < root->l->val)
        return rightRotate(root);
    if (bf < -1 && val > root->r->val)
        return leftRotate(root);
    if (bf > 1 && val > root->l->val)
    {
        root->l = leftRotate(root->l);
        return rightRotate(root);
    }
    if (bf < -1 && val < root->r->val)
    {
        root->r = rightRotate(root->r);
        return leftRotate(root);
    }
    return root;
}
Node *deleteNode(Node *root, int val)
{
    if (!root)
        return NULL;
    else if (val < root->val)
    {
        root->l = deleteNode(root->l, val);
    }
    else if (val > root->val)
    {
        root->r = deleteNode(root->r, val);
    }
    else if (val == root->val)
    {
        if (!root->l && !root->r)
        {
            root = NULL;
            delete root;
            return NULL;
        }
        else if (!root->l)
        {
            Node *temp = root->r;
            delete root;
            return temp;
        }
        else if (!root->r)
        {
            Node *temp = root->l;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = FindMin(root);
            root->val = temp->val;
            root->r = deleteNode(root->r, temp->val);
        }
    }
    else
    {
        std::cout << "Value doesn't exist in BST!" << std::endl;
        return root;
    }
    int bf = getBalance(root);

    if (bf == 2 && getBalance(root->l) >= 0)
        return rightRotate(root);

    else if (bf == 2 && getBalance(root->l) == -1)
    {
        root->l = leftRotate(root->l);
        return rightRotate(root);
    }
    else if (bf == -2 && getBalance(root->r) <= 0)
        return leftRotate(root);
    else if (bf == -2 && getBalance(root->r) == 1)
    {
        root->r = rightRotate(root->r);
        return leftRotate(root);
    }

    return root;
}
int main()
{
    Node *rt = NULL;
    for (int i = 1; i < N; i++)
    {
        rt = insertNode(rt, i);
        printBST(rt);
    }

    for (int i = 1; i < N; i++)
    {
        rt = deleteNode(rt, i);
        printBST(rt);
    }
    delete rt;
    return 0;
}
