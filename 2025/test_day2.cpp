#include <iostream>
#include <cassert>
#include "day2.h"

void testHasRepeatingPattern() {
	std::cout << "Running tests for hasRepeatingPattern()..." << std::endl;

	// Test 1: Single digit repeated
	assert(hasRepeatingPattern(11) == true);
	assert(hasRepeatingPattern(111) == true);
	assert(hasRepeatingPattern(1111) == true);
	assert(hasRepeatingPattern(11111) == true);
	assert(hasRepeatingPattern(111111) == true);
	std::cout << "Single digit repetition tests passed" << std::endl;

	// Test 2: Two-digit pattern repeated
	assert(hasRepeatingPattern(1212) == true);
	assert(hasRepeatingPattern(121212) == true);
	assert(hasRepeatingPattern(12121212) == true);
	assert(hasRepeatingPattern(1212121212) == true);
	std::cout << "Two-digit pattern repetition tests passed" << std::endl;

	// Test 3: Three-digit pattern repeated
	assert(hasRepeatingPattern(123123) == true);
	assert(hasRepeatingPattern(123123123) == true);
	assert(hasRepeatingPattern(123123123123) == true);
	std::cout << "Three-digit pattern repetition tests passed" << std::endl;

	// Test 4: Other patterns
	assert(hasRepeatingPattern(252525) == true);
	assert(hasRepeatingPattern(789789789) == true);
	assert(hasRepeatingPattern(45454545) == true);
	assert(hasRepeatingPattern(789789789789) == true);
	std::cout << "Various pattern repetition tests passed" << std::endl;

	// Test 5: Non-repeating patterns
	assert(hasRepeatingPattern(123) == false);
	assert(hasRepeatingPattern(1234) == false);
	assert(hasRepeatingPattern(12345) == false);
	assert(hasRepeatingPattern(123456) == false);
	assert(hasRepeatingPattern(1213) == false);
	assert(hasRepeatingPattern(121314) == false);
	std::cout << "Non-repeating pattern tests passed" << std::endl;

	// Test 6: Edge cases
	assert(hasRepeatingPattern(0) == false);  // Single digit, no pattern
	assert(hasRepeatingPattern(1) == false);  // Single digit, no pattern
	assert(hasRepeatingPattern(10) == false); // Two different digits
	assert(hasRepeatingPattern(100) == false); // Not evenly divisible pattern
	assert(hasRepeatingPattern(1001) == false); // Not a repeating pattern
	assert(hasRepeatingPattern(0101) == false); // Leading zero case
	std::cout << "Edge case tests passed" << std::endl;

	// Test 7: Large numbers
	assert(hasRepeatingPattern(12341234) == true);
	assert(hasRepeatingPattern(123456123456) == true);
	assert(hasRepeatingPattern(99999999) == true);
	assert(hasRepeatingPattern(123412341234) == true);
	std::cout << "Large number tests passed" << std::endl;

	// Test 8: Mixed - should return false
	assert(hasRepeatingPattern(1234567890) == false);
	assert(hasRepeatingPattern(12121213) == false);
	assert(hasRepeatingPattern(123124) == false);
	std::cout << "Mixed pattern tests passed" << std::endl;

	// Test 9: Same digits but not repeating pattern
	assert(hasRepeatingPattern(1221) == false); // Palindrome, not pattern
	assert(hasRepeatingPattern(123321) == false);
	std::cout << "Palindrome (non-pattern) tests passed" << std::endl;

	// Test 10: All same digits (should pass as single-digit pattern)
	assert(hasRepeatingPattern(2222) == true);
	assert(hasRepeatingPattern(55555) == true);
	assert(hasRepeatingPattern(9999999999) == true);
	std::cout << "All same digit tests passed" << std::endl;

	std::cout << "\nAll tests passed successfully!" << std::endl;
}
