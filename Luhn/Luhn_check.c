/**
*  Implementation of Luhn check algorithm 
*/

#include <string.h>

#include "luhn_check.h"

/**
*  Luhn check algorithm:
*       1. Reverse the order of the digits in the number.
*       2. Take the first, third, ... and every other odd digit in the reversed digits and
*          sum them to form the partial sum s1
*       3. Taking the second, fourth ... and every other even digit in the reversed digits:
*          - Multiply each digit by two and sum the digits if the answer is greater than nine
*            to form partial sums for the even digits
*          - Sum the partial sums of the even digits to form s2
*       4. If s1 + s2 ends in zero then the original number is in the form of a valid credit card number as verified by the Luhn test.
*
*   This implementation was taken unchanged from Rosetta code project: http://rosettacode.org/wiki/Luhn_test_of_credit_card_numbers#C
*   Unchanged implementation allows to use it as an idependedent test for inversed algorithm
*/
int luhn_check(const char* cc)
{
	const int m[] = { 0,2,4,6,8,1,3,5,7,9 };				/* mapping for rule 3 */
	size_t i;
	int odd = 1, sum = 0;

	for (i = strlen(cc); i--; odd = !odd)
	{
		int digit = cc[i] - '0';
		sum += odd ? digit : m[digit];
	}

	return sum % 10 == 0;
}
