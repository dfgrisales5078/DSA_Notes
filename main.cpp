// Diego Grisales
// 01/10/22
// COP 3530 - Data Structures & Algorithms 
// Notes/Code


#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>



using namespace std;

/// swap/reverse elements of array

/*
int main() {

	int a[] = {2, 5, 7, 10 , 11};

	int *ptr = a;
	ptr++;                      // ptr now points to index 1 of array
	cout << *ptr << "\n";

	int n = 5; // number of elements in a
	for(int i=0; i< n/2 ; i++){
		int temp = a[ i ];
		a[ i ] = a[n - i - 1];
		a[n - i - 1] = temp;
	}



	for (auto x: a) {
		cout << x << " ";
	}
	return 0;
}
*/


// ------------------------------------------------------------------------------


/// rotate 2D array 90 degrees - Practice Problem 

/*
void printMatrix(int a[4][4]) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << a[i][j] << " ";

		cout << endl;
	}
	cout << endl;
}

int main() {

	const int n = 4;
	int a[n][n] = { {759, 326, 309, 458},
					{723, 497, 161, 388},
					{623, 702, 148, 485},
					{224, 637, 151, 162} };

	printMatrix(a);
	cout << endl;

	for (int i = 0; i < n / 2; i++) {

		for (int j = i; j < n - i - 1; j++) {
			int temp = a[i][j];                           // temp = a[0][0]
			a[i][j] = a[n - 1 - j][i];                    // a[0][0] = a[3][0]
			a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];    // a[3][0] = a[3][3]
			a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];    // a[3][3] = a[0][3]
			a[j][n - 1 - i] = temp;                       // a[0][3] = temp
		}
	}

	printMatrix(a);

	return 0;
}
*/


// ------------------------------------------------------------------------------


/// Search and Delete using array - Practice exercise


/*
void searchAndEliminate(string thisName, string nameArray[], int size) {

	for (int i = 0; i < size - 1; i++) {
		// iterate through array looking for thisName, if found make it
		// equal to "empty"
		if (thisName == nameArray[i]) {
			nameArray[i] = "empty";
		}

        // if empty found, save it in a temp variable
		if (nameArray[i] == "empty") {
			string temp = nameArray[i];

			// swap index containing "empty" with the index following it

			// nameArray[j] now has the contents of the next index:
			nameArray[i] = nameArray[i + 1];

			// next index now contains "empty":
			nameArray[i + 1] = temp;
		}
	}

}



int main() {


	string nameArray[5] = { "Tom", "Amy", "Sarah", "Mary", "Nick" };
	string thisName = "Sarah";
	int size = sizeof(nameArray) / sizeof(string);


	searchAndEliminate(thisName, nameArray, size);

	for (auto x : nameArray) {
		cout << x << " ";
	}
	cout << "\n" << endl;


	string thisName1 = "Nick";
	searchAndEliminate(thisName1, nameArray, size);


	for (auto x : nameArray) {
		cout << x << " ";
	}
	cout << "\n" << endl;


	return 0;
}

*/



// ------------------------------------------------------------------------------



/// Stack - Array Implementation

#include "stack.h"

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
// ------------------------------------------------------------------------------
// default constructor
// ------------------------------------------------------------------------------
Stack::Stack() {
    top = -1;        //empty stack
}

// ------------------------------------------------------------------------------
// methods (insert and delete) --- O(1)
// ------------------------------------------------------------------------------

char Stack::pop() {
    if (empty()) {
        std::cout << "Stack Underflow POP" << std::endl;
        exit(1);    // Exit Failure
    }
    return items[top--];    // dec top after
}

void Stack::push(char x) {
    if (top == STACKSIZE - 1) {
        std::cout << "Stack Overflow PUSH" << std::endl;
        exit(1);    // Exit Failure
    }
    items[++top] = x;   // inc top first
}

char Stack::peek() {
    if (empty()) {
        std::cout << "Stack Underflow PEEK" << std::endl;
        exit(1);
    }
    return items[top];
}

bool Stack::empty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

// end of stack ----------------------------------------------------------------



/// Matching parenthesis - practice code

