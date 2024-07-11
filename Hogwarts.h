#include<iostream>
#include<fstream>
#include<istream>
#include<string>
#include<vector>
#include "Wizard.h"
#include "Spell.h"
#include "o.h"
#include "for_after.h"

#define UCLASS()
#define GENERATED_BODY()
#define UFUNCTION()

#define BEGIN_GAME int main(){ new Wizard()
#define END_GAME ; return 0;}
Wizard PLAYER1;
Wizard PLAYER2;
for_after use;
#define CREATE ;
#define WIZARD new Wizard
#define WIZARDS Wizard()
#define LEARN ;Spell()
#define MR	;Wizard_learn=
#define MRS	;Wizard_learn=
#define NAME false ? ""
#define HOUSE false ? ""
#define HP false ? 0
#define SPELL new Spell
#define SPELLS Spell()
#define FOR ; isfor_or_isafter = "for"; how_many_rounds =
#define AFTER ; isfor_or_isafter = "after"; how_many_rounds =
#define ROUNDS ; for_after(),[](
#define ACTION false ? []{}
#define START []{
#define END ;}


Wizard getAttacker() {
		if (PLAYER1.isAttacker) 
			return PLAYER1;
		return PLAYER2;
		
	
}

Wizard getDefender() {
	if (PLAYER1.isDefender)
		return PLAYER1;
	return PLAYER2;
}
std::string get_house(Wizard arg1) {

	return arg1.house;

}
std::string get_name(Wizard arg1) {

	return arg1.name;

}
int get_hp(Wizard arg1) {

	return arg1.hp;
}

#define ATTACKER getAttacker(),
#define DEFENDER getDefender(),
#define GET_HOUSE(args ,...)	get_house(args __VA_ARGS__)
#define GET_NAME(args ,...)	get_name(args __VA_ARGS__)
#define GET_HP(args ,...)	get_hp(args __VA_ARGS__)
#define DAMAGE		; dmg = 1; 
#define HEAL		; hl = 1; 
#define EQUIP		;eq=1;
#define IF if(
#define DO ){
#define ELSE_IF ;}else if
#define ELSE ;}else{
#define SPELL_NAME(x)		-parminfo(#x )
#define SHOW && std::cout <<
#define _		0
#define á		o()
//! DUEL function
#define DUEL ;Duel();

int parminfo(std::string s) {
	std::vector<Wizard*> wizards = getWizards();
	for (int i = 0; i < wizards.size(); i++) {
		if (wizards.at(i)->name.compare(Wizard_learn) == 0) {
			wizards.at(i)->knownSpells.push_back(s);
		}
	}

	return 5;
}

void operator,(Wizard wiz, int rhs) {

	if (eq) {
		eq = 0;
		if (rhs) {
			std::cout << "put wand"<<wiz.player_num;
			if (wiz.player_num.compare("player1") == 0)
				PLAYER1.has_wand = 1;
			else
				PLAYER2.has_wand = 1;
		}else {
			std::cout << "remove wand"<<wiz.player_num;
			if (wiz.player_num.compare("player1") == 0)
				PLAYER1.has_wand = 0;
			else
				PLAYER2.has_wand = 0;
		}
		return;
	}

	double attP=0.0, defP = 0.0 , autoHeal = 0.0;

	std::string attacker, defender;

	if (PLAYER1.isAttacker) {
		attacker = PLAYER1.getHouse();
		defender = PLAYER2.getHouse();
	}
	else {
		attacker = PLAYER2.getHouse();
		defender = PLAYER1.getHouse();
	}

	//Attack bonus
	if (!attacker.compare("Slytherin")) {
		if(!defender.compare("Gryffindor")) attP = Attack::Slytherin::toGryffindor;
		else								attP = Attack::Slytherin::toAll;
	}
	if (!attacker.compare("Hufflepuff"))	attP = Attack::Hufflepuff::toAll;

	//Defence bonus
	if (!defender.compare("Gryffindor")) {
		if (!attacker.compare("Slytherin"))	defP = Defense::Gryffindor::fromSlytherin;
		else								defP = Defense::Gryffindor::fromAll;
	}
	if (!defender.compare("Hufflepuff"))	defP = Defense::Hufflepuff::fromAll;

	//other bonuses
	if (!attacker.compare("Ravenclaw") && ROUND % 2 == 1) attP = Attack::Ravenclaw::toAll_whenOdd;
	//if (!attacker.compare("Ravenclaw") && ROUND % 2 == 0) autoHeal = Defense::Ravenclaw::healMaxPrecentege_whenEven;

	rhs += int(rhs * attP);
	rhs -= int(rhs * defP);
	

	if (dmg) {
		dmg = 0;
		if (wiz.player_num.compare("player1") == 0)
			PLAYER1.hp -= rhs;
		else
			PLAYER2.hp -= rhs;
	}else if (hl) {
		hl = 0;
		if (wiz.player_num.compare("player1")==0)
			PLAYER1.hp += rhs;
		else
			PLAYER2.hp += rhs;
	}
}


