#ifndef TAWDE_LIST_HPP_INCLUDED
#define TAWDE_LIST_HPP_INCLUDED

/*
Name: Arya Manish Tawde
Assignment 4.
Description(Node): A class that defines a single element in our linked list. It
                consists of a single data element and a pointer to the next node.
Description(SingLink List): This is a templated linked-list class that can store
a list of variable size that can store a class of users choice

*/

template <class T>              //Templated for variable use.
class Node
{
private:                        //Data is private and encapsulated
    T data;
    Node<T> *next;

public:                         //Multiple Constructors for ease of access;
    Node()
    {
        this->next = nullptr;
    }
    Node(T temp)
    {
        this->next = nullptr;
        this->data = temp;
    }
    Node(Node<T> *temp)
    {
        this->next = temp;
    }
    Node(Node<T> *temp, T temp2)
    {
        this->next = temp;
        this->data = temp2;
    }

    void setNext(Node<T> *temp)         // Methods for Accessing the data.
    {
        this->next = temp;
    }
    Node<T>* getNext()
    {
        return this->next;
    }
    void setData(T temp)
    {
        this->data = temp;
    }
    T getData()
    {
        return this->data;
    }
};

/*This is the Singly Linked List */
template <class T>                  // Templated again for using with different classes
class SingLinkList
{
private:                            //Once again data is private.
    Node<T> *head, *tail;
    int length;

public:                            //Constructors and Methods are defined outside the class.
    SingLinkList();
    ~SingLinkList();
    void addToFront(T data);
    void addToEnd(T data);
    bool addAtIndex(T data, int index);
    T removeFromFront();
    T removeFromEnd();
    void removetheFirst(T data);
    void removeAllOf(T data);
    bool elementExists(T data);
    Node<T>* Find(T data);
    int indexOf(T data);
    T retrieveFront();
    T retrieveEnd();
    T retrieve(int index);
    int getLength();
    void printList();
    void emptyList();
};

/*
Class: SingleLinkList()   Constructor
Description:This is the constructor called when list is made. It initialises head and tail
            pointers to zero.
Parameters: None.
*/

template <class T>
SingLinkList<T>::SingLinkList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

/*
Class: ~SingleLinkList() Destructor
Description: This class runs when the delete method is called and frees up data.
            It iterates through the list and deletes pointers.
Parameters: None
*/

template <class T>
SingLinkList<T>::~SingLinkList()
{
    Node<T>* temp = this->head;

    while(temp!=this->tail)
    {
        this->head = temp;
        temp = temp->getNext();
        delete head;
    }
    delete tail;
}

/*
Class: addToFront()
Description: Creates and adds a new node to the list, with the inputted data stored in it.
            Changes the value of head accordingly.
Parameters: Data of Template Type.
*/

template <class T>
void SingLinkList<T>::addToFront(T data)
{
    if(this->head == nullptr)
    {
        this->head = new Node<T>(data);
        this->tail = this->head;
    }
    else
        this->head = new Node<T>(this->head, data);

    length++;
}

/*
Class: addToEnd()
Description: Creates and adds a new node to the end of the list with the input data in it.
            Changes the value of the tail node accordingly.
Parameters: Data of Template type.
*/

template <class T>
void SingLinkList<T>::addToEnd(T data)
{
    if(this->head == nullptr)
    {
        this->head = new Node<T>(data);
        this->tail = this->head;
    }
    else
    {
        this->tail->setNext(new Node<T>(data));
        this->tail = this->tail->getNext();
    }
    length++;
}

/*
Class: addAtIndex()
Description: Creates and adds a node containing the input data, at the choice index of user.
            It is adding and moving the node at that index forward, not replacing the node.
Parameters: Data of Template Type.
*/

template <class T>
bool SingLinkList<T>::addAtIndex(T data, int index)
{
    if(index<0 || index>= length)
        return false;
    if(index == 0)
    {
        this->addToFront(data);
        return true;
    }
    if(index == length-1)
    {
        this->addToEnd(data);
        return true;
    }

    Node<T>* temp = head;
    index--;
    while(index--)
    {
        temp = temp->getNext();
    }
    temp->setNext(new Node<T>(temp->getNext(),data));
    length++;
    return true;

}

/*
Class: removeFromFront()
Description: Removes the head node and moves the head pointer to the next node. It deletes
            the space allocated to the node and returns the data stored in it.
Parameters: None
*/

template <class T>
T SingLinkList<T>::removeFromFront()
{
    if(head== nullptr)
        return NULL;


    Node<T> *temp = head;
    head = head->getNext();

    T data =  temp->getData();
    delete temp;
    length--;

    return data;
}

/*
Class:  removeFromEnd()
Description: Removes the end node and deletes the memory from heap. Moves the tail pointer to the
            previous position. It returns the data stored in the node.
Parameters: None
*/
template <class T>
T SingLinkList<T>::removeFromEnd()
{
    if(head == nullptr)
        return NULL;
    Node<T> *temp = head;
    while(temp->getNext()!= this->tail)
    {
        temp = temp->getNext();
    }
    Node<T> *temp2 = tail;
    this->tail = temp;

    T data =  temp2->getData();
    delete temp2;
    length--;

    return data;

}

