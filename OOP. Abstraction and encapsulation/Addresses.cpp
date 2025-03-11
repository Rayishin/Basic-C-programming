#include <iostream>
#include <string>
#include <fstream>

class Address
{
private:
	std::string City;
	std::string Street;
	int houseNumber{};
	int apartmentNumber{};

public:
	Address(std::string City, std::string Street, int houseNumber, int apartmentNumber)
	{
		this->City = City;
		this->Street = Street;
		this->houseNumber = houseNumber;
		this->apartmentNumber = apartmentNumber;
	}

	std::string get_output_address()
	{
		return City + ", " + Street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
	}
};

int main()
{
	std::ifstream address;
	address.open("in.txt");
	if (!address.is_open())
	{
		std::cout << "Error!" << std::endl;
		return EXIT_FAILURE;
	}

	int N;
	address >> N;

	Address** addresses = new Address * [N];

	for (int i = 0; i < N; i++)
	{
		std::string City, Street;
		int House, Apartment;

		std::getline(address >> std::ws, City);
		std::getline(address >> std::ws, Street);
		address >> House >> Apartment;

		addresses[i] = new Address(City, Street, House, Apartment);
	}
	address.close();

	std::ofstream out;
	out.open("out.txt");
	if (!out.is_open())
	{
		std::cout << "Error!" << std::endl;
		return EXIT_FAILURE;
	}

	out << N << std::endl;
	for (int i = N - 1; i >= 0; i--)
	{
		out << addresses[i]->get_output_address() << std::endl;
	}
	out.close();

	for (int i = 0; i < N; i++)
	{
		delete addresses[i];
	}
	delete[] addresses;

	return EXIT_SUCCESS;
}