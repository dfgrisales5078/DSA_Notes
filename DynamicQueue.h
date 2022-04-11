#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include "DynamicList.h"

// included from DynamicList.H
//struct DynamicNode{ // node is the same as in the dynamic list code
//    int info;
//    DynamicNode *next;
//};

class DynamicQueue {
public:

    // constructor
    DynamicQueue() {
        front = nullptr;
        rear = nullptr;
    }


    //----------------methods (inserts and deletes)------------------
    bool empty() {
        return (front == nullptr);
    }

    // insert happens at the end
    void insert(int x) {
        DynamicNode* p = new DynamicNode;
        p->info =x;
        p->next = nullptr;

        if (empty()) {
            front = p;
        }
        else {
            rear->next = p;
        }

        rear = p;
    }

    // remove only happens from the beginning - front pointer
    int remove() {
        if (empty()) {
            std::cout << "queue underflow";
            exit(1);
        }

        DynamicNode* p = front;
        int temp = p->info;
        front = p->next;
        delete p;
        if (front == nullptr)
            rear = nullptr;

        return temp;
    }


    // print queue
    void print() {
        if (empty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Data of queue: ";
            DynamicNode *p = front;
            while (p != nullptr) {
                cout << p->info;
                if (p->next != nullptr) {
                    cout << " -> ";
                }
                else {
                    cout << "\n";
                }
                p = p->next;
            }
        }
    }



    // search for x
    DynamicNode * search(int x) {
        DynamicNode *p = front; // node p == head (first element)
        for (p; p != nullptr; p = p->next) {
            if (p->info == x) {
                return p;
            }
        }
        return nullptr; // if x is not in the list
    }

private:
    DynamicNode* front;
    DynamicNode* rear;
};
#endif