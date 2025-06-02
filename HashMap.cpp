#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 10007;

    struct Node {
        int key, value;
        Node* next;
        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    vector<Node*> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE, nullptr);
    }

    void put(int key, int value) {
        int idx = hash(key);
        Node* head = buckets[idx];
        Node* curr = head;
        while (curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = head;
        buckets[idx] = newNode;
    }

    int get(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];
        while (curr) {
            if (curr->key == key) return curr->value;
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];
        Node* prev = nullptr;
        while (curr) {
            if (curr->key == key) {
                if (prev) prev->next = curr->next;
                else buckets[idx] = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

int main() {
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    cout << obj.get(1) << endl;   // 10
    cout << obj.get(3) << endl;   // -1
    obj.put(2, 30);
    cout << obj.get(2) << endl;   // 30
    obj.remove(2);
    cout << obj.get(2) << endl;   // -1
    return 0;
}