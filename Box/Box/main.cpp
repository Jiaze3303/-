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
    cout << "����ƥ�䷨���װ������" << endl;
    cout << "1. �ֶ���������" << endl;
    cout << "2. �ļ���������(in.txt)" << endl;
    cout << "0. �˳�" << endl;
    cout << "�������Ӧ����: ";
}

void manual_input() {
    BinarySearchTree binarySearchTree;
    // ����
    int n;
    cout << "���������Ӹ���: ";
    cin >> n;
    cout << "�������Ӧ" << n << "�����ӵ�����: ";
    while (n--) {
        int m;
        cin >> m;
        binarySearchTree.insert(m);
    }
    // ��ѯ
    cout << "��������Ʒ����: ";
    cin >> n;
    cout << "�������Ӧ" << n << "����Ʒ������: ";
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
    cout << "����������out.txt��" << endl;
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
            cout << "ллʹ�ã�" << endl;
            return 0;
        default:
            cout << "�Ƿ�������" << endl;
            break;
        }
    }
    return 0;
}
