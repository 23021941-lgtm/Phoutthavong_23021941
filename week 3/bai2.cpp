#include <iostream>
#include <list>
using namespace std;

// CÁCH 1: CÀI ĐẶT QUEUE BẰNG LINKEDLIST
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class QueueLinkedList {
private:
    Node* head = nullptr; // Đầu hàng đợi (dùng để pop)
    Node* tail = nullptr; // Cuối hàng đợi (dùng để push)

public:
    // Thêm vào cuối Queue - O(1)
    void push(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Xóa phần tử ở đầu Queue - O(1)
    void pop() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr; // Queue rỗng sau khi xóa
        delete temp;
    }

    // Xem giá trị ở đầu Queue - O(1)
    int front() {
        if (head == nullptr) return -1;
        return head->data;
    }

    // Kiểm tra rỗng - O(1)
    bool empty() {
        return head == nullptr;
    }
};

// CÁCH 2: CÀI ĐẶT QUEUE BẰNG LIST
class QueueList {
private:
    list<int> l;

public:
    // Thêm vào cuối Queue - O(1)
    void push(int val) {
        l.push_back(val);
    }

    // Xóa phần tử ở đầu Queue - O(1)
    void pop() {
        if (!l.empty()) l.pop_front();
    }

    // Xem giá trị ở đầu Queue - O(1)
    int front() {
        if (l.empty()) return -1;
        return l.front();
    }

    // Kiểm tra rỗng - O(1)
    bool empty() {
        return l.empty();
    }
};

int main() {
    cout << "--- TEST QUEUE LINKEDLIST ---\n";
    QueueLinkedList q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << "Front: " << q1.front() << "\n"; // Output: 1
    q1.pop();
    cout << "Front sau pop: " << q1.front() << "\n"; // Output: 2

    cout << "\n--- TEST QUEUE STD::LIST ---\n";
    QueueList q2;
    q2.push(10);
    q2.push(20);
    cout << "Front: " << q2.front() << "\n"; // Output: 10

    return 0;
}