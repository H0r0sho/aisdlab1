#include "Set.h"
#include <iostream>

int main()
{
	Set set1;
	Set set2;
	int choise = 0;
	do
	{
		int n;
		system("cls");
		std::cout << "1 - +(merge) for 1st set\n";
		std::cout << "2 - +(merge) for 2nd set\n";
		std::cout << "3 -  -(difference) for 1st set\n";
		std::cout << "4 -  -(difference) for 2nd set\n";
		std::cout << "5 - +=(adding a number to a 1st set)\n";
		std::cout << "6 - +=(adding a number to a 2st set)\n";
		std::cout << "7 - -=(removing a number from a 1st set)\n";
		std::cout << "8 - -=(removing a number from a 2nd set)\n";
		std::cout << "9- get element of 1st set by index\n";
		std::cout << "10- get element of 2nd set by index\n";
		std::cout << "11 - calculating the intersection\n";
		std::cout << "12 - checking for the presence of a number in the 1st set\n";
		std::cout << "13 - checking for the presence of a number in the 2dn set\n";
		std::cout << "14 - set1+set2\n";
		std::cout << "15 - set1-set2\n";
		std::cout << "Exit: 16\n";
		fflush(stdin);
		std::cout << "choose task\n";
		std::cin >> choise;
		system("cls");
		switch (choise)
		{
		case(1):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set1 + n;
			std::cout << "set1: " << set1 << "\n" << std::endl;
			break;
		case(2):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set2 + n;
			std::cout << "set2: " << set2 << "\n" << std::endl;
			break;
		case(3):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set1 - n;
			std::cout << "set1: " << set1 << "\n" << std::endl;
			break;
		case(4):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set2 - n;
			std::cout << "set2: " << set2 << "\n" << std::endl;
			break;
		case(5):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set1 += n;
			std::cout << "set1: " << set1 << "\n" << std::endl;
			break;
		case(6):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set2 += n;
			std::cout << "set2: " << set2 << "\n" << std::endl;
			break;
		case(7):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set1 -= n;
			std::cout << "set1: " << set1 << "\n" << std::endl;
			break;
		case(8):
			fflush(stdin);
			std::cout << "enter number: \n";
			std::cin >> n;
			set2 -= n;
			std::cout << "set2: " << set2 << "\n" << std::endl;
			break;
		case(9):
			fflush(stdin);
			std::cout << "enter index: \n";
			std::cin >> n;
			std::cout << "index set1: " << set1[n] << std::endl;
			break;
		case(10):
			fflush(stdin);
			std::cout << "enter index: \n";
			std::cin >> n;
			std::cout << "index set2: " << set2[n] << std::endl;
			break;
		case(11):
			fflush(stdin);
			std::cout << "intersection: " << set1.intersection(set2) << std::endl;
			break;
		case(12):
			fflush(stdin);
			std::cout << "enter number for check: \n";
			std::cin >> n;
			std::cout << "check: " << set1.check_num(n) << std::endl;
			break;
		case(13):
			fflush(stdin);
			std::cout << "enter number for check: \n";
			std::cin >> n;
			std::cout << "check: " << set1.check_num(n) << std::endl;
			break;
		case(14):
			fflush(stdin);
			std::cout << "set1+set2: " << set1 + set2 << "\n" << std::endl;
			break;
		case(15):
			fflush(stdin);
			std::cout << "set1-set2: " << set1 - set2 << "\n" << std::endl;
			break;

		}
		if (choise != 16)
		{
			system("pause");
		}
	}while (choise != 16);
}