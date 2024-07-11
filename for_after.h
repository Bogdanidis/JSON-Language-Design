#include <iostream>
#include <functional>
#include <stdarg.h>
int how_many_rounds = 0;
bool p1isAttacker;
std::string isfor_or_isafter = "";
int first_time = 0;
std::vector<int> for_after_rounds;
std::vector<std::string> for_or_after;
std::vector<bool> for_after_P1attacker;
std::vector<void(*)()> for_after_function;
class for_after
{

public:
	

	for_after() {
		if (first_time) {
			//std::cout << "i am in" << how_many_rounds << p1isAttacker << isfor_or_isafter;

			for_after_rounds.push_back(how_many_rounds);
			for_after_P1attacker.push_back(p1isAttacker);
			for_or_after.push_back(isfor_or_isafter);
			std::cout << "size" << for_after_rounds.size() << for_after_P1attacker.size() << for_or_after.size();
		}
		first_time = 1;
	}

	
	
	void operator,(void (function)()) {
		//std::cout << "i am in!!!!!!!!!!";
		for_after_function.push_back(function);
		std::cout << for_after_function.size();
	}
	
};


bool cast_for_after_spell(int i) {

	for_after_function.at(i)();
	return true;
}

