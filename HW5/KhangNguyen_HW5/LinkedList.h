#include<iostream>


struct Node
{
	char data = 0;
	Node* nextPtr = nullptr;
};

class LinkedList
{
private:
	Node *headPtr;
    int size = 0;
public:

    LinkedList(); //Default constructor
    virtual ~LinkedList(); // Destructor

    bool insertAtFront(char value);  // Each new node will connect directly to headPtr
	bool insertBeforePosition(char value, int index);
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool insertAtBack(char value); //Each new node will be added at the back of linked list
	bool deleteAtFront(); // Delete the first node
	bool deletePosition(int index); // Delete a node at position index
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool deleteAtBack();//Delete a node at the back
	//false if empty
	void clear(); //frees memory for entire list
	friend std::ostream& operator << (std::ostream &out, LinkedList &list);
	//Operator overloading output

};
