# Password Generator

This repository provides a secure and versatile password generator implemented in multiple programming languages. Below is an in-depth explanation of each version, categorized by password types:

## Java

### Overview
The Java implementation utilizes the `PasswordGenerator` class, offering both default and parameterized constructors for flexibility. Passwords can be generated with symbols, without symbols, or with only numbers. The password generation involves characters, uppercase letters, digits, and symbols, with shuffling for enhanced randomness. Secure randomness is ensured through the `SecureRandom` class.

### Constructors
- **Default Constructor:** Sets default counts for characters, uppercase letters, digits, and symbols.
- **Parameterized Constructor:** Enables users to specify counts during object creation.

### Methods
- **generatePassword():** Generates a password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.
- **generatePasswordWithoutSymbols():** Creates a password without symbols.
- **generatePasswordWithNumbersOnly():** Generates a password with exactly 6 digits.

### Demonstration
The `main` method demonstrates the generator's functionality in various scenarios.

## Python

### Overview
The Python version mirrors the Java implementation in an object-oriented design. The `PasswordGenerator` class supports both default and parameterized constructors, emphasizing an easy-to-use structure.

### Methods
- **generate_password():** Generates a password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.
- **generate_password_without_symbols():** Creates a password without symbols.
- **generate_password_with_numbers_only():** Generates a password with exactly 6 digits.

### Demonstration
Examples of usage are provided in the `__main__` block.

## JavaScript

### Overview
The JavaScript implementation follows an object-oriented design using the `PasswordGenerator` class. It utilizes the `Math.random()` function for randomness.

### Methods
- **generatePassword():** Generates a password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.
- **generatePasswordWithoutSymbols():** Creates a password without symbols.
- **generatePasswordWithNumbersOnly():** Generates a password with exactly 6 digits.

### Demonstration
Examples of usage are included in the main code block.

## Ruby

### Overview
The Ruby version adopts an object-oriented structure with the `PasswordGenerator` class, providing customizable counts for password generation.

### Methods
- **generate_password():** Generates a secure password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.
- **generate_password_without_symbols():** Creates a password without symbols.

### Demonstration
Usage examples highlight the simplicity and flexibility of the Ruby code.

## PHP

### Overview
The PHP implementation maintains an object-oriented design inspired by Java. The `PasswordGenerator` class allows users to set counts for different password components.

### Methods
- **generatePassword():** Generates a password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.
- **generatePasswordWithoutSymbols():** Creates a password without symbols.

### Demonstration
Usage examples showcase the generation of passwords in different scenarios.

## C

### Overview
The C version uses imperative programming with the `PasswordGenerator` struct. It follows a procedural style for password generation.

### Functions
- **createPasswordGenerator():** Creates a `PasswordGenerator` struct with specified counts.
- **generatePassword():** Generates a password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.

### Demonstration
Usage examples demonstrate the straightforward approach to password generation.

## C++

### Overview
The C++ version adopts an object-oriented approach with the `PasswordGenerator` class. It uses the `<random>` header for secure randomness.

### Methods
- **generatePassword():** Generates a password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.

### Demonstration
Examples in the main code block illustrate the simplicity and effectiveness of the C++ implementation.

## Golang

### Overview
The Golang version embraces functional programming with the `PasswordGenerator` struct. It uses the `math/rand` package for randomness.

### Functions
- **NewPasswordGenerator():** Creates a `PasswordGenerator` struct with specified counts.
- **GeneratePassword():** Generates a password with symbols, characters, uppercase letters, digits, and shuffled for enhanced security.

### Demonstration
Examples in the main code block showcase the functional programming style in Golang.

Feel free to copy and paste these detailed explanations into your README.md file for a comprehensive overview of the password generator in various programming languages, categorized by password types.
