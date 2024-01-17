class PasswordGenerator {
  static LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
  static UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  static NUMBERS = "0123456789";
  static SYMBOLS = "!@#$%^&*_=+-/";

  constructor(chars_count = 4, caps_count = 1, numbers_count = 1, symbols_count = 1) {
    this.chars_count = Math.max(chars_count, 0);
    this.caps_count = Math.max(caps_count, 0);
    this.numbers_count = Math.max(numbers_count, 0);
    this.symbols_count = Math.max(symbols_count, 0);
  }

  generatePassword() {
    return this.generatePasswordSpecific(
      this.chars_count, this.caps_count, this.numbers_count, this.symbols_count
    );
  }

  generatePasswordSpecific(chars_count, caps_count, numbers_count, symbols_count) {
    const password = (
      this.getRandomString(PasswordGenerator.LOWERCASE_CHARS, chars_count) +
      this.getRandomString(PasswordGenerator.UPPERCASE_CHARS, caps_count) +
      this.getRandomString(PasswordGenerator.NUMBERS, numbers_count) +
      this.getRandomString(PasswordGenerator.SYMBOLS, symbols_count)
    );
    return this.shuffle(password);
  }

  generatePasswordWithoutSymbols() {
    return this.generatePasswordSpecific(this.chars_count, this.caps_count, this.numbers_count, 0);
  }

  generatePasswordWithNumbersOnly() {
    return this.getRandomString(PasswordGenerator.NUMBERS, 6);
  }

  getRandomString(char_set, count) {
    const characters = Array.from(char_set);
    characters.sort(() => Math.random() - 0.5);
    return characters.slice(0, count).join("");
  }

  shuffle(source) {
    const characters = Array.from(source);
    characters.sort(() => Math.random() - 0.5);
    return characters.join("");
  }
}

const pwdGenerator = new PasswordGenerator(4, 2, 2, 1);

console.log("Password with characters, caps, numbers, and symbols:");
console.log(pwdGenerator.generatePassword());

console.log("Another password with the same set:");
console.log(pwdGenerator.generatePassword());

console.log("Password with characters, caps, numbers, without symbols:");
console.log(pwdGenerator.generatePasswordWithoutSymbols());

console.log("Password with numbers only (exactly 6 digits):");
console.log(pwdGenerator.generatePasswordWithNumbersOnly());
