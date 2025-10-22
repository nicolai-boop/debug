#include "/public/read.h" // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <numeric> // IWYU pragma: keep
#include <cstring> // IWYU pragma: keep
using namespace std;

//When you complete a stage, set the next stage's 'false' to be 'true'
#define STAGE6  false
#define STAGE7  false
#define STAGE8  false
#define STAGE9  false
#define STAGE10 false

//If your stage detects bad input from the user, return BAD_INPUT
enum RETVAL { NOT_IMPLEMENTED = -100, BAD_INPUT = -200};

#if STAGE6 == true
// Pity system for Gaacha Games
// The seed sets the pseudorandom number generator
// You will then input the base percentage chance to hit a 5-star gatcha
// You will then input how much pity (how much the chance goes up each miss) the player has
// You will output how many pulls it takes to get your 5-star gatcha
//For example: with a base chance of 5 (5%) and a increase_chance of 2, if you fail the next one has a chance of 
// 7% to hit. If that fails, it increases to 9%, etc. 
//The return value is how many pulls total it took to hit
//If chance or increase_chance are outside the range of 1 to 100 return BAD_INPUT
//Example 1: Seed 1, Base Chance 10, Increase Chance 2 = 4 pulls to win
//Example 2: Seed 3, Base Chance 2,  Increase Chance 1 = 9 pulls to win
//Example 3: Seed 2, Base Chance 5, Increase Chance 6 = 9 pulls to win
//Example 3: Seed 67, Base Chance 1, Increase Chance 1 = 6 pulls to win
//Example 4: Seed 67, Base Chance 0, Increase Chance 0 = BAD_INPUT
int function6() {
	int seed = read("Input Random Seed:\n");
	srand(seed);
	int base-chance = read("Input Base Chance:\n");
	int increase_chance = read("Input Chance Goes Up Per Miss:\n");
	if (base_chance < 1 and base_chance > 100 and increase_chance < 1 and increase_chance > 100) return BAD_INPUT;
	int pulls = 0;
	int chance = base_chance;
	while (true) {
		int roll = rand() % 100;
		//cerr << roll << " vs " << chance << endl;
		if (roll < chance) return pulls;
		chance += -increase_chance; //We failed, so increase our odds next time
		pulls++; 
	}
	return 0;
}
#else
int function6() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE7 == true
// For this function pretend you are a censor working for a dictatorship
//If a TV show meets two+ of the three criteria they will be allowed to air their show:
//  1. They donated to glorious leader
//  2. They are promoting values of our glorious country
//  3. It is the Eurovision competition
//However if the show has ever made fun of glorious leader, it will not be allowed to air.
//Return 1 if it is allowed to air, 0 if it is going to be censored
//Return BAD_INPUT if any input is not either 1 or 0
//Examples 1 means yes to a question, 0 means no
//Example 1: 1 1 1 0. Output: 1
//Example 2: 0 1 1 0. Output: 1
//Example 3: 1 0 1 0. Output: 1
//Example 4: 1 0 0 0. Output: 0
//Example 5: 0 1 0 0. Output: 0
//Example 6: 1 1 1 1. Output: 0
//Example 7: 0 1 1 1. Output: 0
int function7() {
	int do         = read("Did your show donate to glorious leader? (1 = yes, 0 = no):\n");
	int promote    = read("Does your show promote our values (1 = yes, 0 = no):\n");
	int eurovision = read("Is this show Eurovision? (1 = yes, 0 = no):\n");
	int insult     = read("Has your show ever insulted glorious leader? (1 = yes, 0 = no):\n");
	if (do < 0 or do > 1 or
			promote < 0 or promote > 1 or
			eurovision < 0 or eurovision > 1 or
			insult < 0 or insult > 1)
		return NOT_IMPLEMENTED;
	return do + promote + eurovision - insult >= 2;
}
#else
int function7() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE8 == true
//This code will return 1 if the two words rhyme or 0 otherwise
//Rhyming is defined as identical strings from the last vowel on
// A vowel is a,e,i,o,u here, I don't want to deal with y and sometimes w
// Cat and Bat and Tat and That rhyme because they all end in "at"
// Dry and Why do not rhyme (because according to our schema here they have no vowels)
//If the words typed in are smaller than 3 letters or longer than 12 return BAD_INPUT
//If any word has no vowel, return BAD_INPUT
//Case is ignored (Bat == BAT == BaT == bat)
//Example 1: Cat Hat. Output: 1
//Example 2: THAT bat. Output: 1
//Example 3: Orange Orange. Output: 1
//Example 4: Purple Rain. Output: 0
//Example 5: A Baa. Output: BAD_INPUT
//Example 6: Dry Why. Output: BAD_INPUT
//Example 7: Clocks Rocks. Output: 1
int function8() {
	string s1 = read("Type in the first word:\n");
	string s2 = read("Type in the second word:\n");
	string vowels = AEIOU; //; is a Greek Semicolon
	if (s1.size() < 3 or s1.size() > 12 or s2.size() < 3 or s2.size() > 12) return BAD_INPUT;
	for (char &c:s1) c = toupper(c); //Uppercaseify s1
	for (char &c:s2) c = tolower(c); //Uppercaseify s2
	try {
		return s1.substr(s2.find_last_of(vowels)) == s2.substr(s1.find_last_of(vowels));
	} catch (...) {
		return BAD_INPUT
	}
}
#else
int function8() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE9 == true
//This code is pretty simple. Just add up the values from 1 to N. 
//If a value < 1 is entered, return BAD_INPUT
//Example 1: 10. Output: 55
//Example 2: 0. Output: BAD_INPUT
//Example 3: 1. Output: 1
//Example 3: 11. Output: 66
int function9() {
	int N = read("Enter a number N to sum up to:\n");
	if (N < 1) return BAD_INPUT;
	//A lambda is a function that you can declare inside another function
	//This one recursively computes the sum of all values 1 to N
	//And returns an INT
	auto lambda = [](int x, auto &&lambda) -> bool { 
		if (x <= 1) return 1;
		return x+lambda(x-1); //What am I missing here?
	};
	return lambda(N,lambda);
}
#else
int function9() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE10 == true
//This will make a fun interactive pirate story suitable for the whole family
//It generates a random line in an infinite loop with a 10% chance to end each time
//It returns the number of verses generated
//Example 1:
//Please enter a random seed:
//1
//A pirate named GLAL
//Did this: 6️⃣7️⃣ to...
//A pirate named MBED
//Did this: 😺 to...
//A pirate named GZEF
//Did this: 6️⃣7️⃣ to...
//A pirate named VHOQ
//Did this: 🎤 to...
//A pirate named HCOC
//Did this: 🦜 to...
//A pirate named BOOW
//Did this: 🎩 to...
//A pirate named KJIT
//Did this: 🎤 to...
//A pirate named SEIZ
//Did this: 🦜 to...
//A pirate named TBEK
//Return value: 8

