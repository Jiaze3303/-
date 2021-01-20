#pragma once
#ifndef BOX_BINARYSEARCHTREE_H
#define BOX_BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <iostream>
#include <fstream>

struct BinarySearchTree {
    TreeNode* root; // 树根

    BinarySearchTree() {
        root = nullptr;
    };

    // 插入值为value节点
    void dfs_insert(TreeNode*& ptr, int value) {
        //        std::cout << ptr << std::endl;
        if (ptr == nullptr) {
            ptr = new TreeNode(value);
            return;
        }
        if (value <= ptr->value) dfs_insert(ptr->lSon, value);
        else dfs_insert(ptr->rSon, value);
    }

    void insert(int value) {
        dfs_insert(root, value);
    }

    // 以ptr为根的树上的最大节点
    TreeNode* max_node(TreeNode*& ptr) {
        // 判空处理
        if (ptr == nullptr) return nullptr;
        TreeNode* max = ptr;
        // 一直向右子树走
        while (max->rSon != nullptr) max = max->rSon;
        return max;
    }

    // 返回不小于value的节点的指针
    TreeNode* lower_bound(TreeNode*& ptr, int value) {
        //        std::cout << ptr << ' ' << ptr->value << std::endl;
        if (ptr == nullptr) return nullptr;
        if (ptr->value == value) return ptr;
        else if (ptr->value < value) {
            return lower_bound(ptr->rSon, value);
        }
        else {
            //            std::cout << "---!!!\n";
            //            std::cout << ptr->lSon << std::endl;
            TreeNode* ceiling = max_node(ptr->lSon);
            //            std::cout << "ceiling: " << ceiling << std::endl;
            if (ceiling == nullptr) return ptr;
            if (ceiling->value < value) return ptr;
            else return lower_bound(ptr->lSon, value);
        }
    }

    // 返回大于value的节点的指针
    TreeNode* upper_bound(TreeNode*& ptr, int value) {
        if (ptr == nullptr) return nullptr;
        if (ptr->value <= value) return upper_bound(ptr->rSon, value);
        else {
            TreeNode* ceiling = upper_bound(ptr->lSon, value);
            return ceiling ? ceiling : ptr;
        }
    }

    // 找到key的父亲
    TreeNode* find_father(TreeNode*& ptr, TreeNode*& key) {
        if (ptr == nullptr) return nullptr;
        //        std::cout << ptr << ' ' << ptr->value << std::endl;
        if (ptr->lSon == key || ptr->rSon == key) return ptr;
        if (key->value <= ptr->value) find_father(ptr->lSon, key);
        else find_father(ptr->rSon, key);
    }

    // 删除指针为ptr的节点
    void erase(TreeNode*& ptr) {
        // 判空处理
        if (ptr != nullptr) {
            // 两指针都为空，找到他的父亲，将其对应指针置为空
            if (ptr->lSon == nullptr && ptr->rSon == nullptr) {
                //                std::cout << "erase: " << ptr->value << std::endl;
                TreeNode* father = find_father(root, ptr);
                //                std::cout << "father: " << father->value << std::endl;
                if (father) {
                    if (father->lSon == ptr) father->lSon = nullptr;
                    else father->rSon = nullptr;
                }
            }
            else if (ptr->rSon == nullptr) ptr = ptr->lSon; // 右孩子为空，直接设为其左孩子
            else if (ptr->lSon == nullptr) ptr = ptr->rSon; // 左孩子为空，直接设为其右孩子
            else {
                TreeNode* ceiling = upper_bound(ptr, ptr->value); // 找到比ptr->value大的第一个节点
//                std::cout << ceiling->value << std::endl;
                int edit = ceiling->value;
                erase(ceiling); // 递归删除原来的节点
                ptr->value = edit; // 替换它的值
            }
        }
    }

    // 放入一个物品
    void put(int value) {
        std::cout << "正在放入重量为" << value << "的物品..." << std::endl;
        // 找到该放的箱子ceiling
        TreeNode* ceiling = lower_bound(root, value);
        std::cout << "已找到合适的剩余容量为" << ceiling->value << "的箱子" << std::endl;
        // 插入新的节点，代表放完之后的箱子，容量应该为之前的容量-物品重量
        if (ceiling->value - value > 0) insert(ceiling->value - value);
        std::cout << "物品已放入，放入后盒子剩余容量为" << ceiling->value - value << std::endl;
        // 删除原来的箱子
        erase(ceiling);
    }

    // 文件处理中放入物品
    void file_put(int value) {
        std::ofstream out("out.txt", std::ios::app);
        out << "正在放入重量为" << value << "的物品..." << std::endl;
        TreeNode* ceiling = lower_bound(root, value);
        out << "已找到合适的剩余容量为" << ceiling->value << "的箱子" << std::endl;
        if (ceiling->value - value > 0) insert(ceiling->value - value);
        out << "物品已放入，放入后盒子剩余容量为" << ceiling->value - value << std::endl;
        erase(ceiling);
        out.close();
    }

    void print_pre_order(TreeNode* ptr) {
        if (ptr == nullptr) return;
        std::cout << ptr->value << std::endl;
        print_pre_order(ptr->lSon);
        print_pre_order(ptr->rSon);
    }
};


#endif //BOX_BINARYSEARCHTREE_H
