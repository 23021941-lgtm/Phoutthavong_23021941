#include <iostream>
#include <list>
using namespace std;

// CÁCH 1: CÀI ĐẶT STACK BẰNG LINKEDLIST 
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* head = nullptr; // head đóng vai trò là đỉnh (top) của Stack

public:
    // Thêm vào đỉnh Stack - O(1)
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Xóa phần tử ở đỉnh Stack - O(1)
    void pop() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Xem giá trị ở đỉnh Stack - O(1)
    int top() {
        if (head == nullptr) return -1;
        return head->data;
    }

    // Kiểm tra rỗng - O(1)
    bool empty() {
        return head == nullptr;
    }
};

// CÁCH 2: CÀI ĐẶT STACK BẰNG LIST 
class StackList {
private:
    list<int> l; // Thư viện std::list 

public:
    // Thêm vào đỉnh Stack - O(1)
    void push(int val) {
        l.push_front(val);
    }

    // Xóa phần tử ở đỉnh Stack - O(1)
    void pop() {
        if (!l.empty()) l.pop_front();
    }

    // Xem giá trị ở đỉnh Stack - O(1)
    int top() {
        if (l.empty()) return -1;
        return l.front();
    }

    // Kiểm tra rỗng - O(1)
    bool empty() {
        return l.empty();
    }
};

int main() {
    cout << "--- TEST STACK LINKEDLIST ---\n";
    StackLinkedList st1;
    st1.push(10);
    st1.push(20);
    cout << "Top: " << st1.top() << "\n"; // Output: 20
    st1.pop();
    cout << "Top sau pop: " << st1.top() << "\n"; // Output: 10

    cout << "\n--- TEST STACK STD::LIST ---\n";
    StackList st2;
    st2.push(100);
    st2.push(200);
    cout << "Top: " << st2.top() << "\n"; // Output: 200

    return 0;
}