/*
// check for pairs
bool arePairs(char j, char i) {
    if (j == '(' && i == ')') {
        return true;
    }
    else if (j == '[' && i == ']') {
        return true;
    }
    else if (j == '{' && i == '}') {
        return true;
    }
    else {
        return false;
    }
}



// matching parenthesis function
bool matchingParenthesis(string exp) {

    bool valid = true;
    Stack stack;

    for (char i : exp) {
        if (i == '(' || i == '[' || i == '{') {
            stack.push(i);
        }

        if (i == ')' || i == ']' || i == '}') {
            if (stack.empty()) {
                valid = false;
                break;
            } else {
                char j = stack.pop(); //

                if (!arePairs(j, i)) {
                    valid = false;
                    break;
                }
            }
        }
    } // end for loop

    // Check for opening parenthesis in the stack
    // make sure stack is empty
    if (!stack.empty()) {
        valid = false;
    }

    return valid;

}

int main() {

    // unbalanced:
    string expression = {"7 - { [X *(X + Y)/(J - 3) ] + Y } / (4 - 2))"};
    // balanced:
    string expression1 = {"(X + Y)/(J - 3)"};

    bool balanced = matchingParenthesis(expression);

    if (balanced) {
        cout << "the string is valid";
    } else {
        cout << "the string is not valid";
    }

    return 0;
}
*/

// ------------------------------------------------------------------------------


/// Stack implementation using an array:

class MyStack {

private:
    char items[100]; // size of stack
    int top;        // indicates top element

public:

    // constructor
    MyStack() {
        top = -1;
    }

    // member methods
    bool empty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }

    void push(char x) {
        if (top == 100 - 1) {
            cout << "stack overflow";
            exit(1);
        }
        else
            items[++top] = x;
    }
    char pop() {
        if (empty()) {
            cout << "stack underflow";
            exit(1);
        }
        else return items[top--];
    }
    char peek() {
        if (empty()) {
            cout << "Stack underflow PEEK";
        }
        return items[top];
    }




};


// ------------------------------------------------------------------------------




// Practice with stacks - Last Name
/*
int main() {
    Stack s;
    string lastName = "GRISALES";

    // for loop used to push each letter of lastName
    // into the stack and print each letter being added.
    cout << "Last name pushed into the stack letter by letter: " << endl;
    for (int i = 0; i < lastName.length(); i++) {
        s.push(lastName[i]);
        cout << lastName[i] << " ";
    }
    cout << "\n" << endl;

    // Print stack contents in reverse: print out the element at the top of
    // stack and then pop the element off the stack, repeat process until
    // stack is empty.
    cout << "Last name printed in reverse and popped off the stack:" << endl;
    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    return 0;
}
*/


// ------------------------------------------------------------------------------


///-------------------------------Recursion--------------------------------------



// factorial
long fac(int n) {
    // base case
    if (n == 0) {
        return 1;
    }
    return n * fac(n - 1);
}

// fibonacci
int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

// sum integers from first to last
int sum(int first, int last) {

    if (first == last) {
        return first;
    }
    return first + sum(first + 1, last);

}

// sum array
int sum(int arr[], int n) {
    if (n==0){
        return 0;
    }
    return sum(arr, n - 1) + arr[n-1];
}


// function that returns max of array
int maxNum(int numbers[], int index, int length) {
    if (index == length - 1)
        return numbers[index];
    else {
        int temp = maxNum(numbers, index + 1, length);
        if (temp > numbers[index])
            return temp;
        else
            return numbers[index];
    }
}


// ------------------------------------------------------------------------------

/// Binary search

int binSearch(int a[], int x, int low, int high) {
    int mid;
    if (low > high) { // base case
        return -1;
    }
    mid = (low + high) / 2;
    //cout << "a[mid] = " << a[mid] << endl;
    if (x == a[mid]) { // base case
        return mid;
    }
    if (x < a[mid]) {
        return binSearch(a, x, low, mid - 1);
    } else {
        return binSearch(a, x, mid + 1, high);
    }
}

/*
int a[] ={2, 3, 7, 8, 13, 21};
cout << "position of 21 is: " << binSearch(a, 21, 0, 5);
 */


// ------------------------------------------------------------------------------

// Linked lists

#include "DynamicList.h"

//# 1 Using while loop:
//    int length = 0;
//    DynamicNode * temp = head;
//
//    while (temp != nullptr) {
//        if (length == x) {
//            return temp;
//        }
//        length++;
//        temp = temp->next;
//    }
//    return nullptr;


// -------------------------Lab methods:---------------------------
// #1
/**
 * Returns the N-th node in the list
 * remember there is no index in the list, so it needs to count to the N-th
 * If the list does not contain as many nodes, it returns nullptr
 */

DynamicNode* DynamicList::getNth (int pos) {
    int index = 0;
    DynamicNode *p = head; // p is a temp node pointing to head
    // for loop used to traverse loop until it finds last node (nullptr)
    for (p ; p != nullptr; p = p->next) {
        // if index is equal to pos (index being searched for), return that node
        if (index == pos) {
            return p;
        }
        index +=1;
    }
    return nullptr; // return nullptr if index is not found or empty list
}

