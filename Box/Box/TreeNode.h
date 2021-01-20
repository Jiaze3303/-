#ifndef BOX_TREENODE_H
#define BOX_TREENODE_H


// TreeNode BST的节点，代表箱子
struct TreeNode {
    int value; // 箱子的剩余容量
    TreeNode* lSon, * rSon; // 左右孩子指针

    TreeNode() = default;

    TreeNode(int value) : value(value) {
        lSon = nullptr;
        rSon = nullptr;
    }

    TreeNode(int value, TreeNode* lSon, TreeNode* rSon) : value(value), lSon(lSon), rSon(rSon) {}
};


#endif //BOX_TREENODE_H
