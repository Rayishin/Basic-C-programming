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
	Address(std::string City, std::string Street, int houseNumber, int apartmentNumber) :
		City(City), Street(Street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {
	}

	std::string get_output_address()
	{
		return City + ", " + Street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
	}

	std::string getCity()
	{
		return City;
	}
};

void sort(Address** addresses, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (addresses[i]->getCity() > addresses[j]->getCity())
			{
				Address* temp = addresses[i];
				addresses[i] = addresses[j];
				addresses[j] = temp;
			}
		}
	}
}

int main()
{
	std::ifstream addressFile;
	addressFile.open("in.txt");
	if (!addressFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		return EXIT_FAILURE;
	}

	int N;
	addressFile >> N;

	Address** addresses = new Address * [N];

	for (int i = 0; i < N; i++)
	{
		std::string City, Street;
		int House, Apartment;

		std::getline(addressFile >> std::ws, City);
		std::getline(addressFile >> std::ws, Street);
		addressFile >> House >> Apartment;

		addresses[i] = new Address(City, Street, House, Apartment);
	}
	addressFile.close();

	sort(addresses, N);

	std::ofstream outFile;
	outFile.open("out.txt");
	if (!outFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		return EXIT_FAILURE;
	}

	outFile << N << std::endl;
	for (int i = 0; i < N; i++)
	{
		outFile << addresses[i]->get_output_address() << std::endl;
	}
	outFile.close();

	for (int i = 0; i < N; i++)
	{
		delete addresses[i];
	}
	delete[] addresses;

	return EXIT_SUCCESS;
}