#pragma once	

#include<vector>
#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void makeSound() = 0;
	virtual ~Animal() {};
};

class Dog : public Animal
{
public:
	void makeSound() override {
		cout << "Woof!" << endl;
	}

};

class Cat : public Animal
{
public:
	void makeSound() override {
		cout << "Meow!" << endl;
	}

};

class Cow : public Animal
{
public:
	void makeSound() override {
		cout << "Moo!" <<endl;
	}

};

class Zoo
{
private:
	Animal* animals[10];
	int cagenum = 0;

public:
	void addAnimal(Animal* animal)
	{
		animals[cagenum] = animal;
		cagenum++;

		if (cagenum >= 10) {
			cout << "가득참!" << endl;
		}
	}

	void performActions()
	{
		for (auto& animal : animals)
		{
			if (animal != nullptr)
			{
				animal->makeSound();
			}
		}
	}

	virtual ~Zoo() {
		for (auto& animal : animals) {
			delete animal;
		}
	}
};

Animal* createRamdomAnimal()
{
	int num;
	num = rand() % 3;

	switch (num) {
	case 0:
		return new Dog();
	case 1:
		return new Cat();
	case 2:
		return new Cow();
	};

}

int main()
{
	Zoo zoo;

	for (int i = 0; i < 11; i++)
	{
		zoo.addAnimal(createRamdomAnimal());
	}

	zoo.performActions();

}

