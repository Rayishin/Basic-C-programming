#include <iostream>

class Calculator
{
private:

	double num1;
	double num2;

public:

	Calculator(double setNum1, double setNum2) : num1{ setNum1 }, num2{ setNum2 } {}

	double add()
	{
		return num1 + num2;
	}

	double multiply()
	{
		return num1 * num2;
	}

	double subtract_1_2()
	{
		return num2 - num1;
	}

	double subtract_2_1()
	{
		return num1 - num2;
	}

	double divide_1_2()
	{
		return num1 / num2;
	}

	double divide_2_1()
	{
		return num2 / num1;
	}

	bool set_num1(double num1)
	{
		if (num1 == 0)
		{
			return false;
		}

		this->num1 = num1;
		return true;
	}

	bool set_num2(double num2)
	{
		if (num2 == 0)
		{
			return false;
		}

		this->num2 = num2;
		return true;
	}

};

int main()
{
	double num1, num2;

	while (true)
	{
		std::cout << "Enter num1: ";
		std::cin >> num1;

		std::cout << "Enter num2: ";
		std::cin >> num2;

		if (num1 == 0 || num2 == 0)
		{
			std::cout << "Invalid input! ";
			continue;
		}
		break;
	}

	Calculator calc(num1, num2);

	std::cout << "num1 + num2 = " << calc.add() << std::endl;
	std::cout << "num1 - num2 = " << calc.subtract_2_1() << std::endl;
	std::cout << "num2 - num1 = " << calc.subtract_1_2() << std::endl;
	std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
	std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
	std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;

	return EXIT_SUCCESS;
}
