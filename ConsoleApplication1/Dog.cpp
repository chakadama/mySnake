#include "Dog.h"

Dog::Dog() : Animal(0, "")
{
	std::cout << "����Dog" << std::endl;
}

Dog::Dog(int age, std::string name) : Animal(age, name)
{
	std::cout << "���ι���Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "����Dog" << std::endl;
}

void Dog::sound()
{
	std::cout << "Bark!" << std::endl;
}