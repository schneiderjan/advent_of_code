#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

struct Range {
	long long first; 
	long long last;
};

std::unordered_set<long long> invalidIds = {};

std::vector<std::vector<Range>> readFile() {
	std::ifstream inputFile("day2_input.txt");
	std::string line;
	std::vector<std::vector<Range>> allRanges;

	std::cout << "Day 2 - Advent of Code 2025" << std::endl;

	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open day2_input.txt" << std::endl;
		return allRanges;  // Return empty vector on error
	}

	while (std::getline(inputFile, line)) {
		if (line.empty()) {
			continue;
		}

		std::vector<Range> lineRanges;
		std::stringstream ss(line);
		std::string rangeStr;

		// Split by comma
		while (std::getline(ss, rangeStr, ',')) {
			// Find the dash separator
			size_t dashPos = rangeStr.find('-');
			if (dashPos != std::string::npos) {
				auto firstSubStr = rangeStr.substr(0, dashPos);
				auto secSubStr = rangeStr.substr(dashPos + 1);
				long long first = std::stoll(firstSubStr);
				long long last = std::stoll(secSubStr);
				lineRanges.push_back({ first, last });
			}
		}

		allRanges.push_back(lineRanges);
	}

	inputFile.close();
	return allRanges;
}

int countDigits(long long num) {
	if (num == 0) return 1;
	return static_cast<int>(std::log10(std::abs(num))) + 1;
}

bool notInInvalidIds(long long num) {
	return invalidIds.find(num) == invalidIds.end();
}

bool hasEqualHalves(long long num) {
	int digits = countDigits(num);

	// Skip if odd number of digits
	if (digits % 2 != 0) {
		return false;
	}

	int halfDigits = digits / 2;
	long long divisor = static_cast<long long>(std::pow(10, halfDigits));

	long long leftPart = num / divisor;
	long long rightPart = num % divisor;

	return leftPart == rightPart;
}

bool hasRepeatingPattern(long long num) {
	int digits = countDigits(num);
	
	for (int patLen = 1; patLen <= digits / 2; ++patLen) {
		if (digits % patLen == 0) {
			long long divisor = static_cast<long long>(std::pow(10, patLen));
			
			// Extract each chunk and compare to the first pattern
			long long firstPattern = num % divisor;  // Rightmost chunk
			bool allMatch = true;
			long long temp = num;
			
			while (temp > 0) {
				long long currentPattern = temp % divisor;
				if (currentPattern != firstPattern) {
					allMatch = false;
					break;
				}
				temp /= divisor;
			}
			
			if (allMatch) {
				return true;
			}
		}
	}
	return false;
}

void day2() {
	long long sum = 0;
	std::vector<std::vector<Range>> input = readFile();

	for (const auto& LineRange : input) {
		for (const auto& range : LineRange) {
			for (long long i = range.first; i <= range.last; ++i) {
				//TODO: consider caching results for performance, memoization
				if (notInInvalidIds(i)) {
					if (hasEqualHalves(i) || hasRepeatingPattern(i)) {
						sum += i;
						invalidIds.insert(i);
					}
				}
			}
		}
		std::cout << std::endl;
	}

	std::cout << "Result: " << sum << std::endl;
}