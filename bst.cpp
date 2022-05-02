#include <iostream>
struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *FindMin(Node *root)
{
    Node *node = root;

    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
void Insert(Node *&root, int data)
{
    if (root == NULL)
    {
        Node *node = new Node;
        node->data = data;
        root = node;
        return;
    }
    else if (data == root->data)
    {
        std::cout << "\nData aleady exists";
        return;
    }
    else if (data < root->data)
    {
        Insert(root->left, data);
    }
    else
    {
        Insert(root->right, data);
    }
}
void Traversal(std::string str, Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (str == "preorder")
    {
        std::cout << root->data << " ";
        Traversal(str, root->left);
        Traversal(str, root->right);
    }

    else if (str == "inorder")
    {
        Traversal(str, root->left);
        std::cout << root->data << " ";
        Traversal(str, root->right);
    }
    else if (str == "postorder")
    {
        Traversal(str, root->left);
        Traversal(str, root->right);
        std::cout << root->data << " ";
    }
    else
    {
        std::cout << "\nInvalid!";
    }
}
void Search(Node *root, int data)
{
    if (root == NULL)
    {
        std::cout << "\nData not found!";
        return;
    }
    if (data == root->data)
    {
        std::cout << "\nData found!";
        return;
    }
    else if (data > root->data)
    {
        Search(root->right, data);
    }
    else
    {
        Search(root->left, data);
    }
}
void predSuc(Node *root, Node *&pred, Node *&suc, int data)
{
    if (root == NULL)
        return;
    else if (data == root->data)
    {
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pred = temp;
        }
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }
    else if (data < root->data)
    {
        suc = root;
        predSuc(root->left, pred, suc, data);
    }
    else
    {
        pred = root;
        predSuc(root->right, pred, suc, data);
    }
}
Node *Delete(Node *root, int data)
{
    if (root == NULL)
    {
        std::cout << "\nData not found";
    }
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            delete temp;
            temp = NULL;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            delete temp;
            temp = NULL;
        }
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    Node *pred = NULL;
    Node *suc = NULL;
    int x, value;
    while (1)
    {
        std::cout << "\n1.Insertion\n2.Search\n3.Traversal\n4.Predecessor and Successor\n5.Deletion\nChoose:";
        std::cin >> x;
        if (x == 1)
        {
            std::cout << "\nEnter data:";
            std::cin >> value;
            Insert(root, value);
        }
        else if (x == 2)
        {
            std::cout << "\nEnter data:";
            std::cin >> value;
            Search(root, value);
        }
        else if (x == 3)
        {
            if (root == NULL)
            {
                std::cout << "\nTree is empty!";
            }
            Traversal("inorder", root);
        }
        else if (x == 4)
        {
            std::cout << "\nEnter data:";
            std::cin >> value;
            predSuc(root, pred, suc, value);
            std::cout << "\nPredecessor:" << pred->data << "\nSuccessor:" << suc->data;
        }
        else if (x == 5)
        {
            std::cout << "\nEnter data:";
            std::cin >> value;
            root = Delete(root, value);
        }
        else
        {
            exit(0);
        }
    }
    return 0;
}