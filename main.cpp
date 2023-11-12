#include <stdlib.h>
#include <iostream>
#include <vector>


class node
{
public:
    int input;
    node* left, * right;
    node(int input)
    {
        this->input = input;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class myTree
{
private:

public:
    node* root;
    myTree()
    {
        this->root = nullptr;
    }
    ~myTree()
    {
        delete root;
    }
    node* find(int input)
    {
        node* treeIterator = root;
        while (treeIterator != nullptr)
        {
            if (treeIterator->input == input)
            {
                return treeIterator;
            }
            else if (treeIterator->input > input) {
                treeIterator = treeIterator->left;
            }
            else {
                treeIterator = treeIterator->right;
            }
        }
        return nullptr;
    }

    int size(node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return 1 + size(node->left) + size(node->right);
    }

    void deleteTree(node* node)
    {
        if (node == nullptr) return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }

    void inOrder(node* node, std::vector<int>& arr)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left, arr);
        arr.push_back(node->input);
        inOrder(node->right, arr);
    }

    void reverseInOrder(node* node, std::vector<int>& arr) {
        if (node == nullptr) {
            return;
        }
        reverseInOrder(node->right, arr);
        arr.push_back(node->input);
        reverseInOrder(node->left, arr);
    }

    void insert(int input)
    {
        if (this->root == nullptr)
        {
            this->root = new node(input);
            return;
        }
        node* cur = this->root;
        while (cur != nullptr)
        {
            if (input < cur->input)
            {
                if (cur->left == nullptr)
                {
                    cur->left = new node(input);
                    return;
                }
                cur = cur->left;
            }
            else {
                if (cur->right == nullptr)
                {
                    cur->right = new node(input);
                    return;
                }
                cur = cur->right;
            }
        }
    }

    node* remove(int input)
    {
        node* treeIterator = root;
        node* parent = nullptr;
        while (treeIterator != nullptr)
        {
            if (treeIterator->input == input)
            {
                break;
            }
            else if (treeIterator->input > input)
            {
                parent = treeIterator;
                treeIterator = treeIterator->left;
            }
            else {
                parent = treeIterator;
                treeIterator = treeIterator->right;
            }
        }
        if (treeIterator == nullptr)
        {
            return nullptr;
        }
        if (treeIterator->left == nullptr && treeIterator->right == nullptr)
        {
            if (parent == nullptr) {
                root = nullptr;
            }
            else if (parent->left == treeIterator)
            {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        else if (treeIterator->left == nullptr)
        {
            if (parent == nullptr)
            {
                root = treeIterator->right;
            }
            else if (parent->left == treeIterator)
            {
                parent->left = treeIterator->right;
            }
            else
            {
                parent->right = treeIterator->right;
            }
        }
        else if (treeIterator->right == nullptr)
        {
            if (parent == nullptr)
            {
                root = treeIterator->left;
            }
            else if (parent->left == treeIterator)
            {
                parent->left = treeIterator->left;
            }
            else
            {
                parent->right = treeIterator->left;
            }
        }
        else
        {
            node* temp = treeIterator->right;
            node* tempParent = treeIterator;
            while (temp->left != nullptr)
            {
                tempParent = temp;
                temp = temp->left;
            }
            treeIterator->input = temp->input;
            if (tempParent->left == temp)
            {
                tempParent->left = temp->right;
            }
            else
            {
                tempParent->right = temp->right;
            }
            treeIterator = temp;
        }
        return treeIterator;
    }

    void print(node* root, int space)
    {
        if (root == NULL) return;
        space += 10;
        print(root->right, space);
        std::cout << std::endl;
        for (int i = 10; i < space; i++) std::cout << " ";
        std::cout << root->input << "\n";
        print(root->left, space);
    }
    void printWrap(node *root)
    {
        this->print(root, 0);
    }
};

void uiHandler() {
    myTree* tree = new myTree();

    int num;
    std::cout << "How many numbers to insert? ";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        int input;
        std::cout << "Enter number: ";
        std::cin >> input;
        tree->insert(input);
    }
    std::cout << "Current Tree: " << std::endl;
    tree->printWrap(tree->root);


    bool treeExists = false;
    char choice;
    int input;
    std::vector<int> arr;
    while (!treeExists)
    {
        std::cout << "Options:\n"
                     "a: print in order traversal\n"
                     "b: print reverse order traversal\n"
                     "i: insert a input\n"
                     "r: remove a input\n"
                     "p: print tree\n"
                     "anything else: exit\n";
        std::cin >> choice;
        switch (choice)
        {
            case 'a':
                tree->inOrder(tree->root, arr);
                std::cout << "\nPrinting in order traversal: ";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
                break;
            case 'b':
                tree->reverseInOrder(tree->root, arr);
                std::cout << "\nPrinting reverse order traversal: ";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
                break;
            case 'i':
                int input;
                std::cout << "\ninput to insert to tree: ";
                std::cin >> input;
                tree->insert(input);
                std::cout << "\nNumber inserted" << std::endl;
                break;
            case 'r':
                std::cout << "\nInput to delete from tree: ";
                std::cin >> input;
                tree->remove(input);
                std::cout << "\nValue deleted" << std::endl;
                break;
            case 'p':
                tree->printWrap(tree->root);
                break;
            default:
                tree->deleteTree(tree->root);
                std::cout << "\nTree deleted, exiting program." << std::endl;
                treeExists = true;
                break;
        }
    }
    if (!treeExists)
    {
        delete tree;
    }




}

int main()
{
    uiHandler();
}

