#include "Serializer.hpp"

int main()
{
	Data* original = new Data;
	original->id = 42;
	original->name = "$ubZ3r0";
	original->value = 3.14f;

	std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << original << std::endl;
    std::cout << "  ID: " << original->id << std::endl;
    std::cout << "  Name: " << original->name << std::endl;
    std::cout << "  Value: " << original->value << std::endl;
    std::cout << std::endl;

	uintptr_t serialized  = Serializer::serialize(original);
	std::cout << "Serialized (as integer): " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  ID: " << deserialized->id << std::endl;
    std::cout << "  Name: " << deserialized->name << std::endl;
    std::cout << "  Value: " << deserialized->value << std::endl;
    std::cout << std::endl;

	if (deserialized == original)
        std::cout << "✅ Success! Pointers are equal." << std::endl;
	else
		std::cout << "❌ Error! Pointers are different." << std::endl;

	delete original;

	return 0;
}