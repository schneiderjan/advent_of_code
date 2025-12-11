#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum class Direction {
	Left,
	Right
};

struct Instruction {
	Direction direction;
	int value;
};

int main() {
	std::vector<Instruction> instructions;
	std::string line;
	int dialValue = 50;
	int zeroCount = 0;

	std::cout << "Paste all instructions and press Enter twice:" << std::endl;

	while (std::getline(std::cin, line)) {
		if (line.empty()) {
			break;  // Stop on empty line (double Enter)
		}
		char dirChar = line[0];
		int value = std::stoi(line.substr(1));

		Direction direction = (dirChar == 'L') ? Direction::Left : Direction::Right;
		instructions.push_back({ direction, value });
	}

	for (const auto& instruction : instructions) {
		auto val = instruction.value % 100;
		auto nTurns = instruction.value / 100;

		if (instruction.direction == Direction::Left) {
			int computedValue = dialValue - val;
			if (computedValue == 0) {
				zeroCount++;
				dialValue = 0;
			}
			else if (computedValue < 0) {
				dialValue = 100 + computedValue;
			}
			else {
				dialValue = computedValue;
			}
		}
		else if (instruction.direction == Direction::Right) {
			int computedValue = dialValue + val;
			if (computedValue == 100) {
				zeroCount++;
				dialValue = 0;
			}
			else if (computedValue >= 100) {
				dialValue = computedValue - 100;
			}
			else {
				dialValue = computedValue;
			}
		}

	}

	std::cout << "The password is " << zeroCount << std::endl;

	return 0;
}
