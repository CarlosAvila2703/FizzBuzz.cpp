#include <iostream>
#include <string>
#include <sstream>

namespace {
	const char* prompt = R"(
*************** GAMES MENU *******************
*                                            *
* (F) - Fizz-Buzz                            *
*                                            *
* (Q) - Quit program                         *
*                                            *
**********************************************

)";

}

int getInt();

int main()
{
	std::stringstream ss;
	bool isPlaying{ true };
	std::string msg{ "" };
	while (isPlaying) {
		system("cls");
		std::cout << prompt << ss.str() << msg << "\n";
		msg = "";
		ss.str("");

		int i{ 0 };
		char c;
		std::cin >> c;
		switch (std::tolower(c))
		{

		case 'f':
			std::cout << "What should I count to? ";
			i = getInt();
			for (int j{ 1 }; j <= i; ++j) {
				
				if (j % 3 == 0 || j % 5 == 0)
				{
					ss << "Fizz-Buzz";
				}
				else if (j % 3 == 0)
				{
					ss << "Fizz";
				}
				else if (j % 5 == 0)
				{
					ss << "Buzz";
				}
				else
				{
					ss << j;
				}

				ss << "\n";
			}
			break;


		case 'q':
			isPlaying = false;
			break;

		default:
			msg = "Please make a valid choice: ";
			break;
		}
	}
}

int getInt() {
	int i;
	std::cin >> i;
	while (std::cin.fail() || i < 0) {
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "Please enter a valid positive number: ";
		i = getInt();
	}
	return i;
}