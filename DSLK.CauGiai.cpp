#include <iostream>

// Cau truc cua mot node trong danh sach lien ket
struct Node {
    int data;
    Node* next;
};

// Khoi tao danh sach rong
Node* head = NULL;

// Ham them node vao cuoi danh sach
void themNodeCuoi(int giaTri) {
    Node* newNode = new Node;
    newNode->data = giaTri;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Ham in danh sach
void inDanhSach() {
    Node* temp = head;
    std::cout << "Danh sach hien tai: ";
    while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Ham xoa node o dau danh sach
void xoaNodeDau() {
    if (head == NULL) {
        std::cout << "Danh sach rong, khong co gi de xoa.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    std::cout << "Da xoa node o dau danh sach.\n";
}

// Ham xoa node o cuoi danh sach
void xoaNodeCuoi() {
    if (head == NULL) {
        std::cout << "Danh sach rong, khong co gi de xoa.\n";
        return;
    }

    if (head->next == NULL) { // Danh sach chi co mot phan tu
        delete head;
        head = NULL;
        std::cout << "Da xoa node duy nhat trong danh sach.\n";
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    std::cout << "Da xoa node o cuoi danh sach.\n";
}

// Ham xoa node sau mot node cu the
void xoaNodeSau(int giaTri) {
    if (head == NULL) {
        std::cout << "Danh sach rong, khong co gi de xoa.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != giaTri) {
        temp = temp->next;
    }

    if (temp == NULL) {
        std::cout << "Khong tim thay node co gia tri " << giaTri << ".\n";
        return;
    }

    if (temp->next == NULL) {
        std::cout << "Khong co node nao sau node co gia tri " << giaTri << ".\n";
        return;
    }

    Node* nodeCanXoa = temp->next;
    temp->next = nodeCanXoa->next;
    delete nodeCanXoa;
    std::cout << "Da xoa node sau node co gia tri " << giaTri << ".\n";
}

// Ham chinh
int main() {
    int luaChon;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Them mot node vao cuoi danh sach\n";
        std::cout << "2. Xoa node o dau danh sach\n";
        std::cout << "3. Xoa node o cuoi danh sach\n";
        std::cout << "4. Xoa node sau mot gia tri nhat dinh\n";
        std::cout << "5. In danh sach\n";
        std::cout << "0. Thoat\n";
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> luaChon;

        switch (luaChon) {
            case 1: {
                int giaTri;
                std::cout << "Nhap gia tri cua node: ";
                std::cin >> giaTri;
                themNodeCuoi(giaTri);
                break;
            }
            case 2:
                xoaNodeDau();
                break;
            case 3:
                xoaNodeCuoi();
                break;
            case 4: {
                int giaTri;
                std::cout << "Nhap gia tri cua node truoc node can xoa: ";
                std::cin >> giaTri;
                xoaNodeSau(giaTri);
                break;
            }
            case 5:
                inDanhSach();
                break;
            case 0:
                std::cout << "Thoat chuong trinh.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le, vui long thu lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}

