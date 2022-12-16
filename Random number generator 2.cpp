#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <random>

std::ofstream out("RandomNumbers.txt");
std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator


#pragma region RNG
////===============RANDOM NUMBER GENERATOR -start-
/// qty, range_begin, range_end, qty_aftercoma, rangecoma_begin, rangecoma_end

namespace PRINTS
{
	unsigned int random_number_in_range(unsigned int r_begin, unsigned int r_end)
	{
		std::uniform_int_distribution<> distr(r_begin, r_end);
		return distr(gen);
	} 

	void P0(unsigned int qty, unsigned int range_begin, unsigned int range_end)
	{
		for (unsigned int i = 0; i < qty; i++)
		{
			out << random_number_in_range(range_begin, range_end) << std::endl;
		}
	}
	void P1(unsigned int qty, unsigned int range_begin, unsigned int range_end, unsigned int rangecoma_begin, unsigned int rangecoma_end)
	{
		for (unsigned int i = 0; i < qty; i++)
		{
			out << random_number_in_range(range_begin, range_end) << "."<< random_number_in_range(rangecoma_begin, rangecoma_end) << std::endl;
		}
	}
	void P2(unsigned int qty, unsigned int range_begin, unsigned int range_end, unsigned int rangecoma_begin, unsigned int rangecoma_end)
	{
		for (unsigned int i = 0; i < qty; i++)
		{
			unsigned int temp_aftercoma = random_number_in_range(rangecoma_begin, rangecoma_end);
			if (temp_aftercoma < 10)
			{
				out << random_number_in_range(range_begin, range_end) << ".0" << temp_aftercoma << std::endl;
			}
			else out << random_number_in_range(range_begin, range_end) << "." << temp_aftercoma << std::endl;
		}
	}
	void P3(unsigned int qty, unsigned int range_begin, unsigned int range_end, unsigned int rangecoma_begin, unsigned int rangecoma_end)
	{
		for (unsigned int i = 0; i < qty; i++)
		{
			unsigned int temp_aftercoma = random_number_in_range(rangecoma_begin, rangecoma_end);
			if (temp_aftercoma < 10)
			{
				out << random_number_in_range(range_begin, range_end) << ".00" << temp_aftercoma << std::endl;
			}
			else if (temp_aftercoma >= 10 && temp_aftercoma < 100)
			{
				out << random_number_in_range(range_begin, range_end) << ".0" << temp_aftercoma << std::endl;
			}
			else out << random_number_in_range(range_begin, range_end) << "." << temp_aftercoma << std::endl;
		}
	}
	void P4(unsigned int qty, unsigned int range_begin, unsigned int range_end, unsigned int rangecoma_begin, unsigned int rangecoma_end)
	{
		for (unsigned int i = 0; i < qty; i++)
		{
			unsigned int temp_aftercoma = random_number_in_range(rangecoma_begin, rangecoma_end);
			if (temp_aftercoma < 10)
			{
				out << random_number_in_range(range_begin, range_end) << ".000" << temp_aftercoma << std::endl;
			}
			else if (temp_aftercoma >= 10 && temp_aftercoma < 100)
			{
				out << random_number_in_range(range_begin, range_end) << ".00" << temp_aftercoma << std::endl;
			}
			else if (temp_aftercoma >= 100 && temp_aftercoma < 1000)
			{
				out << random_number_in_range(range_begin, range_end) << ".0" << temp_aftercoma << std::endl;
			}
			else out << random_number_in_range(range_begin, range_end) << "." << temp_aftercoma << std::endl;
		}
	}
}
// REAL PROGRAM PART

void IgnoreShittyInput()
{
	std::cin.clear(); // reset failbit
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
}
void eeend() { std::cout << std::endl; }


#pragma endregion RNG

void PrintUSER_INPUT(const unsigned int q, const unsigned int r1, const unsigned int r2, const unsigned int qa, const unsigned int r1qa, const unsigned int r2qa)
{
	std::cout << "qty= " << q << std::endl;
	std::cout << "range_begin= " << r1 << std::endl;
	std::cout << "range_end= " << r2 << std::endl;
	std::cout << "qty_aftercoma= " << qa << std::endl;
	std::cout << "rangecoma_begin= " << r1qa << std::endl;
	std::cout << "rangecoma_end= " << r2qa << std::endl;
}

// shortening couts for output text
void output_pizdesh(unsigned int q, unsigned int rb, unsigned int re, unsigned int qa, unsigned int rcb, unsigned int rce);
void output_pizdesh(unsigned int q, unsigned int rb, unsigned int re);

