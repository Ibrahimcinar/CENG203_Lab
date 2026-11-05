#include "TreeUtils.h"
#include <iostream>
#include <queue>                    // std::queue: the library version of
using namespace std;                // Week 4's Queue, for any type

TreeNode* makeNode(int value)
{
    TreeNode* node = new TreeNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// ============================ Q2 ============================
void preorder(const TreeNode* node)
{
    if (node == nullptr)            // empty tree: nothing to print
        return;
    cout << node->data << " ";      // visit
    preorder(node->left);
    preorder(node->right);
}

void inorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";      // visit
    inorder(node->right);
}

void postorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";      // visit
}

int countNodes(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;                   // a leaf counts itself
    return countLeaves(node->left) + countLeaves(node->right);
}

// ============================ Q3 ============================
int height(const TreeNode* node)
{
    if (node == nullptr)
        return -1;                  // empty tree: -1, so a leaf gets 0
    int hl = height(node->left);
    int hr = height(node->right);
    return 1 + (hl > hr ? hl : hr); // 1 + the taller subtree
}

void levelOrder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    queue<const TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        const TreeNode* cur = q.front();   // read first, pop returns nothing
        q.pop();
        cout << cur->data << " ";
        if (cur->left != nullptr)
            q.push(cur->left);
        if (cur->right != nullptr)
            q.push(cur->right);
    }
}

// ============================ Q6 ============================
bool isBalanced(const TreeNode* node)
{
    if (node == nullptr)
        return true;                // empty tree is balanced
    int diff = height(node->left) - height(node->right);
    if (diff > 1 || diff < -1)
        return false;
    return isBalanced(node->left) && isBalanced(node->right);
}

// ============================ memory ============================
void destroy(TreeNode* node)
{
    if (node == nullptr)
        return;
    destroy(node->left);            // children first ...
    destroy(node->right);
    delete node;                    // ... the node last (postorder)
}
