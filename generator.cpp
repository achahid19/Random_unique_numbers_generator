#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <fstream>

using namespace std;

int main() {
	int	numbersToGenerate;

	std::cout << "How many numbers you want to generate? (approximatively not exact number)";
	std::cout << std::endl;
	cin >> numbersToGenerate; cin.ignore();
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // Use a set to automatically remove duplicates
    std::set<int> uniqueNumbers;

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
            file << ",";  // Separate numbers by commas
        }
    }

	std::cout << "Unique " << uniqueNumbers.size();
	std::cout << " numbers are generated on random_numbers.txt file" << std::endl;

    return 0;
}
