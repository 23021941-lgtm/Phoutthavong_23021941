// Ham vun dong tu duoi len (dung khi Them phan tu)
void heapifyUp(int arr[], int i) {
    int parent = (i - 1) / 2; // Vi tri nut cha

    // Neu nut hien tai lon hon nut cha thi doi cho va de quy len tren
    if (i > 0 && arr[i] > arr[parent]) {
        swap(arr[i], arr[parent]);
        heapifyUp(arr, parent);
    }
}

// 1. Ham Tim kiem (tra ve chi so index, khong thay tra ve -1)
int searchHeap(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// 2. Ham Them phan tu moi vao Max-Heap
void insertHeap(int arr[], int& n, int val) {
    arr[n] = val;          // Dua phan tu moi vao cuoi mang
    n++;                   // Tang kich thuoc heap
    heapifyUp(arr, n - 1); // Vun dong nguoc len de dam bao tinh chat Max-Heap
}

// 3a. Ham Xoa phan tu goc (phan tu lon nhat - thao tac chuan cua Heap)
void deleteRoot(int arr[], int& n) {
    if (n <= 0) return;

    arr[0] = arr[n - 1]; // Dua phan tu cuoi cung len thay the goc
    n--;                 // Giam kich thuoc heap
    heapify(arr, n, 0);  // Vun dong tu goc xuong duoi (dung ham heapify da co)
}

// 3b. Ham Xoa mot gia tri bat ky trong Max-Heap
void deleteValue(int arr[], int& n, int val) {
    int idx = searchHeap(arr, n, val);
    if (idx == -1) return; // Khong tim thay gia tri can xoa

    arr[idx] = arr[n - 1]; // Ghi de bang phan tu cuoi mang
    n--;                   // Giam kich thuoc heap

    if (idx == n) return;  // Neu xoa dung phan tu cuoi cung thi dung luon

    // Can bang lai heap tai vi tri idx (day len neu lon hon cha, nguoc lai day xuong)
    int parent = (idx - 1) / 2;
    if (idx > 0 && arr[idx] > arr[parent]) {
        heapifyUp(arr, idx);
    } else {
        heapify(arr, n, idx);
    }
}