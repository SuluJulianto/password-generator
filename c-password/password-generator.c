#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Include the time header

#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SYMBOLS "!@#$%^&*_=+-/"

typedef struct {
    int chars_count;
    int caps_count;
    int numbers_count;
    int symbols_count;
} PasswordGenerator;

void initializeGenerator(PasswordGenerator *generator, int chars_count, int caps_count, int numbers_count, int symbols_count) {
    generator->chars_count = chars_count > 0 ? chars_count : 0;
    generator->caps_count = caps_count > 0 ? caps_count : 0;
    generator->numbers_count = numbers_count > 0 ? numbers_count : 0;
    generator->symbols_count = symbols_count > 0 ? symbols_count : 0;
}

void generatePasswordSpecific(PasswordGenerator *generator, char *password) {
    sprintf(password, "%.*s%.*s%.*s%.*s",
            generator->chars_count, LOWERCASE_CHARS,
            generator->caps_count, UPPERCASE_CHARS,
            generator->numbers_count, NUMBERS,
            generator->symbols_count, SYMBOLS);
    // Shuffle the password
    for (int i = strlen(password) - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

void generatePassword(PasswordGenerator *generator, char *password) {
    generatePasswordSpecific(generator, password);
}

void generatePasswordWithoutSymbols(PasswordGenerator *generator, char *password) {
    generator->symbols_count = 0;
    generatePasswordSpecific(generator, password);
}

void generatePasswordWithNumbersOnly(PasswordGenerator *generator, char *password) {
    generator->chars_count = 0;
    generator->caps_count = 0;
    generator->symbols_count = 0;
    generator->numbers_count = 6; // Set numbers_count to 6 for exactly 6 digits
    generatePasswordSpecific(generator, password);
}

int main() {
    srand((unsigned int)time(NULL));

    PasswordGenerator pwdGenerator;
    initializeGenerator(&pwdGenerator, 4, 2, 2, 1);

    char generatedPassword[20];  // Adjust the size based on your needs

    printf("Password with characters, caps, numbers, and symbols:\n");
    generatePassword(&pwdGenerator, generatedPassword);
    printf("%s\n", generatedPassword);

    printf("Another password with the same set:\n");
    generatePassword(&pwdGenerator, generatedPassword);
    printf("%s\n", generatedPassword);

    printf("Password with characters, caps, numbers, without symbols:\n");
    generatePasswordWithoutSymbols(&pwdGenerator, generatedPassword);
    printf("%s\n", generatedPassword);

    printf("Password with numbers only (exactly 6 digits):\n");
    generatePasswordWithNumbersOnly(&pwdGenerator, generatedPassword);
    printf("%s\n", generatedPassword);

    return 0;
}
