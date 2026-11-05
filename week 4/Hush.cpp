// 1. Hàm băm (Hash Function)
int hashFunction(int key) {
    return key % SIZE;
}

// 2. Hàm thêm / cập nhật
void insert(int key, string value) {
    int i = hashFunction(key);
    for (auto& pair : table[i]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    table[i].push_back({key, value});
}

// 3. Hàm tìm kiếm
string search(int key) {
    int i = hashFunction(key);
    for (const auto& pair : table[i]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return "Khong tim thay!";
}

// 4. Hàm xóa
void remove(int key) {
    int i = hashFunction(key);
    for (auto it = table[i].begin(); it != table[i].end(); ++it) {
        if (it->first == key) {
            table[i].erase(it);
            return;
        }
    }
}