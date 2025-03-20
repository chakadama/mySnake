#pragma once
#include "Animal.h"
class Dog : public Animal {
public:
	Dog();
	Dog(int age, std::string name);
	~Dog();
	void sound();
};