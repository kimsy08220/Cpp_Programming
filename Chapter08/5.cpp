#include <iostream>
using namespace std;

class BaseArray {
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
    int rear, front;
public:
    MyQueue(int capacity) : BaseArray(capacity) {
        rear = 0;
        front = 0;
    }
    void enqueue(int n) {
        put(front, n);
        front++;
    }
    int capacity() { return getCapacity(); }
    int length() { return front - rear; }
    int dequeue() {
        return get(rear++);
    }
};

int main(void) {
    MyQueue mQ(100);
    int n;
    cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n);
    }
    cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
    cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
    while (mQ.length() != 0) {
        cout << mQ.dequeue() << ' '; 
    }
    cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}