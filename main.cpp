#include "LinkedQueue.hpp"
#include <iostream>
using namespace std;

int main() {
    LinkedQueue<int> queueA;
    const int MAX_SIZE = 10;

    // attempt to display the front and back
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    // insert just one element
    queueA.enqueue(-5);

    cout << "A length: " << queueA.getLength() << " ";
    cout << "A front: "  << queueA.front()     << " ";
    cout << "A back: "   << queueA.back()      << " ";

    // remove it
    queueA.dequeue();

    cout << "A length: " << queueA.getLength() << " ";
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    // 🔥 FIX: deterministic values instead of random
    for (int i = 0; i < MAX_SIZE; i++) {
        queueA.enqueue(i);
    }

    cout << "A length: " << queueA.getLength() << " ";
    cout << "A front: "  << queueA.front()     << " ";
    cout << "A back: "   << queueA.back()      << " ";

    LinkedQueue<int> queueB = queueA;

    cout << "A contains: ";
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << queueA.front() << ' ';
        queueA.dequeue();
    }
    cout << " ";

    if (queueA.isEmpty()) {
        cout << "A is now empty ";
    } else {
        cout << "A is not empty [ERROR] ";
    }

    cout << "B length: " << queueB.getLength() << " ";
    cout << "B front: "  << queueB.front()     << " ";
    cout << "B back: "   << queueB.back()      << " ";

    LinkedQueue<int> queueC;
    queueC = queueB;

    queueB.clear();

    if (queueB.isEmpty()) {
        cout << "B is now empty ";
    } else {
        cout << "B is not empty [ERROR] ";
    }

    cout << "C length: " << queueC.getLength() << " ";
    cout << "C front: "  << queueC.front()     << " ";
    cout << "C back: "   << queueC.back()      << " ";

    return 0;
}