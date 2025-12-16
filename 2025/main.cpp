#include <iostream>

void day1();
void day2();

int main() {
	int day;
	std::cout << "Advent of Code 2025" << std::endl;
	std::cout << "Enter day number (1-25): ";
	//std::cin >> day;
	//std::cin.ignore(); // Clear newline from buffer
	day = 2;

	switch (day) {
	case 1:
		day1();
		break;
	case 2:
		day2();
		break;
	// Add more cases as you complete more days
	default:
		std::cout << "Day " << day << " not implemented yet!" << std::endl;
		break;
	}

	return 0;
}