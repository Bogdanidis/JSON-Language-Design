#include <iostream>
#include <functional>
#include <stdarg.h>

class Spell
{

public:
	std::string name;

	const Spell* operator[] (const Spell*)const;


	Spell() {
		this->name = "";
	}

	Spell(std::string name) {

		this->name = name;
		Spell *sp = new Spell();
		sp->name = name;
		//std::cout << name;
		allSp.push_back(sp);
	}

	Spell(std::string name, void (function)()) {

		this->name = name;
		Spell *sp = new Spell();
		sp->name = name;

		spell[this->name] = function;
		allSp.push_back(sp);
	}

	void setName(std::string name) {
		this->name = name;

	}

	std::string getName() {
		return name;
	}
	int operator[](int s) {
		
		return 5;
	}
};


const Spell* Spell::operator[](const Spell*sp)const
{
	return sp;
}

bool showAllSpells() {
	for (int i = 0; i < allSp.size(); i++) {

		Spell* wizard = (Spell*)allSp.at(i);
		wizard = (Spell*)allSp.at(i);
		std::cout << wizard->getName() << std::endl;

		std::cout << "\n";
	}
	return true;
}

Spell* get_spell(std::string name) {
	for (int i = 0; i < allWiz.size(); i++) {

		Spell* spell = (Spell*)allSp.at(i);
		spell = (Spell*)allSp.at(i);

		if (!spell->getName().compare(name))
			return spell;
	}
}

bool cast_spell(std::string name) {

	spell[name]();
	return true;
}

int GET_HP(Wizard* wizard) {

	return wizard->getHp();
}

std::string GET_HOUSE(Wizard* wizard) {

	return wizard->getHouse();
}

std::string GET_NAME(Wizard* wizard) {

	return wizard->getName();
}

bool HAS_WAND(Wizard* wizard) {

	return wizard->getWand();
}

//!logic operators

bool NOT(bool statement) {
	return !statement;
}

//! in order for the AND,OR case to work we need variadic templates and use them recursively

//?base case (for AND)
template <typename T, typename F>
bool AND(T t, F t2) {
	return t && t2;
}

//?recursive case (for AND)
template <typename T, typename... Rest>
bool AND(T t, Rest... rest) {
	return t && AND(rest...);
}

//?base case (for OR)
template <typename T, typename F>
bool OR(T t, F t2) {
	return t || t2;
}

//?recursive case (for OR)
template <typename T, typename... Rest>
bool OR(T t, Rest... rest) {
	return t || OR(rest...);
}

//!for DUEL
std::vector<Spell*> getSpells() {
	std::vector<Spell*> spells;

	for (int i = 0; i < allSp.size(); i++) {

		Spell* spell = (Spell*)allSp.at(i);
		spell = (Spell*)allSp.at(i);

		spells.push_back(spell);
	}

	return spells;
}