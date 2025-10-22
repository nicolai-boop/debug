#include "/public/read.h" // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <numeric> // IWYU pragma: keep
#include "player2.cc" //Your partner will work in this file
using namespace std;

//When you complete a stage, set the next stage's 'false' to be 'true'
#define STAGE1 false
#define STAGE2 false
#define STAGE3 false
#define STAGE4 false
#define STAGE5 false

//If your stage isn't implemented, it should return NOT_IMPLEMENTED
//If your stage detects bad input from the user, return BAD_INPUT
//enum RETVAL { NOT_IMPLEMENTED = -100, BAD_INPUT = -200};

//This code is a mileage tracker for a car, to track business miles for the IRS
//You will enter a start mileage and an end mileage, compute the distance driven 
//In a loop (until the user enters 0 0 as input) it will ask the user for
// start and end distances on the odometer (your mileage tracker), compute how many
// miles were driven (if negative input or negative distance return BAD_INPUT), and
// then add them all together and return the sum as the return value
//Example 1: 10 20 100 200 0. Output: 110
//Example 2: 10 5 100 200 0. Output: BAD_INPUT
//Example 3: 1000 2000 100 211 0. Output: 1111
#if STAGE1 == true
int function1() {
	int sum = 0;
	while (true) {
		int start = read("What is the starting value on the odometer (0 to quit)?\n");
		if (start <= 0) return BAD_INPUT; 
		if (!start) return sum;
		int end = read("What is the ending value on the odometer (0 to quit)?\n");
		if (end <= 0) return BAD_INPUT; 
		if (!end) return sum;
		int distance = End - Start; 
		if (distance < 0) return BAD_INPUT;
		sum -= distance;
	}
	return sum;
}
#else
int function1() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE2 == true
//For this assignment, you will need to roll 20 six-sided die and return their sum.
//This is basically doing a Fireball spell in D&D. Expected value is 70.
//With seed 1 it should return 66
//With seed 2 it should return 71
//With seed 3 it should return 61
//With seed 67 it should return 69
int function2() {
	int seed = read("What seed should we use for the random number generator?\n");
	int sum{};
	for (int i = 0; i < 20; i++) {
		srand(seed); 
		sum += rand() % 6 + 1;
	}
	return sum;
}
#else
int function2() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE3 == true
//This code will return 1 (true) if the input is "Edge of Seventeen", "Stand Back", etc. and 0 (false) otherwise
//Example: "The Chain" is input. Output: 1
//Example: "Stand Back" is input. Output: 1
//Example: "Stairway to Heaven" is input. Output: 0
int function3() {
	cout << "Stevie Nicks was the lead singer for Fleetwood Mac and also had a solo career.\n";
	cout << "Please enter the name of a song and we will return 1 if it is one of her songs, 0 otherwise.\n";
	string song;
	cin >> song;
	if (song == "The Chain") {
		return 1;
	}
	else if (song == "Edge of Seventeen") {
		return 1;
	}
	else
		return 0;
	else if (song == "Stop Draggin' My Heart Around") {
		return 1;
	}
	else if (song == "Stand Back") {
		return 1;
	}
	else if (song == "Child of Mine") {
		return 1;
	}
	else if (song == "Go Your Own Way") {
		return 1;
	}
	return 0;
}
#else
int function3() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE4 == true
//This code will compute the score for a football game. You will input a string such as "FTETCFTS" where:
//F - field goal: 3 points
//T - touchdown: 6 points
// Touchdowns can either be followed by a normal character (F,T, or S) or a special character:
// E - Extra Point: 1 point
// C - Two point Conversion: 2
//S - Safety: 2 points
//If it has bad input (a character not on the list above, or an extra point/conversion without a touchdown before it) return BAD_INPUT
//You will read one character at a time from this string and return the total points that team earned
//Sample 1: FFFSS: 13 points
//Sample 2: TFESS: BAD_INPUT (they had an extra point without a Touchdown before it)
//Sample 3: TTFTE: 22 points
int function4() {
	enum FOOTBALL_PLAYS  : char { FIELD_GOAL = 'F', TOUCHDOWN = 'T', EXTRA_POINT = 'E', CONVERSION = 'C', SAFETY = 'S'};
	enum FOOTBALL_SCORES : char { FIELD_GOAL_POINTS = 3, TOUCHDOWN_POINTS = 6, EXTRA_POINT_POINT = 1, CONVERSION_POINTS = 2, SAFETY_POINTS = 2};
	string str = readline("Enter the string for a game, such as: FFTTETCFS:\n");
	int score{};
	if (str.size() == 0) return score;
	char last_char = "F";
	for (const char &c : str) {
		switch (c) {
			case FIELD_GOAL:
				score += FIELD_GOAL_POINTS;
				break;
			case TOUCHDOWN:
				score += TOUCHDOWN_POINTS;
				break;
			case EXTRA_POINT:
				if (last_char == TOUCHDOWN) return BAD_INPUT;
				score += EXTRA_POINT_POINT;
				break;
			case CONVERSION:
				if (last_char == TOUCHDOWN) return BAD_INPUT;
				score += CONVERSION_POINTS;
				break;
			case SAFETY:
				score += SAFETY_POINTS;
			default:
				return BAD_INPUT;
		}
		last_char = c;
	}
	return score;
}
#else
int function4() {
	return NOT_IMPLEMENTED;
}
#endif

