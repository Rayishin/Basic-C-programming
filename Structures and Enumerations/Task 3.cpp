#include <iostream>
#include <string>

struct addressStorage
{
    std::string City{};
    std::string Street{};
    int houseNumber{};
    int apartmentNumber{};
    int index{};
};

void structureInstance(addressStorage& addressStorage);
void printAddress(const addressStorage& addressStorage);

int main()
{
    addressStorage addressStorageOne{ "Moscow", "Arbat", 12, 8, 123456 };
    addressStorage addressStorageTwo{};

    printAddress(addressStorageOne);

    structureInstance(addressStorageTwo);


    return EXIT_SUCCESS;
}

void printAddress(const addressStorage& addressStorage)
{
    std::cout << "City: " << addressStorage.City << "\n" << "Street: " << addressStorage.Street << "\n"
        << "House number: " << addressStorage.houseNumber << "\n" << "Apartment number: " << addressStorage.apartmentNumber << "\n"
        << "Index: " << addressStorage.index << "\n"
        << std::endl;
}

void structureInstance(addressStorage& addressStorage)
{
    std::cout << "City: ";
    std::cin >> addressStorage.City;

    std::cout << "Street: ";
    std::cin >> addressStorage.Street;

    std::cout << "House number: ";
    std::cin >> addressStorage.houseNumber;

    std::cout << "Apartment number: ";
    std::cin >> addressStorage.apartmentNumber;

    std::cout << "Index: ";
    std::cin >> addressStorage.index;

}