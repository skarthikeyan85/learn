#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} bst_node;

void preOrder(struct node *root)
{
    if (!root)
        return;

    printf ("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root)
{
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf ("%d ", root->data);
}

void inOrder(struct node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    printf ("%d ", root->data);        
    inOrder(root->right);
}

struct node *newNode(int data)
{
    struct node *node = (struct node *)calloc(sizeof(struct node), 1);

    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void insert(struct node **node, int data)
{
    if (*node == NULL) {
        *node = newNode(data);
    } else if ((*node)->data > data) {
        insert(&(*node)->left, data);
    } else {
        insert(&(*node)->right, data);
    }
}

struct node *search_util(struct node *node, int data, struct node **par)
{
    if (!node) {
        return node;
    }
    if (node->data == data) {
        return node;
    }

    if (node->data > data) {
        *par = node;
        return search_util(node->left, data, par);
    } else {
        *par = node;
        return search_util(node->right, data, par);
    }
}

struct node *search(struct node *node, int data, struct node **par)
{
    *par = NULL;
    return search_util(node, data, par);
}

struct node *findMinNode(struct node *node)
{
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
 
struct node *delete_bst(struct node *node, int key)
{
    struct node *temp;

    if (node == NULL) {
        return node;
    } 
    
    if (node->data > key) {
        node->left = delete_bst(node->left, key);
    } else if (node->data < key) {
        node->right = delete_bst(node->right, key);
    } else {
        if (node->left == NULL) {
            temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            temp = node->left;
            free(node);
            return temp;
        }
        temp = findMinNode(node->right);
        node->data = temp->data;
        node->right = delete_bst(node->right,  temp->data);
    }

    return node;
}

int count(struct node *node)
{
    if (!node) {
        return 0;
    }
    return (count(node->left) + count(node->right) + 1);
}

void preOrderNonRec(bst_node *root)
{
    if (!root)
        return;

    stack<bst_node *> s;
    s.push(root);
    while (!s.empty()) {
        root = s.top();
        cout << root->data << ' ';
        s.pop();
        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);
    }
    return;
}

void inOrderNonRec(bst_node *node)
{
    stack<bst_node *> s;

    while (true) {
        if (node) {
            s.push(node);
            node = node->left;
        } else {
            if (s.empty())
                break;
            node = s.top();
            cout << node->data << ' ';
            s.pop();
            node = node->right;
        }
    }

    return;
}

void postOrderNonRec(bst_node *node)
{
    stack<bst_node *> si;
    stack<bst_node *> so;

    si.push(node);
    while (!si.empty()) {
        node = si.top();
        si.pop();
        so.push(node);
        if (node->left) {
            si.push(node->left);
        }
        if (node->right) {
            si.push(node->right);
        }
    }

    while (!so.empty()) {
        node = so.top();
        so.pop();
        cout << node->data << ' ';
    }

    return;
}

int main()
{
    struct node *root = NULL;
    struct node *par = NULL;
    struct node *ans = NULL;
    int num = 0;

    insert(&root, 13);
    insert(&root, 14);
    insert(&root, 11);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 23);
    insert(&root, 24);
    insert(&root, 21);

    cout << "inorder: " << endl;
    inOrder(root);
    cout << endl;

    cout << "inorder nonrec: " << endl;
    inOrderNonRec(root);
    cout << endl;

    cout << "postorder: " << endl;
    postOrder(root);
    cout << endl;

    cout << "postorderNonRec: " << endl;
    postOrderNonRec(root);
    cout << endl;

    num = 11;
    ans = search(root, num, &par);
    printf("search: %d,%p,%p,%d\n", num, ans, par, par->data);

    root = delete_bst(root, 13);
    root = delete_bst(root, 14);
    root = delete_bst(root, 11);

    cout << "inorder: " << endl;
    inOrder(root);
    cout << endl;
    cout << "preorder: " << endl;
    preOrder(root);
    cout << endl;
    cout << "preorder nonrec: " << endl;
    preOrderNonRec(root);
    cout << endl;

    printf("count: %d\n", count(root));
    return 0;
}

