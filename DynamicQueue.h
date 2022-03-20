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

private:
    DynamicNode* front;
    DynamicNode* rear;
};
#endif