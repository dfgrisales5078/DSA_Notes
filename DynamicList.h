
#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <iostream>
using namespace std;

struct DynamicNode{
    int info;
    DynamicNode * next;
};

class DynamicList {
public:
// constructors
    DynamicList() {
        head = nullptr;
    } // default constructor

// methods (inserts, deletes, print, search) ----------------------------------------

    // inserts x at the beginning of the list
    void insertFirst(int x) {
        DynamicNode* q = new DynamicNode();
        q->info = x;        // update data
        q->next = head;     // update next
        head = q;           // make q the new head
    }

    // insert x after node p
    void insertAfter(DynamicNode *p, int x) {
        if (p == nullptr) {
            cout << "void insertion" << endl;
            exit(1);
        }
        DynamicNode *q = new DynamicNode();
        q->info = x;
        q->next = p->next;      // must be in this order to avoid losing list
        p->next = q;
    }

    // insert x to end of list
    void insertLast(int x) {
        DynamicNode *p = new DynamicNode();  // p new node to insert last
        p->info = x;
        p->next = nullptr;

        DynamicNode *q = nullptr; // q is a temp node to traverse list, it arrives at last node

        if (isEmpty()){
            head = p; // if empty, head is now pointing to p (new node)
        }
        else { // search for last node using q and an empty-body loop
            for (q = head; q->next != nullptr; q = q->next);
            q->next = p; // q =  original last node, which now point to p (new last node)
        }
    }

    // search for x
    DynamicNode * search(int x) {
        DynamicNode *p = head; // node p == head (first element)
        for (p; p != nullptr; p = p->next) {
            if (p->info == x) {
                return p;
            }
        }
        return nullptr; // if x is not in the list
    }

    // delete first node in list
    int deleteFirst() {
        if(isEmpty()) {
            cout << "void deletion" << endl;
            exit(1);
        }

        int temp = head->info;  // info of the head
        if (head->next != nullptr) { // if more than one node in list
            DynamicNode * newHead = head->next; // move to next head
            delete head;
            head = newHead;
        }
        else { // one node in list -> make list empty
            delete head;
            head = nullptr;
        }
        return temp;
    }

    // deletes node after p
    int deleteAfter(DynamicNode *p) {
        if(p == nullptr || p->next == nullptr)  {
            cout << "void deletion" << endl;
            exit(1);
        }
        DynamicNode* q = p->next; // q is a temp to the next of p
        int temp = q->info;       // info to be returned
        p->next = q->next;        // update the next
        delete q;                 // delete actual node in memory
        return temp;    // return info of deleted node

    }


    // removes nodes whose info field contains x
    // removes all nodes whose info fields contain x
    void removeX(int x) {
        DynamicNode* p = head; // p is the first node
        DynamicNode* q = nullptr; // q will be the one behind p, null for now
        while (p != nullptr) { // traverse the list
            if (p->info == x) { // you found it
                p = p->next;
                if (q == nullptr) {
                    deleteFirst(); // remove first node of the list
                }
                else {
                    deleteAfter(q); // q is before p, p has info=x
                }
            }
            else {
                // advance to next node of list
                q = p;
                p = p->next;
            }
        } // end while
    } // end removeX


    // check if list is empty
    bool isEmpty() {
        if (head == nullptr){
            //cout << "List is empty" << endl;
            return true;
        }
        else {
            //cout << "List is NOT empty" << endl;
            return false;
        }
    }


    // print list
    void print() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
        }
        else {
            cout << "Data of linked list: ";
            DynamicNode *p = head;
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

    // print list using for loop
    void printFor() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
        }
        else {
            DynamicNode * p = head;
            for (p; p!= nullptr; p = p->next) {
                cout << p->info << " ";
            }
        }
    }


    // count number of nodes
    int countNodes() {
        int count = 0;
        DynamicNode * p = head;
        for (p; p != nullptr; p = p->next) {
            count +=1;
        }
        return count;
    }


    // TODO
    // swap elements of the linked list
    void swap (int m, int n) {
        DynamicNode * p = getNth(m);
        DynamicNode * q = getNth(n);
        DynamicNode * temp = p;





        // temp variable to store q's info
//        int temp = q->info;
//        q->info = p->info;
//        p->info = temp;   //p's info == temp

    }

// ----------------------- Recursive methods -------------------------

    // recursive print function
    void recPrint(DynamicNode * p) {
        if (p != nullptr) {
            cout << p->info << " ";
            recPrint(p->next);
        }
    }

    // reverse print recursive
    void reverseRecPrint(DynamicNode * p) {
        if (p != nullptr) {
            reverseRecPrint(p = p -> next);
            cout << p->info << " ";
        }
    }

    // counts nodes in list recursively
    int recLength(DynamicNode * p) {
        if (p == nullptr) {
            return 0;
        }
        else {
            return 1 + recLength(p->next);
        }
    }

//--------------------- End of recursive methods -----------------------


    // TODO
    ~DynamicList() {

    }


// -------------------------------- Lab Methods -----------------------------

    // #1
    DynamicNode* getNth (int pos);

    // #2
    DynamicNode* findOrInsert(int x);

    // lab mystery question
    int mystery();

// -------------------------------- Exam Methods -----------------------------

    // recursive sum of elements larger than one
    int sumLargerThanOne(DynamicNode * node) {
        if (node == nullptr) { // base case
            return 0;
        }
        if (node->info > 1) {
            return node->info + sumLargerThanOne(node->next);
        }
        else {
            return sumLargerThanOne(node->next);
        }
    }

    // DeleteLast
    void deleteLast(DynamicNode * node) {
        if (head == nullptr){
            cout << "void deletion";
            exit(1);
        }
        // arrive at previous to last node using empty body loop
        for (node; node->next->next != nullptr; node = node->next);
        cout << endl;
        delete node->next;
        node->next = nullptr;


    }


private:
    DynamicNode* head;

};


#endif