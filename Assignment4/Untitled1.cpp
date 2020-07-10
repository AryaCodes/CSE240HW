#include<iostream>

class Parent
{
    public:
        virtual void method()
        {
            std::cout << "from PARENT" << std::endl;
        }

        virtual ~Parent() {}
        void baseMethod() {}
};

class Child : public Parent
{
    public:
        void method()
        {
            std::cout << "from CHILD" << std::endl;
        }

        ~Child() {}
};
int main(void)
{
Parent* item = new Child();
item->method();
delete item;
return 0;
}
