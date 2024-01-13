import random

class PasswordGenerator:
    LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz"
    UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    NUMBERS = "0123456789"
    SYMBOLS = "!@#$%^&*_=+-/"

    def __init__(self, chars_count=4, caps_count=1, numbers_count=1, symbols_count=1):
        self.chars_count = max(chars_count, 0)
        self.caps_count = max(caps_count, 0)
        self.numbers_count = max(numbers_count, 0)
        self.symbols_count = max(symbols_count, 0)

    def generate_password(self):
        return self.generate_password_specific(
            self.chars_count, self.caps_count, self.numbers_count, self.symbols_count
        )

    def generate_password_specific(self, chars_count, caps_count, numbers_count, symbols_count):
        password = (
            self.get_random_string(self.LOWERCASE_CHARS, chars_count)
            + self.get_random_string(self.UPPERCASE_CHARS, caps_count)
            + self.get_random_string(self.NUMBERS, numbers_count)
            + self.get_random_string(self.SYMBOLS, symbols_count)
        )
        return self.shuffle(password)

    def generate_password_without_symbols(self):
        return self.generate_password_specific(self.chars_count, self.caps_count, self.numbers_count, 0)

    def generate_password_with_numbers_only(self):
        return self.get_random_string(self.NUMBERS, 6)

    def get_random_string(self, char_set, count):
        characters = list(char_set)
        random.shuffle(characters)
        return "".join(characters[:count])

    def shuffle(self, source):
        characters = list(source)
        random.shuffle(characters)
        return "".join(characters)

if __name__ == "__main__":
    pwd_generator = PasswordGenerator(chars_count=4, caps_count=2, numbers_count=2, symbols_count=1)

    print("Password with characters, caps, numbers, and symbols:")
    print(pwd_generator.generate_password())

    print("Another password with the same set:")
    print(pwd_generator.generate_password())

    print("Password with characters, caps, numbers, without symbols:")
    print(pwd_generator.generate_password_without_symbols())

    print("Password with numbers only (exactly 6 digits):")
    print(pwd_generator.generate_password_with_numbers_only())