int main()
{
	std::cout << "Random number generator" << std::endl;

	unsigned int qty, range_begin, range_end, qty_aftercoma, rangecoma_begin, rangecoma_end;

#pragma region USER_INPUT

	std::cout << "How many numbers to generate(maximum 999999) ? : ";
	std::cin >> qty;
	if (qty < 1 || qty > 999999 || !std::cin)
	{
		IgnoreShittyInput();
		std::cout << "Invalid input, number has been set to 100" << std::endl;
		qty = 100;
	} eeend();

	std::cout << "Range from(0-999999) ? : ";
	std::cin >> range_begin;
	if (range_begin < 0 || range_begin > 999999 || !std::cin)
	{
		IgnoreShittyInput();
		std::cout << "Invalid input, number has been set to 0" << std::endl;
		range_begin = 0;
	} eeend();

	std::cout << "Range to(max 999999) ? : ";
	std::cin >> range_end;
	if (range_end < range_begin || range_end > 999999 || !std::cin)
	{
		IgnoreShittyInput();
		std::cout << "Invalid input, number has been set to 100" << std::endl;
		range_end = 999999;
	} eeend();

	std::cout << "How many numbers after coma (0-4) ? : ";
	std::cin >> qty_aftercoma;
	if (qty_aftercoma < 0 || qty_aftercoma > 4 || !std::cin)
	{
		IgnoreShittyInput();
		std::cout << "Invalid input, number has been set to 2" << std::endl;
		qty_aftercoma = 2;
	} eeend();
	switch (qty_aftercoma)
	{
	case 0:
		// execute RANDOMIZER with NO_AFTER_COMA !!
		break;
	case 1:
		std::cout << "Range after coma from(0-9) ? : ";
		std::cin >> rangecoma_begin;
		if (rangecoma_begin < 0 || rangecoma_begin > 9 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 0" << std::endl;
			rangecoma_begin = 0;
		} eeend();

		std::cout << "Range after coma to (max 9) ? : ";
		std::cin >> rangecoma_end;
		if (rangecoma_end < rangecoma_begin || rangecoma_end > 9 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 9" << std::endl;
			rangecoma_end = 9;
		} eeend();

		break;
	case 2:
		std::cout << "Range after coma from(0-99) ? : ";
		std::cin >> rangecoma_begin;
		if (rangecoma_begin < 0 || rangecoma_begin > 99 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 0" << std::endl;
			rangecoma_begin = 0;
		} eeend();

		std::cout << "Range after coma to (max 99) ? : ";
		std::cin >> rangecoma_end;
		if (rangecoma_end < rangecoma_begin || rangecoma_end > 99 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 99" << std::endl;
			rangecoma_end = 99;
		} eeend();
		break;
	case 3:
		std::cout << "Range after coma from(0-999) ? : ";
		std::cin >> rangecoma_begin;
		if (rangecoma_begin < 0 || rangecoma_begin > 999 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 0" << std::endl;
			rangecoma_begin = 0;
		} eeend();

		std::cout << "Range after coma to (max 999) ? : ";
		std::cin >> rangecoma_end;
		if (rangecoma_end < rangecoma_begin || rangecoma_end > 999 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 999" << std::endl;
			rangecoma_end = 999;
		} eeend();
		break;
	case 4:
		std::cout << "Range after coma from(0-9999) ? : ";
		std::cin >> rangecoma_begin;
		if (rangecoma_begin < 0 || rangecoma_begin > 9999 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 0" << std::endl;
			rangecoma_begin = 0;
		} eeend();

		std::cout << "Range after coma to (max 9999) ? : ";
		std::cin >> rangecoma_end;
		if (rangecoma_end < rangecoma_begin || rangecoma_end > 9999 || !std::cin)
		{
			IgnoreShittyInput();
			std::cout << "Invalid input, number has been set to 9999" << std::endl;
			rangecoma_end = 9999;
		} eeend();
		break;
	}

#pragma endregion USER_INPUT_END

	//PrintUSER_INPUT(qty, range_begin, range_end, qty_aftercoma, rangecoma_begin, rangecoma_end);

	switch (qty_aftercoma)
	{
	case 0:
		output_pizdesh(qty, range_begin, range_end);
		PRINTS::P0(qty, range_begin, range_end);
		break;
	case 1:
	{
		output_pizdesh(qty, range_begin, range_end, qty_aftercoma, rangecoma_begin, rangecoma_end);
		PRINTS::P1(qty, range_begin, range_end, rangecoma_begin, rangecoma_end);
		break;
	}
	case 2:
	{
		output_pizdesh(qty, range_begin, range_end, qty_aftercoma, rangecoma_begin, rangecoma_end);
		PRINTS::P2(qty, range_begin, range_end, rangecoma_begin, rangecoma_end);
		break;
	}
	case 3:
	{
		output_pizdesh(qty, range_begin, range_end, qty_aftercoma, rangecoma_begin, rangecoma_end);
		PRINTS::P3(qty, range_begin, range_end, rangecoma_begin, rangecoma_end);
		break;
	}
	case 4:
	{
		output_pizdesh(qty, range_begin, range_end, qty_aftercoma, rangecoma_begin, rangecoma_end);
		PRINTS::P4(qty, range_begin, range_end, rangecoma_begin, rangecoma_end);
		break;
	}
	}
	std::cin.get();
	return 0;
}

void output_pizdesh(unsigned int q, unsigned int rb, unsigned int re)
{
	std::cout << "Random " << q << " numbers generated between " << rb << " and " << re <<
		" and saved to <RandomNumbers.txt> " << std::endl;
}void output_pizdesh(unsigned int q, unsigned int rb, unsigned int re, unsigned int qa, unsigned int rcb, unsigned int rce)
{
	std::cout << "Random " << q << " numbers generated between " << rb << " and " << re << ", " <<
		qa << " digits after coma" << " in range from " << rcb << " to " << rce << " and saved to <RandomNumbers.txt> " << std::endl;
}
