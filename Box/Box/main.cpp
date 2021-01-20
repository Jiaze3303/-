#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

void test() {
    BinarySearchTree binarySearchTree;
    binarySearchTree.insert(53);
    binarySearchTree.insert(17);
    binarySearchTree.insert(78);
    binarySearchTree.insert(9);
    binarySearchTree.insert(45);
    binarySearchTree.insert(23);
    binarySearchTree.insert(65);
    binarySearchTree.insert(87);
    binarySearchTree.insert(87);
    cout << binarySearchTree.lower_bound(binarySearchTree.root, 80)->value << endl;
    cout << "-----\n";
    binarySearchTree.print_pre_order(binarySearchTree.root);
    cout << "-----\n";
    binarySearchTree.erase(binarySearchTree.root);
    cout << binarySearchTree.root->value << endl;
    cout << "-----\n";
    binarySearchTree.print_pre_order(binarySearchTree.root);
    cout << "-----\n";
    binarySearchTree.put(52);
    cout << binarySearchTree.root->value << endl;
    cout << "-----\n";
    binarySearchTree.print_pre_order(binarySearchTree.root);
}

void menu() {
    cout << "最优匹配法解决装箱问题" << endl;
    cout << "1. 手动输入数据" << endl;
    cout << "2. 文件输入数据(in.txt)" << endl;
    cout << "0. 退出" << endl;
    cout << "请输入对应操作: ";
}

void manual_input() {
    BinarySearchTree binarySearchTree;
    // 建树
    int n;
    cout << "请输入箱子个数: ";
    cin >> n;
    cout << "请输入对应" << n << "个箱子的容量: ";
    while (n--) {
        int m;
        cin >> m;
        binarySearchTree.insert(m);
    }
    // 查询
    cout << "请输入物品个数: ";
    cin >> n;
    cout << "请输入对应" << n << "个物品的重量: ";
    while (n--) {
        int m;
        cin >> m;
        binarySearchTree.put(m);
    }
}

void file_input() {
    ifstream in("in.txt");
    BinarySearchTree binarySearchTree;
    int n;
    in >> n;
    while (n--) {
        int m;
        in >> m;
        binarySearchTree.insert(m);
    }
    in >> n;
    while (n--) {
        int m;
        in >> m;
        binarySearchTree.file_put(m);
    }
    cout << "结果已输出至out.txt！" << endl;
    in.close();
}

int main() {
    //    test();
    while (true) {
        menu();
        int op;
        cin >> op;
        switch (op) {
        case 1:
            manual_input();
            break;
        case 2:
            file_input();
            break;
        case 0:
            cout << "谢谢使用！" << endl;
            return 0;
        default:
            cout << "非法操作！" << endl;
            break;
        }
    }
    return 0;
}
