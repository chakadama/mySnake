#include "Dog.h"

Dog::Dog() : Animal(0, "")
{
	std::cout << "构造Dog" << std::endl;
}

Dog::Dog(int age, std::string name) : Animal(age, name)
{
	std::cout << "带参构造Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "析构Dog" << std::endl;
}

void Dog::sound()
{
	std::cout << "Bark!" << std::endl;
}