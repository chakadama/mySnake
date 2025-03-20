#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
	Cat();
	Cat(int age, std::string name);
	~Cat();
	void sound();
};