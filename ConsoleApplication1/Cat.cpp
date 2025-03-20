#include "Cat.h"

Cat::Cat() : Animal(0, "") {
	std::cout << "构造Cat" << std::endl;
}

Cat::Cat(int age, std::string name) : Animal(age, name) {
	std::cout << "带参构造Cat" << std::endl;
}

Cat::~Cat() {
	std::cout << "析构Cat" << std::endl;
}

void Cat::sound() {
	std::cout << "Meow!" << std::endl;
}