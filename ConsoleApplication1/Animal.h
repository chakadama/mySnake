#pragma once

#include <iostream>
#include <vector>
#include <string>

class Animal
{
private:
	int age;
	std::string name;

public:
	Animal();
	Animal(int age, std::string name);
	virtual ~Animal();
	void setAge(int age);
	int getAge();
	void setName(std::string name);
	std::string getName();

	virtual void sound();
};