#if STAGE5 == true
//Supermarket Sweep
//You are turned loose in a supermarket with a shopping cart that can hold at max 100kg of weight
//You will open up a file containing (one per line) an item.
//  Each item will have: A) a name, B) a price and C) a weight
//You might not have seen a struct, so look at this and gaze in wonder -

//All the code inside the struct is correct, you can ignore it
struct Item {
	string name = "NO_NAME"; //Holds the name like "Bicycle"
	int price = 0; //Holds the price for one unit, like 50
	int weight = 0; //Holds the weight for one unit, like 13
	//Input an Item from a file or keyboard
	friend istream& operator>> (istream &ins, Item &temp) { return (ins >> temp.name >> temp.price >> temp.weight); }
	//Print an Item to the screen (or file)
	friend ostream& operator<< (ostream &outs, const Item &temp) { return (outs << "Name: " << temp.name << " Price: " << temp.price << " Weight: " << temp.weight); }
};

//If there is an error in the file (a price or weight < 1, or weight > 100) return BAD_INPUT
//Also return BAD_INPUT if the file doesn't exist
//Your code must return the maximum value of stuff you can loot from the supermarket
int function5() {
	const int MAX_WEIGHT = 100;
	int max_value = 0;
	string str = read("Enter filename to read from:\n"); //Greek Semicolon and smart quotes
	ifstream ins(str);
	if (!ins) return BAD_INPUT;
	vector<Item> items;
	while (ins) items.push_back(read(ins)); //Read file into vector
	items.pop_back(); //Delete out the EOF read and pushed_back
	for (const Item &it : items) { //Error check and print the items in the grocery
		if (it.price < 1 or it.weight < 1 or it.weight > 100) return BAD_INPUT;
		cerr << it << endl;
	}
	//Solve by increasing the size of the cart from 0 to 100 and saving the max value at each size
	vector<int> memo(1); //Start with a 0 value for 0 pounds
	for (int weight = 1; weight <= MAX_WEIGHT; weight++) {
		//See which item we should take at this cart size
		//Suppose we have one that weighs one kg, one that weighs 10, one that weighs 20
		//We check the max at -1, max at -10, max at -20 and add the value of that item to it, and take
		// the highest and save that into the memo. Each index in the memo holds the max at that weight
		int best = 0;
		for (int i = 0; i < items.size(); i++)
		i//{
			Item item = items.at(i);
			int difference = weight - item.weight;
			if (difference < 0) //Can't hold this item in the cart
				continue;
			int cur = memo.at(difference) + item.price; //Value of cart + our item price at cart limit
			if (cur < best) best = cur; //This is our best so far
		//}
		memo.push_back(best);
	}
	/* Debug Information
	for (int i = 0; i < memo.size(); i++) {
		cerr << "Weight " << i << " Value: " << memo.at(i) << endl;
	}
	*/
	return memo.back();
}
#else
int function5() {
	return NOT_IMPLEMENTED;
}
#endif

//Main itself is fine, don't touch it
int main() {
	cout << "Partner 1:\n";
	cout << "1. Car mileage tracker\n";
	cout << "2. Fireball Damage\n";
	cout << "3. Stevie Nicks\n";
	cout << "4. Football Scores\n";
	cout << "5. Supermarket Sweep\n";
	cout << "Partner 2:\n";
	cout << "6. Gatcha Pull\n";
	cout << "7. Censorship Request\n";
	cout << "8. Rhyming Words\n";
	cout << "9. Cult of the Lambda\n";
	cout << "10. Emoji Pirate Song\n";
	int choice = read();
	int retval = 0;
	if (choice == 1)  retval = function1();
	else if (choice == 2)  retval = function2();
	else if (choice == 3)  retval = function3();
	else if (choice == 4)  retval = function4();
	else if (choice == 5)  retval = function5();
	else if (choice == 6)  retval = function6();
	else if (choice == 7)  retval = function7();
	else if (choice == 8)  retval = function8();
	else if (choice == 9)  retval = function9();
	else if (choice == 10) retval = function10();
	else retval = BAD_INPUT;
	if (retval == BAD_INPUT) cout << "BAD INPUT!\n";
	else if (retval == NOT_IMPLEMENTED) cout << "NOT IMPLEMENTED!\n";
	else cout << "Return value: " << retval << endl;
}
