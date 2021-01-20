#ifndef BOX_TREENODE_H
#define BOX_TREENODE_H


// TreeNode BST�Ľڵ㣬��������
struct TreeNode {
    int value; // ���ӵ�ʣ������
    TreeNode* lSon, * rSon; // ���Һ���ָ��

    TreeNode() = default;

    TreeNode(int value) : value(value) {
        lSon = nullptr;
        rSon = nullptr;
    }

    TreeNode(int value, TreeNode* lSon, TreeNode* rSon) : value(value), lSon(lSon), rSon(rSon) {}
};


#endif //BOX_TREENODE_H
