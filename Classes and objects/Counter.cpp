#include <iostream>
#include <string>

class Counter
{
private:

	int counter{};

public:
	Counter() : counter{ 1 } {};
	Counter(int setCounter) : counter{ setCounter } {}

	void increment()
	{
		++counter;
	}

	void decrement()
	{
		--counter;
	}

	int getValue()
	{
		return counter;
	}

};

int main()
{
	int value;
	std::string userInput;
	std::cout << "Do you want to specify an initial counter value? Enter \"yes\" or \"no\": ";
	std::cin >> userInput;

	if (userInput == "yes")
	{
		std::cout << "Enter the initial counter value: ";
		std::cin >> value;
	}
	else
	{
		value = 1;
	}
	Counter counter(value);

	while (true)
	{
		char command;
		std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
		std::cin >> command;

		switch (command)
		{
		case '+':
			counter.increment();
			break;

		case '-':
			counter.decrement();
			break;

		case '=':
			std::cout << "Counter value: " << counter.getValue() << std::endl;
			break;

		case 'x':
			std::cout << "Goodbye!" << std::endl;
			return 0;

		default:
			std::cout << "Error!" << std::endl;

		}
	}

	return EXIT_SUCCESS;
}