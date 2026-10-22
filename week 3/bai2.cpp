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
    Node* head = nullptr; // Đầu hàng đợi (nơi lấy ra)
    Node* tail = nullptr; // Cuối hàng đợi (nơi thêm vào)

public:
    // Thêm phần tử vào cuối hàng đợi - O(1)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode; // Nếu Queue rỗng, cả head và tail cùng trỏ vào newNode
        } else {
            tail->next = newNode;  // Nối phần tử cuối cũ sang newNode
            tail = newNode;        // Cập nhật tail mới
        }
    }

    // Xóa phần tử ở đầu hàng đợi - O(1)
    void dequeue() {
        if (head == nullptr) return; // Queue rỗng thì bỏ qua
        Node* temp = head;
        head = head->next;          // Chuyển head sang phần tử kế tiếp
        if (head == nullptr) {
            tail = nullptr;         // Nếu danh sách rỗng, reset tail về nullptr
        }
        delete temp;                // Giải phóng vùng nhớ
    }

    // Xem giá trị phần tử ở đầu hàng đợi - O(1)
    int front() {
        if (head == nullptr) return -1;
        return head->data;
    }

    // Kiểm tra hàng đợi rỗng - O(1)
    bool empty() {
        return head == nullptr;
    }
};

// CÁCH 2: CÀI ĐẶT QUEUE BẰNG STD::LIST (STL)
class QueueList {
private:
    list<int> l;

public:
    // Thêm phần tử vào cuối hàng đợi - O(1)
    void enqueue(int val) {
        l.push_back(val);
    }

    // Xóa phần tử ở đầu hàng đợi - O(1)
    void dequeue() {
        if (!l.empty()) {
            l.pop_front();
        }
    }

    // Xem phần tử ở đầu hàng đợi - O(1)
    int front() {
        if (l.empty()) return -1;
        return l.front();
    }

    // Kiểm tra hàng đợi rỗng - O(1)
    bool empty() {
        return l.empty();
    }
};

// HÀM MAIN CHẠY THỬ
int main() {
    cout << "=== TEST QUEUE LINKEDLIST ===\n";
    QueueLinkedList q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << q1.front() << "\n"; // In ra: 10
    
    q1.dequeue();
    cout << q1.front() << "\n"; // In ra: 20

    cout << "\n=== TEST QUEUE STD::LIST ===\n";
    QueueList q2;
    q2.enqueue(100);
    q2.enqueue(200);
    cout << q2.front() << "\n"; // In ra: 100
    
    q2.dequeue();
    cout << q2.front() << "\n"; // In ra: 200

    return 0;
}