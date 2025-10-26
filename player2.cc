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

#define STAGE6 false
#define STAGE7 false
#define STAGE8 false
#define STAGE9 false
#define STAGE10 false

enum RETVAL { NOT_IMPLEMENTED = -100, BAD_INPUT = -200 };

#if STAGE6 == true
int function6() {
	int seed = read("Input Random Seed:\n");
	srand(seed);
	int base_chance = read("Input Base Chance:\n");
	int increase_chance = read("Input Chance Goes Up Per Miss:\n");

	if (base_chance < 1 || base_chance > 100 || increase_chance < 1 || increase_chance > 100)
		return BAD_INPUT;

	int pulls = 0;
	int chance = base_chance;

	while (true) {
		int roll = rand() % 100;
		if (roll < chance)
			return pulls + 1;
		chance += increase_chance;
		if (chance > 100) chance = 100;
		pulls++;
	}
}
#else
int function6() {
	return NOT_IMPLEMENTED;
}
#endif

int main() {
	int result = function6();
	cout << "Result: " << result << endl;
	return 0;
}