// #2
/**
 * Searches the list for a node that has x, and
 * returns the list node containing x, if x is found.
 * If x is not found in the list, it inserts a node with x into the list
 * and returns the node containing x.
 */
DynamicNode *DynamicList::findOrInsert(int x) {
    // if list is empty create new node containing x at
    // the beginning of list and return it
    if (head == nullptr) {
        DynamicNode * q = new DynamicNode;
        q->info = x;
        q->next = head;
        head = q;
        return q;
    }
    DynamicNode *p = head; // p is a temp node pointing to head
    // for loop used to traverse loop searching for x using p
    for (p ; p->next != nullptr; p = p->next) {
        // if p's info is equal to x, return p
        if (p->info == x) {
            return p;
        }
    }
    // if p's info equals x, return p
    if (p->info == x) {
        return p;
    }
        // else create new node at end of the list and return it
    else {
        DynamicNode * q = new DynamicNode;
        p->next = q;
        q->info = x;
        q->next = nullptr;
        return q;
    }
}


// Lab extra mystery question
int DynamicList::mystery() {
    int return_val = -1; // some error code
    if (head == nullptr) {
        return return_val; // some error code
    }
    else {
        DynamicNode* current = nullptr;
        DynamicNode* temp1 = head;
        DynamicNode* temp2 = head;
        while (temp2->next != nullptr) {
            current = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp2->next == nullptr) {
                return return_val; // some error code
            }
            else {
                temp2 = temp2->next;
            }
        }
        if (current == nullptr) {
            return_val=head->info;
            head = nullptr;
            delete temp1;
        }
        else {
            return_val=temp1->info;
            current->next = temp1->next;
            delete temp1;
        }
        return return_val;
    }
}


//---------------------Linked Lists Main()--------------------------
/*
int main() {

    DynamicList myList = DynamicList();
    myList.insertFirst(3);
    myList.insertFirst(2);
    myList.insertFirst(1);
    myList.insertLast(4);
    myList.insertLast(5);
    myList.insertLast(6);
    myList.insertLast(7);
    myList.insertLast(8);
    myList.insertLast(9);

    myList.print();

    // swap elements test
    myList.swap(0,2);
    myList.print();

//    myList.removeX(7);
//    myList.print();


    // recursive node count from main
    DynamicNode * head = myList.getNth(0);
    cout << "Number of Nodes: " << myList.recLength(head) << endl;

    myList.print();

    cout << "Sum of elements larger than one: " <<myList.sumLargerThanOne(head);

    myList.deleteLast(head);
    myList.print();


    //cout << "number of nodes: " << myList.countNodes() << endl;

    //DynamicNode * nodeFour = myList.search(4);
    //myList.insertAfter(nodeFour, 5);


    //cout << myList.head->next->next->next->next->info << endl;
    //myList.deleteFirst();


    //DynamicNode * nodeOne = myList.search(1);
    //cout << node->info;

    //myList.deleteAfter(nodeOne);
    //myList.print();

    //myList.insertAfter(nodeOne, 0);

    //myList.print();


    // lab code test:
    // # 1
//    DynamicNode * N  = myList.getNth(1);
//    if (N != nullptr) {
//        cout << "Info of 4th element: " << N->info << endl;
//    }
//    else {
//        cout << "Index not found" << endl;
//    }


    // #2
//    DynamicNode * N = myList.findOrInsert(6);
//    cout << "Info of N: "<<N->info << endl;
//    myList.print();


    // Mystery lab question

//    cout << myList.mystery() << endl;
//    myList.print();

    return 0;
}

*/
//--------------------End Linked Lists Main()------------------------



//----------------------- Queues Main() -----------------------------


#include "DynamicQueue.h"

/*
int main() {

    DynamicQueue queue = DynamicQueue();
    queue.insert(5);
    std::cout << "Inserted 5 into queue" << std::endl;
    queue.insert(7);
    std::cout << "Inserted 7 into queue" << std::endl;


    queue.remove();
    std::cout << "Removed 5 from queue" << std::endl;
    queue.remove();
    std::cout << "Removed 7 from queue" << std::endl;

    //code should exit here due to underflow
    std::cout << "Attempting to remove from an empty queue..." << std::endl;
    queue.remove();


}
*/
//--------------------- End Queues Main() --------------------------




//--------------- Binary Search Trees Main() ----------------------

