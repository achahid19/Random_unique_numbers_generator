#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <fstream>

using namespace std;

int main( void ) {
	int				numbersToGenerate;
	std::string		separator;
	std::set<int>	uniqueNumbers;

	std::cout << "How many numbers you want to generate? (approximatively not exact number)";
	std::cout << std::endl;
	cin >> numbersToGenerate; cin.ignore();

	std::cout << "Type the separator you want to use?" << std::endl;
	std::getline(cin, separator, '\n');

	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < numbersToGenerate + (numbersToGenerate / 2); ++i) {
		// Random number between 1 and numbersToGenerate * 2;
		uniqueNumbers.insert(rand() % (numbersToGenerate * 2) + 1);
	}

	std::ofstream	file("random_numbers.txt");
	if (!file) {
		std::cerr << "Error: cannot create output file!" << std::endl;
		return EXIT_FAILURE;
	}

	auto it = uniqueNumbers.begin();

	while (it != uniqueNumbers.end()) {
		file << *it;
		++it;
		if (it != uniqueNumbers.end()) {
			file << separator;
		}
	}

	std::cout << "Unique " << uniqueNumbers.size();
	std::cout << " numbers are generated on random_numbers.txt file" << std::endl;

	return 0;
}