/*
Class: removeTheFirst()
Description: It removes the first node storing data equal to the input. It changes the previous nodes pointer
            accordingly.
Parameters: data of Template type.
*/

template <class T>
void SingLinkList<T>::removetheFirst(T data)
{
    int index = 0;

    Node<T> *temp= head;

    while(temp->getData()!= data)
    {
       if(temp == tail)
            return;
       temp = temp->getNext();
       index++;
    }

    if(index == 0)
    {
        this->removeFromFront();
        return;
    }
    if(index == length-1)
    {
        this->removeFromEnd();
        return;
    }

     Node<T> *temp2 = head;

     index--;

     while(index--)
     {
         temp2 = temp2->getNext();
     }

     temp2->setNext(temp2->getNext()->getNext());

     delete temp;
     length--;
     return;

}

/*
Class: removeAllOf()
Description: It removes all nodes which have data equal to the input. Changes stuff accordingly
Parameters: Data of Template Type.
*/
template <class T>
void SingLinkList<T>::removeAllOf(T data)
{
    while(true)
    {

    Node<T> *temp= head;

    while(temp->getData()!= data)
    {
       if(temp == tail)
            return;
       temp = temp->getNext();
    }

    if(temp == head)
    {
        this->removeFromFront();
        continue;
    }
    if(temp == tail)
    {
        this->removeFromEnd();
        return;
    }

     Node<T> *temp2 = head;


     while(temp2->getNext()!=temp)
     {
         temp2 = temp2->getNext();
     }

     temp2->setNext(temp2->getNext()->getNext());

     delete temp;
     length--;
     return;
    }
}

/*
Class: elementExists()
Description: Checks to see if the input data exists in any node of the list. Returns true if it does.
            False if it doesn't
Parameters: Data of Template Type
*/
template <class T>
bool SingLinkList<T>::elementExists(T data)
{

    Node<T> *temp= head;

    while(temp->getData!= data)
    {
       if(temp == tail)
            return false;
       temp = temp->getNext();
    }

    return true;
}

/*
Class:Find()
Description: Looks for and returns the pointer of the first occurance of the input data. Returns a nullptr
            if it doesn't exist.
Parameters: Data of type T.
*/
template <class T>
Node<T>* SingLinkList<T>::Find(T data)
{
     Node<T> *temp= head;

    while(temp->getData!= data)
    {
       if(temp == tail)
            return nullptr;
       temp = temp->getNext();
    }

    return temp;
}

/*
Class: indexOf()
Description:Looks for and returns the index of the first occurance of the input data. Returns -1
Parameters: Data of Template Type
*/

template <class T>
int SingLinkList<T>::indexOf(T data)
{
    int index = 0;

    Node<T> *temp= head;

    while(temp->getData()!= data)
    {
       if(temp == tail)
            return -1;
       temp = temp->getNext();
       index++;
    }
    return index;

}

/*
Class: retrieveFront()
Description: Returns the value stored in the first node of the list. Doesn't do any changes to the
            list itself
Parameters: None
*/

template <class T>
T SingLinkList<T>::retrieveFront()
{
    return this->head.getData();
}

/*
Class: retrieveEnd()
Description: Returns the value stored in the last node of the list. Doesn't do any changes to the
            list itself
Parameters: None
*/

template <class T>
T SingLinkList<T>::retrieveEnd()
{
    return this->tail.getData();
}

/*
Class: retrieve()
Description: Returns the value stored in the nth node of the list. Doesn't do any changes to the
            list itself
Parameters: Int index of the list.
*/

template <class T>
T SingLinkList<T>::retrieve(int index)
{
    if(index<0 || index>length-1)
        return nullptr;
    if(index== 0)
        return retrieveFront();
    if(index==length-1)
        return retrieveEnd();

    Node<T> *temp= head;
    index--;
    while(index--)
    {
       temp = temp->getNext();
    }
    return temp.getData();
}

/*
Class: getLength()
Description: Returns the length of the list.
Parameters: None
*/

template <class T>
int SingLinkList<T>::getLength()
{
    return this->length;
}

/*
Class: printList()
Description: Prints the data stored in the list in order. << Operator must be overloaded in
            user-defined classes in order for this to function as expected.
Parameters: None
*/

template <class T>
void SingLinkList<T>::printList()
{
    Node<T>* temp = this->head;
    std::cout<< temp->getData()<< "\t";

    while(temp!=this->tail)
    {
        temp = temp->getNext();
        std::cout<< temp->getData()<< "\t";
    }

    std::cout<< std::endl;

}

/*
Class: emptyList()
Description: Effectively acts as a list cleaner. Destroyes all nodes in the list freeing up memory.
Parameters: None
*/
template <class T>
void SingLinkList<T>::emptyList()
{
    Node<T>* temp = this->head;

    while(temp!=this->tail)
    {
        this->head = temp;
        temp = temp->getNext();
        delete head;
    }
    delete tail;
    this->length = 0;
}



#endif // TAWDE_LIST_HPP_INCLUDED
