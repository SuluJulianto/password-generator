package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

// PasswordGenerator struct
type PasswordGenerator struct {
	CharsCount    int
	CapsCount     int
	NumbersCount  int
	SymbolsCount  int
	LowercaseChars string
	UppercaseChars string
	Numbers       string
	Symbols       string
}

// NewPasswordGenerator initializes a new PasswordGenerator
func NewPasswordGenerator(charsCount, capsCount, numbersCount, symbolsCount int) *PasswordGenerator {
	return &PasswordGenerator{
		CharsCount:    max(charsCount, 0),
		CapsCount:     max(capsCount, 0),
		NumbersCount:  max(numbersCount, 0),
		SymbolsCount:  max(symbolsCount, 0),
		LowercaseChars: "abcdefghijklmnopqrstuvwxyz",
		UppercaseChars: "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		Numbers:       "0123456789",
		Symbols:       "!@#$%^&*_=+-/",
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// GeneratePassword generates a password with specified counts of characters, caps, numbers, and symbols
func (pg *PasswordGenerator) GeneratePassword() string {
	return pg.generatePasswordSpecific(pg.CharsCount, pg.CapsCount, pg.NumbersCount, pg.SymbolsCount)
}

// GeneratePasswordWithoutSymbols generates a password without symbols
func (pg *PasswordGenerator) GeneratePasswordWithoutSymbols() string {
	return pg.generatePasswordSpecific(pg.CharsCount, pg.CapsCount, pg.NumbersCount, 0)
}

// GeneratePasswordWithNumbersOnly generates a password with numbers only (exactly 6 digits)
func (pg *PasswordGenerator) GeneratePasswordWithNumbersOnly() string {
	return pg.getRandomString(pg.Numbers, 6)
}

func (pg *PasswordGenerator) generatePasswordSpecific(charsCount, capsCount, numbersCount, symbolsCount int) string {
	password := pg.getRandomString(pg.LowercaseChars, charsCount) +
		pg.getRandomString(pg.UppercaseChars, capsCount) +
		pg.getRandomString(pg.Numbers, numbersCount) +
		pg.getRandomString(pg.Symbols, symbolsCount)

	return pg.shuffle(password)
}

func (pg *PasswordGenerator) getRandomString(charSet string, count int) string {
	chars := strings.Split(charSet, "")
	rand.Seed(time.Now().UnixNano())
	rand.Shuffle(len(chars), func(i, j int) {
		chars[i], chars[j] = chars[j], chars[i]
	})

	return strings.Join(chars[:count], "")
}

func (pg *PasswordGenerator) shuffle(source string) string {
	chars := strings.Split(source, "")
	rand.Seed(time.Now().UnixNano())
	rand.Shuffle(len(chars), func(i, j int) {
		chars[i], chars[j] = chars[j], chars[i]
	})

	return strings.Join(chars, "")
}

func main() {
	rand.Seed(time.Now().UnixNano())

	pwdGenerator := NewPasswordGenerator(4, 2, 2, 1)

	fmt.Println("Password with characters, caps, numbers, and symbols:")
	fmt.Println(pwdGenerator.GeneratePassword())

	fmt.Println("Another password with the same set:")
	fmt.Println(pwdGenerator.GeneratePassword())

	fmt.Println("Password with characters, caps, numbers, without symbols:")
	fmt.Println(pwdGenerator.GeneratePasswordWithoutSymbols())

	fmt.Println("Password with numbers only (exactly 6 digits):")
	fmt.Println(pwdGenerator.GeneratePasswordWithNumbersOnly())
}
