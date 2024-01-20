#include <iostream>
#include <string>
#include <algorithm> // For std::shuffle
#include <ctime>      // For std::time
#include <cstdlib>    // For std::rand

class PasswordGenerator {
private:
    static const std::string LOWERCASE_CHARS;
    static const std::string UPPERCASE_CHARS;
    static const std::string NUMBERS;
    static const std::string SYMBOLS;

    int chars_count;
    int caps_count;
    int numbers_count;
    int symbols_count;

public:
    PasswordGenerator(int chars_count = 4, int caps_count = 1, int numbers_count = 1, int symbols_count = 1);

    std::string generatePassword();
    std::string generatePasswordWithoutSymbols();
    std::string generatePasswordWithNumbersOnly();

private:
    std::string generatePasswordSpecific(int chars_count, int caps_count, int numbers_count, int symbols_count);
    std::string getRandomString(const std::string& char_set, int count);
    std::string shuffle(const std::string& source);
};

// Initialize static const member variables
const std::string PasswordGenerator::LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
const std::string PasswordGenerator::UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string PasswordGenerator::NUMBERS = "0123456789";
const std::string PasswordGenerator::SYMBOLS = "!@#$%^&*_=+-/";

// Constructor
PasswordGenerator::PasswordGenerator(int chars_count, int caps_count, int numbers_count, int symbols_count)
    : chars_count(std::max(chars_count, 0)),
      caps_count(std::max(caps_count, 0)),
      numbers_count(std::max(numbers_count, 0)),
      symbols_count(std::max(symbols_count, 0)) {}

// Public member functions
std::string PasswordGenerator::generatePassword() {
    return generatePasswordSpecific(chars_count, caps_count, numbers_count, symbols_count);
}

std::string PasswordGenerator::generatePasswordWithoutSymbols() {
    return generatePasswordSpecific(chars_count, caps_count, numbers_count, 0);
}

std::string PasswordGenerator::generatePasswordWithNumbersOnly() {
    return getRandomString(NUMBERS, 6);
}

// Private member functions
std::string PasswordGenerator::generatePasswordSpecific(int chars_count, int caps_count, int numbers_count, int symbols_count) {
    std::string password = getRandomString(LOWERCASE_CHARS, chars_count) +
                           getRandomString(UPPERCASE_CHARS, caps_count) +
                           getRandomString(NUMBERS, numbers_count) +
                           getRandomString(SYMBOLS, symbols_count);
    return shuffle(password);
}

std::string PasswordGenerator::getRandomString(const std::string& char_set, int count) {
    std::string characters = char_set;
    std::random_shuffle(characters.begin(), characters.end());
    return characters.substr(0, count);
}

std::string PasswordGenerator::shuffle(const std::string& source) {
    std::string characters = source;
    std::random_shuffle(characters.begin(), characters.end());
    return characters;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    PasswordGenerator pwdGenerator(4, 2, 2, 1);

    std::cout << "Password with characters, caps, numbers, and symbols:" << std::endl;
    std::cout << pwdGenerator.generatePassword() << std::endl;

    std::cout << "Another password with the same set:" << std::endl;
    std::cout << pwdGenerator.generatePassword() << std::endl;

    std::cout << "Password with characters, caps, numbers, without symbols:" << std::endl;
    std::cout << pwdGenerator.generatePasswordWithoutSymbols() << std::endl;

    std::cout << "Password with numbers only (exactly 6 digits):" << std::endl;
    std::cout << pwdGenerator.generatePasswordWithNumbersOnly() << std::endl;

    return 0;
}
