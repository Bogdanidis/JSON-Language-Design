#include "Main.h"
#include <string>
#include <iostream>

class Wizard
{
public:

	const Wizard* operator[] (const Wizard*) const;

	

	Wizard() {

		this->name = "";
		this->house = "";
		this->hp = 0;
		this->has_wand = true;

	}

	Wizard(std::string name, std::string house, int hp) {
		this->name = name;
		this->house = house;
		this->hp = hp;
		Wizard *wiz = new Wizard();
		wiz->name = name;
		//std::cout << name;
		wiz->house = house;
		wiz->hp = hp;
		allWiz.push_back(wiz);
	}
	void setName(std::string name) {
		this->name = name;
	}

	void setHouse(std::string house) {
		this->house = house;
	}
	void setHp(int hp) {
		this->hp = hp;
	}
	void setWand(int has_wand) {
		this->has_wand = has_wand;
	}
	std::string getName() {
		return name;
	}
	std::string getHouse() {
		return house;
	}
	int getHp() {
		return hp;
	}
	
	void equipWand(int wand) {
		this->has_wand = true;
	}
	void unequipWand(int wand) {
		this->has_wand = false;
	}
	bool getWand() {
		return has_wand;
	}

	std::string name;
	std::string house;
	int hp;
	std::string player_num;
	bool has_wand = false;

	//get the ones fighting
	bool isAttacker = false;
	bool isDefender = false;
	
	std::vector<std::string> knownSpells;
	
};

 


const Wizard* Wizard::operator[](const Wizard*wiz) const
{
	return wiz;
}


bool showAllWizards() {
	for (int i = 0; i < allWiz.size(); i++) {

		Wizard* wizard = (Wizard*)allWiz.at(i);
		wizard = (Wizard*)allWiz.at(i);
		std::cout << wizard->getName() << std::endl;
		std::cout << wizard->getHouse() << std::endl;
		std::cout << wizard->getHp() << std::endl;
		std::cout << "Wand: " << wizard->has_wand << std::endl;
		std::cout << "Attacker: " << wizard->isAttacker << std::endl;
		std::cout << "Defender: " << wizard->isDefender << std::endl;

		std::cout << "\n";
	}
	return true;
}

//!for spellcasting
Wizard* get_attacker() {
	for (int i = 0; i < allWiz.size(); i++) {

		Wizard* wizard = (Wizard*)allWiz.at(i);
		wizard = (Wizard*)allWiz.at(i);

		if (wizard->isAttacker)
			return wizard;
	}
}

bool make_attacker(std::string name) {
	for (int i = 0; i < allWiz.size(); i++) {

		Wizard* wizard = (Wizard*)allWiz.at(i);
		wizard = (Wizard*)allWiz.at(i);

		if (!wizard->getName().compare(name)) {
			wizard->isAttacker = true;
		}
	}
	return true;
}

Wizard* get_defender() {
	for (int i = 0; i < allWiz.size(); i++) {

		Wizard* wizard = (Wizard*)allWiz.at(i);
		wizard = (Wizard*)allWiz.at(i);

		if (wizard->isDefender)
			return wizard;
	}
}

bool make_defender(std::string name) {
	for (int i = 0; i < allWiz.size(); i++) {

		Wizard* wizard = (Wizard*)allWiz.at(i);
		wizard = (Wizard*)allWiz.at(i);

		if (!wizard->getName().compare(name)) {
			wizard->isDefender = true;
		}
	}
	return true;
}

//!for DUEL
std::vector<Wizard*> getWizards() {
	std::vector<Wizard*> wizards;

	for (int i = 0; i < allWiz.size(); i++) {

		Wizard* wizard = (Wizard*)allWiz.at(i);
		wizard = (Wizard*)allWiz.at(i);

		wizards.push_back(wizard);
	}

	return wizards;
}

std::vector<Wizard*> DUELISTS;