/*
#include "BinSearchTree.h"


int main() {
    // BST main code test
    BinSearchTree st = BinSearchTree(); // the tree object
    st.insert(8);  //the root
    // where will each of this go in the BST?
    st.insert(3);
    st.insert(11);
    st.insert(9);
    st.insert(10);
    st.insert(14);

    std::cout << "inorder traversal:  ";
    st.inTrav();

    std::cout << "\nSum of leaf node values: " << st.sumOfLeaves(st.getRoot());


    std::cout << "\nless than 10: ";
    st.printLessThanK(st.getRoot(), 10);


    cout << "\nNumber of nodes in tree: " << st.count(st.getRoot());

    cout << "\nSum of node values in tree: " << st.sumOfValues(st.getRoot());

    cout << "\nHeight of tree: " << st.height(st.getRoot()) << "\n";

    st.inTrav();

    std::cout << "\npreorder traversal: ";
    st.preTrav(st.getRoot());

    std::cout << "\npostorder traversal: ";
    st.postTrav(st.getRoot());

    TreeNode * N = st.findMin(st.getRoot());
    std::cout << "\nSmallest number: " << N->info;



}
*/

//--------------- End - Binary Search Trees Main() ----------------------


//--------------- Heap/Heapsort Main() ----------------------

/*
const int SIZE = 8; //the length of the array

void printArray(int x[]){

    for(int i=0;i<SIZE;i++){
        std::cout<< x[i] << " ";
    }
    std::cout<<"\n";
}

void heapSort(int x[]){
    int i, parent, child;

    if(SIZE == 0)	return;

    // preprocessing phase; create initial heap
    for(i = 1; i < SIZE; i++){
        int elt = x[i];
        // bubble_up
        child = i;
        parent = (child - 1)/2;
        while(child > 0 && x[parent] < elt){
            x[child] = x[parent];
            child = parent;
            parent = (child - 1)/2;
        }
        x[child] = elt;
    }

    std::cout << "Initial heap: " <<"\t";
    printArray(x);

    // selection phase; repeatedly remove x[0], insert it
    // in its proper position and adjust the heap
    for(i = SIZE-1; i > 0; i--){
        // bubble-down
        std::cout <<"i=" << i << "  x[i]=" << x[i] << "\t";
        printArray(x);

        //put x[0] in i-th position
        int iValue = x[i];
        x[i] = x[0];
        parent = 0;

        //select the large child
        if(i == 1) 						child = -1;
        else							child = 1;
        if(i > 2 && x[2] > x[1])		child = 2;

        while(child >= 0 && iValue < x[child]){
            //move child into parent position
            x[parent] = x[child];
            parent = child;
            child = 2*parent + 1; //first child index

            if(child > i-1)  //no child
                break;

            //if there is a second child and it is larger
            if(child + 1 <= i-1 && x[child] < x[child+1])
                child = child + 1;  //get second child
        }
        x[parent] = iValue;
    }
    std::cout <<"\t\t";
    printArray(x);

} // end heapSort


int main(){
    int b[] = {75, 3, 4, 83, 51, 45, 67, 72	};
    std::cout << "Numbers:\n";
    printArray(b);

    heapSort(b);
    std::cout << "\nSorted numbers using Heap sort: ";
    printArray(b);
}
*/


//--------------- End Heap/Heapsort Main() ----------------------


//--------------- Quicksort Main() ----------------------


int partition (int x[], int lb, int ub){
    int down, up, a, temp;

    a = x[lb];  // the pivot element
    up = ub;
    down = lb;
    //traverse the array and swap elements
    while (down < up){
        while (x[down] <= a && down < ub)
            down++;
        while (x[up] > a)
            up--;
        if (down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }

    x[lb] = x[up];
    x[up] = a;

    //return the index where the pivot is now at

    return up;
} // end partition

// main qsort method with array, lower and upper bound
void quicksort(int x[], int lb, int ub){
    // lower bound crossed upper bound
    if(lb >= ub)	return;

    // index j = the index of the "pivot"
    int j = partition(x, lb, ub);
    // ^^ this function will choose
    // which element to partition
    // around

    quicksort(x, lb, j-1); // quicksort on left of j
    quicksort(x, j+1, ub); // quicksort on the right of j
}


int main() {

    int arr[] = {44, 66, 10, 1, 199, 100, 2, 88};

    std::cout << "Before quicksort: ";
    for (int x : arr) {
        std::cout << x << " ";
    }

    quicksort(arr, 0, 7);
    std::cout << "\nAfter quicksort: ";
    for (int x : arr) {
        std::cout << x << " ";
    }


}

//--------------- End Quicksort Main() ----------------------