bool Duel() {
	ROUND = 1;
	std::cout << "----------------------------------------";
	std::cout << "HARRY POTTER THE GAME";
	std::cout << "----------------------------------------\n\n";

	std::cout << "Player1 select wizard:\n";
	std::cout << "----------------------------\n";

	//! show available wizards
	std::vector<Wizard*> wizards = getWizards();
	for (int i = 0; i < wizards.size(); i++) {
		std::cout << wizards.at(i)->getName() << std::endl;
	}
	std::cout << "----------------------------\n";

	//!choose wizard palyer1
	char input1[100];
	char input2[100];
	bool notExists = true;

	while (notExists) {

		
		std::cin.getline(input1, sizeof(input1));
		for (int i = 0; i < wizards.size(); i++) {
			//std::cout << wizards.at(i)->getName();
			if (!wizards.at(i)->getName().compare(input1))
				notExists = false;
		}
	}

	std::cout << std::endl;
	std::cout << "Player2 select wizard:\n";
	std::cout << "----------------------------\n";

	//! show available wizards
	for (int i = 0; i < wizards.size(); i++) {
		std::cout << wizards.at(i)->getName() << std::endl;
	}
	std::cout << "----------------------------\n";

	//!choose wizard palyer2
	notExists = true;

	while (notExists) {

		std::cin.getline(input2, sizeof(input2));
		for (int i = 0; i < wizards.size(); i++) {

			if (!wizards.at(i)->getName().compare(input2))
				notExists = false;
		}
	}

	std::cout << std::endl;

	//! pre-round set up (create instanses of wizards for the players)

	//? make vector withe the duelists
	std::vector<Wizard*> duelists;
	for (int i = 0; i < wizards.size(); i++) {
		if (!wizards.at(i)->getName().compare(input1))
			duelists.push_back(wizards.at(i));
	}
	for (int i = 0; i < wizards.size(); i++) {
		if (!wizards.at(i)->getName().compare(input2))
			duelists.push_back(wizards.at(i));
	}


	
	bool someoneDied = false;
	bool bothDied = false;
	std::string isDead;
	std::string isAlive;


	PLAYER1.setName(duelists.at(0)->name);
	PLAYER1.setHouse(duelists.at(0)->house);
	PLAYER1.setHp(duelists.at(0)->hp);
	PLAYER1.player_num = "player1";
	PLAYER2.setName(duelists.at(1)->name);
	PLAYER2.setHouse(duelists.at(1)->house);
	PLAYER2.setHp(duelists.at(1)->hp);
	PLAYER2.player_num="player2";

	PLAYER1.knownSpells = duelists.at(0)->knownSpells;
	PLAYER2.knownSpells = duelists.at(1)->knownSpells;

	int	initialHp1 = PLAYER1.hp;
	int	initialHp2 = PLAYER2.hp;

	//! battle begins now

	while (!someoneDied) {

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "Round " << ROUND << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		for (int i = 0; i < for_after_rounds.size(); i++)
			for_after_rounds.at(i) = for_after_rounds.at(i)-1;
		//todo make player1 attacker and player2 defender
		//todo i need them insisde allWiz to cast spells (i will delete them at the end of the game)
		 
		PLAYER1.isAttacker = true;
		p1isAttacker = true;
		PLAYER2.isDefender = true;
		PLAYER2.isAttacker = false;
		PLAYER1.isDefender = false;

		//!player1 select spell
		if (PLAYER1.has_wand) {
			std::cout << PLAYER1.name << "(Player1)" << " select spell:" << std::endl;
			std::cout << "----------------------------\n";
			for (int i = 0; i < PLAYER1.knownSpells.size(); i++) {

				std::cout << PLAYER1.knownSpells.at(i) << std::endl;
			}
			std::cout << "----------------------------\n";

			std::string spell1;
			bool notExists = true;
			//! show available spells

			while (notExists) {

				std::cin >> spell1;
				for (int i = 0; i < PLAYER1.knownSpells.size(); i++) {
					if (!PLAYER1.knownSpells.at(i).compare(spell1))
						notExists = false;
				}
			}

			//use passive heal
			if (!(PLAYER1.getHouse().compare("Ravenclaw")) && (ROUND % 2 == 0)) {
				double autoHeal = Defense::Ravenclaw::healMaxPrecentege_whenEven;
				PLAYER1.hp += initialHp1 * autoHeal;
				if (PLAYER1.hp > initialHp1) PLAYER1.hp = initialHp1;
			}

			//! spell1 attack
			cast_spell(spell1);
		}
		else {
			std::cout << "player1 no wand"<<std::endl;
		}
		for (int i = 0; i < for_or_after.size(); i++) {
			if (for_or_after.at(i).compare("for") == 0) {
				if (for_after_rounds.at(i) > 0)
					if (for_after_P1attacker.at(i))
						cast_for_after_spell(i);


			}else {
				if (for_after_rounds.at(i) == 0)
					if (for_after_P1attacker.at(i))
							cast_for_after_spell(i);
			}
		}

		if (PLAYER1.hp <= 0 && PLAYER2.hp > 0) {
			isDead = PLAYER1.name;
			isAlive = PLAYER2.name;
			someoneDied = true;
			break;

		}
		else if (PLAYER2.hp <= 0 && PLAYER1.hp > 0) {
			isDead = PLAYER2.name;
			isAlive = PLAYER1.name;
			someoneDied = true;
			break;

		}
		else if (PLAYER1.hp <= 0 && PLAYER2.hp <= 0) {
			bothDied = true;
			break;
		}

		//! show results
		std::string hasWand1;
		std::string hasWand2;
		if (PLAYER1.has_wand) hasWand1 = "equipped";
		else hasWand1 = "not equiped";
		if (PLAYER2.has_wand) hasWand2 = "equipped";
		else hasWand2 = "not equiped";

		std::cout << "\n############################" << std::endl;
		std::cout << "NAME: " << PLAYER1.name << std::endl;
		std::cout << "HP: " << PLAYER1.hp << std::endl;
		std::cout << "WAND: " << hasWand1 << std::endl;
		std::cout << "############################\n\n" << std::endl;

		std::cout << "############################" << std::endl;
		std::cout << "NAME: " << PLAYER2.name << std::endl;
		std::cout << "HP: " << PLAYER2.hp << std::endl;
		std::cout << "WAND: " << hasWand2 << std::endl;
		std::cout << "############################\n\n" << std::endl;


		//!same for player 2
		PLAYER1.isAttacker = false;
		p1isAttacker = false;
		PLAYER2.isDefender = false;
		PLAYER2.isAttacker = true;
		PLAYER1.isDefender = true;
		if (PLAYER2.has_wand) {
			//!player1 select spell
			std::cout << PLAYER2.name << "(Player2)" << " select spell:" << std::endl;
			std::cout << "----------------------------\n";
			for (int i = 0; i < PLAYER2.knownSpells.size(); i++) {

				std::cout << PLAYER2.knownSpells.at(i) << std::endl;
			}
			std::cout << "----------------------------\n";

			std::string spell2;
			notExists = true;
			//! show available spells
			while (notExists) {

				std::cin >> spell2;
				for (int i = 0; i < PLAYER2.knownSpells.size(); i++) {

					if (!PLAYER2.knownSpells.at(i).compare(spell2))
						notExists = false;
				}
			}

			//use passive heal
			if (!(PLAYER2.getHouse().compare("Ravenclaw")) && (ROUND % 2 == 0)) {
				double autoHeal = Defense::Ravenclaw::healMaxPrecentege_whenEven;
				PLAYER2.hp += initialHp2 * autoHeal;
				if (PLAYER2.hp > initialHp2) PLAYER2.hp = initialHp2;
			}

			//! spell2 attack
			cast_spell(spell2);
		}
		else {
			std::cout << "player2 no wand" << std::endl;
		}
		for (int i = 0; i < for_or_after.size(); i++) {
			if (for_or_after.at(i).compare("for") == 0) {
				if (for_after_rounds.at(i) > 0)
					if (!(for_after_P1attacker.at(i)))
						cast_for_after_spell(i);


			}
			else {
				if (for_after_rounds.at(i) == 0)
					if (!(for_after_P1attacker.at(i)))
						cast_for_after_spell(i);
			}
		}
		if (PLAYER1.hp <= 0 && PLAYER2.hp > 0) {
			isDead = PLAYER1.name;
			isAlive = PLAYER2.name;
			someoneDied = true;
			break;

		}
		else if (PLAYER2.hp <= 0 && PLAYER1.hp > 0) {
			isDead = PLAYER2.name;
			isAlive = PLAYER1.name;
			someoneDied = true;
			break;

		}
		else if (PLAYER1.hp <= 0 && PLAYER2.hp <= 0) {
			bothDied = true;
			break;
		}

		//! show results
		if (PLAYER1.has_wand) hasWand1 = "equipped";
		else hasWand1 = "not equiped";
		if (PLAYER2.has_wand) hasWand2 = "equipped";
		else hasWand2 = "not equiped";

		std::cout << "\n############################" << std::endl;
		std::cout << "NAME: " << PLAYER1.name << std::endl;
		std::cout << "HP: " << PLAYER1.hp << std::endl;
		std::cout << "WAND: " << hasWand1 << std::endl;
		std::cout << "############################\n\n" << std::endl;

		std::cout << "############################" << std::endl;
		std::cout << "NAME: " << PLAYER2.name << std::endl;
		std::cout << "HP: " << PLAYER2.hp << std::endl;
		std::cout << "WAND: " << hasWand2 << std::endl;
		std::cout << "############################\n\n" << std::endl;

		ROUND++;
	}

	std::cout << "\n\n" << std::endl;
	if (bothDied) {
		std::cout << "The duel was fatal for both the wizards" << std::endl;
	}
	else {
		std::cout << "Wizard " << isAlive << " has eliminated wizard " << isDead << std::endl;
	}

	return true;
}