#include <iostream>
#define NDEBUG
#include <cassert>

void decToOtherBase(int num, int base);
//Converts a nonnegative integer to a base representation specified by parameter base

char intToChar(int remainder) noexcept;
//Maps an integer to the correct character 

int main(int argc, char *argv[])
{
	auto done{false};
	while (!done)
	{
		try
		{
			int num, base;

			std::cout << "Enter integer greater or equal to 0: ";
			std::cin >> num;

			std::cout << "Enter integer base between 2 and 36: ";
			std::cin >> base;

			if (num < 0)
				throw "Decimal number must be an integer greater or equal to zero.\n";
			if (2 > base || base > 36)
				throw "Base must be an integer between 2 and 36.\n";

			std::cout << "base " << base << " system representation: ";
			decToOtherBase(num, base);
			std::cout << "\n";
			done = true;
		}
		catch (const char *p)
		{
			std::cout << p << "\n";
		} //try - catch
	}	  //while
} //end main

void decToOtherBase(int num, int base)
{
	assert(2 <= base && base <= 36);
	assert(num >= 0);

	if (num > 0)
	{
		decToOtherBase(num / base, base);
		std::cout << intToChar(num % base);
	}
} //end decToOtherBase

char intToChar(int remainder) noexcept
{
	constexpr int baseTen = 10;
	if (remainder < baseTen)
		return static_cast<char>('0' + remainder);
	else
	{
		auto diff = remainder - baseTen;
		return static_cast<char>('A' + diff);
	}
} //end intToChar