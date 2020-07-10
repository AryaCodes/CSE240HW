#include <iostream>
#include<cstdlib>
#include<ctime>
#include "tawde_list.hpp"

using namespace std;

int main()
{
    srand((unsigned)time(0));

    SingLinkList<int>* temp= new SingLinkList<int>();

    cout<<"temp->addToFront(1);"<< endl;
    temp->addToFront(1);
    cout<<"temp->addToFront(2);"<< endl;
    temp->addToFront(2);
    cout<<"temp->addToFront(3);"<< endl;
    temp->addToFront(3);
    cout<<"temp->addToFront(4);"<< endl;
    temp->addToFront(4);
    cout<<"temp->printList();"<< endl;
    temp->printList();
    cout<<"temp->indexOf(3)"<< endl;
    cout<< temp->indexOf(3)<< endl;
    cout<<"temp->addToFront(5);"<< endl;
    temp->addToFront(5);
    cout<<"temp->addToEnd(0);"<< endl;
    temp->addToEnd(0);
    cout<<"temp->addAtIndex(1,4);"<<endl;
    temp->addAtIndex(100, 3);
    cout<<"temp->printList();"<< endl;
    temp->printList();
    cout<<"temp->removetheFirst(1);"<< endl;
    temp->removetheFirst(1);
    cout<<"temp->printList();"<< endl;
    temp->printList();
    cout<<"temp->emptyList();"<< endl;
    temp->emptyList();
    cout<<"temp->addToEnd(3);"<< endl;
    temp->addToEnd(3);
    cout<<"temp->addToEnd(3);"<< endl;
    temp->addToEnd(3);
    cout<<"temp->addToEnd(3);"<< endl;
    temp->addToEnd(3);
    cout<<"temp->addToEnd(3);"<< endl;
    temp->addToEnd(3);
    temp->addToEnd(4);
    cout<<"temp->printList();"<< endl;
    temp->printList();
    cout<<"temp->removeAllOf(3);"<< endl;
    temp->removeAllOf(3);
    cout<<" temp->printList();"<< endl;
    temp->printList();
    cout<<"End Demonstration.";



    delete temp;

    return 0;
}
