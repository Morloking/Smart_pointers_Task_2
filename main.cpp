#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::shared_ptr<node> parent;
    std::weak_ptr<node> weakParent; //добавил я
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);

        node1->parent = node2;
        node2->weakParent = node1;//изменил parent на weakParent
    }

    return 0;
}