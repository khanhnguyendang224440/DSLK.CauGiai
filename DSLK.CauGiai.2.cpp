#include <iostream>
#include <string>

// Cau truc luu thong tin ve file
struct FileNode {
    std::string fileName;     // Ten file
    long fileSize;            // Kich thuoc file (byte)
    std::string creationDate; // Ngay tao file (dinh dang "YYYY-MM-DD")
    FileNode* next;
};

// Danh sach lien ket luu thong tin file
FileNode* head = NULL;

// Ham them file vao danh sach
void themFile(std::string ten, long kichThuoc, std::string ngay) {
    FileNode* newNode = new FileNode{ten, kichThuoc, ngay, NULL};

    if (!head || head->fileSize > kichThuoc) {
        newNode->next = head;
        head = newNode;
    } else {
        FileNode* temp = head;
        while (temp->next && temp->next->fileSize <= kichThuoc) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Ham in danh sach file
void inDanhSach() {
    FileNode* temp = head;
    std::cout << "Danh sach file:\n";
    while (temp) {
        std::cout << "- " << temp->fileName << ", Kich thuoc: " << temp->fileSize
                  << " bytes, Ngay tao: " << temp->creationDate << std::endl;
        temp = temp->next;
    }
}

// Ham xoa file co kich thuoc be nhat va thoi gian tao lau nhat
void xoaFileBeNhatVaLauNhat() {
    if (!head) {
        std::cout << "Danh sach rong, khong co file de xoa.\n";
        return;
    }

    FileNode* smallest = head;
    FileNode* prevSmallest = NULL;

    FileNode* current = head;
    FileNode* prev = NULL;

    while (current) {
        if (current->fileSize == smallest->fileSize &&
            current->creationDate < smallest->creationDate) {
            smallest = current;
            prevSmallest = prev;
        }
        prev = current;
        current = current->next;
    }

    // Xoa file nho nhat va lau nhat
    if (prevSmallest) {
        prevSmallest->next = smallest->next;
    } else {
        head = head->next;
    }
    std::cout << "Da xoa file: " << smallest->fileName
              << " (Kich thuoc: " << smallest->fileSize
              << " bytes, Ngay tao: " << smallest->creationDate << ")\n";
    delete smallest;
}

// Chuong trinh chinh
int main() {
    int luaChon;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Them file vao danh sach\n";
        std::cout << "2. In danh sach file\n";
        std::cout << "3. Xoa file co kich thuoc be nhat va thoi gian tao lau nhat\n";
        std::cout << "0. Thoat\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> luaChon;

        switch (luaChon) {
            case 1: {
                std::string ten, ngay;
                long kichThuoc;
                std::cout << "Nhap ten file: ";
                std::cin >> ten;
                std::cout << "Nhap kich thuoc file (bytes): ";
                std::cin >> kichThuoc;
                std::cout << "Nhap ngay tao file (YYYY-MM-DD): ";
                std::cin >> ngay;
                themFile(ten, kichThuoc, ngay);
                break;
            }
            case 2:
                inDanhSach();
                break;
            case 3:
                xoaFileBeNhatVaLauNhat();
                break;
            case 0:
                std::cout << "Thoat chuong trinh.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le.\n";
        }
    } while (luaChon != 0);

    return 0;
}

