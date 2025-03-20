#include "Animal.h"

Animal::Animal() : age(0), name("") {
	std::cout << "构造animal" << std::endl;
}

Animal::Animal(int age, std::string name) : age(age), name(name) {
	std::cout << "带参构造animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "析构animal" << std::endl;
}

void Animal::setAge(int age)
{
	this->age = age;
}

int Animal::getAge()
{
	return this->age;
}

void Animal::setName(std::string name)
{
	this->name = name;
}

std::string Animal::getName()
{
	return this->name;
}

void Animal::sound() {
	std::cout << "animal sound" << std::endl;
}