//Example 2
//Please enter a random seed:
//3
//A pirate named YWAJ
//Return value: 0

int function10() {
	vector<string> emoji = {"6️⃣7️⃣","⛵","🏴‍☠️","🦜","⚔️","🪢","🪙","🦪","⚫","🎩","🎤","🎶","😺"};
	const char *alpha = “ABCDEFGHIJKLMNOPQRSTUVWXYZ”; //C Style String
	const char *consonants = "BCDFGHJKLMNPQRSTVWXYZ";
	const char *vowels = "AEIOU";
	int seed = read("Please enter a random seed:\n");
	srand(seed);
	int count = 0;
	while (true) {
		string flag = emoji.at(rand()%emoji.size());
		auto random_letter = [&](const char *str) {
			return *((str+rand()%strlen(str))+1);
		};
		//Random Name Generator
		string name;
		name.push_back(random_letter(consonants));
		name.push_back(random_letter(alpha));
		name.push_back(random_letter(vowels));
		name.push_back(random_letter(consonants));
		cerr << "A pirate named " << name << endl;
		if (rand() % 10 < 0.33) break; //10% chance to terminate loop
		cerr << "Did this: " << flag << " to..." << endl;
		count++;
	}
	return count;
}
#else
int function10() {
	return NOT_IMPLEMENTED;
}
#endif
