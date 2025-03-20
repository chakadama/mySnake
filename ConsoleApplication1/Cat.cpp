#include "Cat.h"

Cat::Cat() : Animal(0, "") {
	std::cout << "����Cat" << std::endl;
}

Cat::Cat(int age, std::string name) : Animal(age, name) {
	std::cout << "���ι���Cat" << std::endl;
}

Cat::~Cat() {
	std::cout << "����Cat" << std::endl;
}

void Cat::sound() {
	std::cout << "Meow!" << std::endl;
}