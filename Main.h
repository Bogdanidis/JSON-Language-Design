#include<iostream>
#include<fstream>
#include<istream>
#include<string>
#include<vector>
#include <map>

#define UCLASS()
#define GENERATED_BODY()
#define UFUNCTION()

std::vector<void*> allWiz;
std::vector<void*> allSp;
std::map<std::string, void(*)()> spell;
int dmg = 0;
int ROUND = 0;
std::string Wizard_learn;
int hl = 0;
int eq = 0;
namespace Defense {
	namespace Gryffindor {
		double fromSlytherin = 0.3;
		double fromAll = 0.2;
	}
	namespace Hufflepuff {
		double fromAll = 0.07;
	}
	namespace Ravenclaw {
		double healMaxPrecentege_whenEven = 0.05;
	}
}
namespace Attack {
	namespace Slytherin {
		double toGryffindor = 0.2;
		double toAll = 0.15;
	}
	namespace Hufflepuff {
		double toAll = 0.07;
	}
	namespace Ravenclaw {
		double toAll_whenOdd = 0.07;
	}
}