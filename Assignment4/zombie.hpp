#ifndef ZOMBIE_HPP_INCLUDED
#define ZOMBIE_HPP_INCLUDED
#include<cstdlib>
#include<ctime>
#include "tawde_list.hpp"


class Zombie
{
private:
    char style;

public:
    Zombie();
    Zombie(char);
    char getStyle();
    void setStyle(char);
    int generateAction(SingLinkList <Zombie>*);
    int generateAction(SingLinkList <Zombie>*, int type);
    int randomInRange(int, int);
    Zombie operator=(const Zombie&);

};
Zombie::Zombie()
{
    int temp = this->randomInRange(1,6);

    switch(temp)
    {
    case 1:
        this->style = 'R';
        break;
    case 2:
        this->style = 'Y';
        break;
    case 3:
        this->style = 'G';
        break;
    case 4:
        this->style = 'B';
        break;
    case 5:
        this->style = 'M';
        break;
    case 6:
        this->style = 'C';
        break;
    default:
        this->style = 'D';

    }
}
Zombie::Zombie(char temp)
{
    this->style = temp;
}
char Zombie::getStyle()
{
    return this->style;
}

void Zombie::setStyle(char temp)
{
    this->style = temp;
}

int Zombie::generateAction(SingLinkList<Zombie>* zlist)
{
    int temp = this->randomInRange(1,7);
    Zombie temp2();

    switch(temp)
    {
    case 1:
        zlist->addToFront(temp2->getStyle());
        break;
    case 2:
        zlist->addToEnd(*temp2);
        break;
    case 3:
        zlist->addAtIndex(temp2, this->randomInRange(0, zlist->getLength()) );
        break;
    case 4:
        zlist->removeAllOf(temp2);
        break;
    case 5:
        zlist->removetheFirst(temp2);
        break;
    case 6:
        zlist->addToFront(temp2);
        zlist->addToEnd(temp2);
        zlist->addAtIndex(temp2, (zlist->getLength())/2);
        break;
    case 7:
        zlist->addToFront(temp2);
        zlist->addToEnd(Zombie tempR('R'));
        zlist->addToEnd(Zombie tempR('Y'));
        zlist->addToEnd(Zombie tempR('G'));
        zlist->addToEnd(Zombie tempR('B'));
        zlist->addToEnd(Zombie tempR('M'));
        zlist->addToEnd(Zombie tempR('C'));
        break;
    }
    delete temp2;
    return temp;
}
int Zombie:: generateAction(SingLinkList<Zombie>* zlist, int type)
{
    Zombie temp2();

    switch(type)
    {
    case 1:
        zlist->addToFront(temp2);
        break;
    case 2:
        zlist->addToEnd(temp2);
        break;
    case 3:
        zlist->addAtIndex(temp2, this->randomInRange(0, zlist->getLength()) );
        break;
    case 4:
        zlist->removeAllOf(temp2);
        break;
    case 5:
        zlist->removetheFirst(temp2);
        break;
    case 6:
        zlist->addToFront(temp2);
        zlist->addToEnd(temp2);
        zlist->addAtIndex(temp2, (zlist->getLength())/2);
        break;
    case 7:
        zlist->addToFront(temp2);
        zlist->addToEnd(Zombie tempR('R'));
        zlist->addToEnd(Zombie tempR('Y'));
        zlist->addToEnd(Zombie tempR('G'));
        zlist->addToEnd(Zombie tempR('B'));
        zlist->addToEnd(Zombie tempR('M'));
        zlist->addToEnd(Zombie tempR('C'));
        break;
    }
    delete temp2;
    return type;
}
int Zombie::randomInRange(int min, int max)
{
	return (min + (rand()%(max + 1 -min)));
}

Zombie Zombie::operator=(const Zombie& zom)
{
    this->setStyle(zom.getStyle())
    return zom;
}



#endif // ZOMBIE_HPP_INCLUDED
