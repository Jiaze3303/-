#pragma once
#ifndef BOX_BINARYSEARCHTREE_H
#define BOX_BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <iostream>
#include <fstream>

struct BinarySearchTree {
    TreeNode* root; // ����

    BinarySearchTree() {
        root = nullptr;
    };

    // ����ֵΪvalue�ڵ�
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

    // ��ptrΪ�������ϵ����ڵ�
    TreeNode* max_node(TreeNode*& ptr) {
        // �пմ���
        if (ptr == nullptr) return nullptr;
        TreeNode* max = ptr;
        // һֱ����������
        while (max->rSon != nullptr) max = max->rSon;
        return max;
    }

    // ���ز�С��value�Ľڵ��ָ��
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

    // ���ش���value�Ľڵ��ָ��
    TreeNode* upper_bound(TreeNode*& ptr, int value) {
        if (ptr == nullptr) return nullptr;
        if (ptr->value <= value) return upper_bound(ptr->rSon, value);
        else {
            TreeNode* ceiling = upper_bound(ptr->lSon, value);
            return ceiling ? ceiling : ptr;
        }
    }

    // �ҵ�key�ĸ���
    TreeNode* find_father(TreeNode*& ptr, TreeNode*& key) {
        if (ptr == nullptr) return nullptr;
        //        std::cout << ptr << ' ' << ptr->value << std::endl;
        if (ptr->lSon == key || ptr->rSon == key) return ptr;
        if (key->value <= ptr->value) find_father(ptr->lSon, key);
        else find_father(ptr->rSon, key);
    }

    // ɾ��ָ��Ϊptr�Ľڵ�
    void erase(TreeNode*& ptr) {
        // �пմ���
        if (ptr != nullptr) {
            // ��ָ�붼Ϊ�գ��ҵ����ĸ��ף������Ӧָ����Ϊ��
            if (ptr->lSon == nullptr && ptr->rSon == nullptr) {
                //                std::cout << "erase: " << ptr->value << std::endl;
                TreeNode* father = find_father(root, ptr);
                //                std::cout << "father: " << father->value << std::endl;
                if (father) {
                    if (father->lSon == ptr) father->lSon = nullptr;
                    else father->rSon = nullptr;
                }
            }
            else if (ptr->rSon == nullptr) ptr = ptr->lSon; // �Һ���Ϊ�գ�ֱ����Ϊ������
            else if (ptr->lSon == nullptr) ptr = ptr->rSon; // ����Ϊ�գ�ֱ����Ϊ���Һ���
            else {
                TreeNode* ceiling = upper_bound(ptr, ptr->value); // �ҵ���ptr->value��ĵ�һ���ڵ�
//                std::cout << ceiling->value << std::endl;
                int edit = ceiling->value;
                erase(ceiling); // �ݹ�ɾ��ԭ���Ľڵ�
                ptr->value = edit; // �滻����ֵ
            }
        }
    }

    // ����һ����Ʒ
    void put(int value) {
        std::cout << "���ڷ�������Ϊ" << value << "����Ʒ..." << std::endl;
        // �ҵ��÷ŵ�����ceiling
        TreeNode* ceiling = lower_bound(root, value);
        std::cout << "���ҵ����ʵ�ʣ������Ϊ" << ceiling->value << "������" << std::endl;
        // �����µĽڵ㣬�������֮������ӣ�����Ӧ��Ϊ֮ǰ������-��Ʒ����
        if (ceiling->value - value > 0) insert(ceiling->value - value);
        std::cout << "��Ʒ�ѷ��룬��������ʣ������Ϊ" << ceiling->value - value << std::endl;
        // ɾ��ԭ��������
        erase(ceiling);
    }

    // �ļ������з�����Ʒ
    void file_put(int value) {
        std::ofstream out("out.txt", std::ios::app);
        out << "���ڷ�������Ϊ" << value << "����Ʒ..." << std::endl;
        TreeNode* ceiling = lower_bound(root, value);
        out << "���ҵ����ʵ�ʣ������Ϊ" << ceiling->value << "������" << std::endl;
        if (ceiling->value - value > 0) insert(ceiling->value - value);
        out << "��Ʒ�ѷ��룬��������ʣ������Ϊ" << ceiling->value - value << std::endl;
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
