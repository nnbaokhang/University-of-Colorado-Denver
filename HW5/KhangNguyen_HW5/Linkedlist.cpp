//
// Created by khang on 9/22/2018.
//
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList() {

    // Assign headPtr to nullptr
    //First Node will add
    headPtr= nullptr;

    size = 0;
}

bool LinkedList::insertAtFront(char value){
    // Connect headPtr directly to new Node (Only when headPtr point to nullptr)
    if(headPtr == nullptr){
    Node* newPtr = new Node;
    newPtr->data = value;
    newPtr->nextPtr = nullptr;
    headPtr = newPtr;
    size++;  // Linked list size increase by 1
    }
    else{
        // Create new Node and connect new node to exist node then assign newPtr to new Node
        Node* newPtr = new Node;
        newPtr->data = value;
        newPtr->nextPtr = headPtr;
        headPtr = newPtr;
        size++; // Linked list size increase by 1
    }
    return 1;
}


bool LinkedList::insertBeforePosition(char value, int index){
    //Check if position want to add node is out of range
     if(size == 0 || index > size)
         return 0;
     else if (index == 1){
         // Add at front
         insertAtFront(value);
     }
     else{
         //Create a new runptr to run to position want to add new node
         //Initialize a new node
         //RunPtr starts from headPtr
         //NewPtr will connect to where runPtr->next point to  and runPtr will connect to new Ptr
         //Size increase by one
         Node* runPtr = nullptr;
         Node* newPtr = new Node;
         newPtr->data = value;
         runPtr = headPtr;
         index = index - 2;
         while(index--){
             runPtr = runPtr->nextPtr;
         }
         newPtr->nextPtr = runPtr->nextPtr;
         runPtr->nextPtr = newPtr;
         size++;
     }
    return 1;
}

bool LinkedList::insertAtBack(char value){
    //Create a runPtr to run to the back of the linked list
    //Initialize a new node
    //RunPtr connect to newPtr
    //Size increase by 1
    Node* newPtr = new Node;
    Node* runPtr = nullptr;
    newPtr->data = value;
    newPtr->nextPtr = nullptr;
    runPtr = headPtr;
    while(runPtr->nextPtr != nullptr){
        runPtr = runPtr->nextPtr;
    }
    runPtr->nextPtr = newPtr;
    size++;
return 1;
}
bool LinkedList::deleteAtFront(){
    //Size out of range return false
    if(size == 0)
        return 0;
    else {
        //Create a deletePtr node and assign it to headPtr address
        //Move headPtr to headPtr-> next
        //Delete a node that deletePtr points to
        //Size decrease by one
        Node* deletePtr;
        deletePtr = headPtr;
        headPtr = deletePtr->nextPtr;
        delete deletePtr;
        size--;
    }
    return 1;
}
bool LinkedList::deleteAtBack(){
    //Size out of range return false
    if(size == 0)
        return 0;
    else if (size == 1){
        //Delete a node where headPtr point to
          delete headPtr;
          headPtr = nullptr;
          size--;
    }
    else{
        //Create a deletePtr and a runPtr
        //Run deletePtr to the last node
        //Run runPtr to before deletePtr
        //Delete a node that deletePtr point to
        //Connect runPtr->next to nullPtr
        //Size decrease by 1
        Node* deletePtr;
        Node* runPtr;
        deletePtr = headPtr;
        runPtr = headPtr;
        while(deletePtr->nextPtr != nullptr) {
            deletePtr = deletePtr->nextPtr;
        }
        while(runPtr->nextPtr != deletePtr)
            runPtr = runPtr->nextPtr;
       delete deletePtr;
       runPtr->nextPtr = nullptr;
     size--;
    }
    return 1;
}

bool LinkedList::deletePosition(int index) {
    //Return false when out of range
    if(size == 0 || index > size || index == 0)
        return 0;
    else if(index == 1){
        //delete at front
        deleteAtFront();
            }
    else if(index == size) {
        //delete at back
        deleteAtBack();
    }
    else{
        //Create deletePtr and runPtr
        //Run deletePtr to node where want to delete
        //Run runPtr to where before deletePtr
        //Connect runPtr->next to deletePtr -> next
        //Delete node where deletePtr point to
        //Size decrease by 1
        Node* deletePtr = headPtr;
        Node* runPtr = headPtr;
        index--;
        while(index--){
            deletePtr = deletePtr->nextPtr;
        }
        while(runPtr->nextPtr != deletePtr)
        runPtr = runPtr->nextPtr;
        runPtr->nextPtr = deletePtr->nextPtr;
        delete  deletePtr;
        size--;
    }
    return 1;
}

LinkedList::~LinkedList() {
    //Destructor clean the whole list
  clear();
}
void LinkedList::clear() {
         //Delete each node at the time
         //Start delete each node from right to left
         //End when headPtr point to nullptr
         //Size will set = 0
        while (headPtr != nullptr) {
            if(size == 1){
                deleteAtFront();
                break;
            }
            else {
                Node *deletePtr = headPtr;
                Node *runPtr = headPtr;
                while (deletePtr->nextPtr != nullptr)
                    deletePtr = deletePtr->nextPtr;
                while (runPtr->nextPtr != deletePtr)
                    runPtr = runPtr->nextPtr;
                delete deletePtr;
                runPtr->nextPtr = nullptr;
            size--;
            }
        }


}
std::ostream& operator << (std::ostream &out, LinkedList &list){
    //Create newPtr point to where headPtr point to
    //Loop through the linked list and print out each node data
    Node* newPtr = list.headPtr;
    out << "##########" << endl;
    while(newPtr != nullptr) {
        cout << newPtr->data;
        newPtr = newPtr->nextPtr;
    }
    out << endl << "##########" << endl;
    return out;
}