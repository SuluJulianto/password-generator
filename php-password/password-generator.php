<?php

class PasswordGenerator {
    private const LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
    private const UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private const NUMBERS = "0123456789";
    private const SYMBOLS = "!@#$%^&*_=+-/";

    private $chars_count;
    private $caps_count;
    private $numbers_count;
    private $symbols_count;

    public function __construct($chars_count = 4, $caps_count = 1, $numbers_count = 1, $symbols_count = 1) {
        $this->chars_count = max($chars_count, 0);
        $this->caps_count = max($caps_count, 0);
        $this->numbers_count = max($numbers_count, 0);
        $this->symbols_count = max($symbols_count, 0);
    }

    public function generatePassword() {
        return $this->generatePasswordSpecific(
            $this->chars_count, $this->caps_count, $this->numbers_count, $this->symbols_count
        );
    }

    public function generatePasswordSpecific($chars_count, $caps_count, $numbers_count, $symbols_count) {
        $password = (
            $this->getRandomString(self::LOWERCASE_CHARS, $chars_count) .
            $this->getRandomString(self::UPPERCASE_CHARS, $caps_count) .
            $this->getRandomString(self::NUMBERS, $numbers_count) .
            $this->getRandomString(self::SYMBOLS, $symbols_count)
        );
        return $this->shuffle($password);
    }

    public function generatePasswordWithoutSymbols() {
        return $this->generatePasswordSpecific($this->chars_count, $this->caps_count, $this->numbers_count, 0);
    }

    public function generatePasswordWithNumbersOnly() {
        return $this->getRandomString(self::NUMBERS, 6);
    }

    private function getRandomString($char_set, $count) {
        $characters = str_split($char_set);
        shuffle($characters);
        return implode(array_slice($characters, 0, $count));
    }

    private function shuffle($source) {
        $characters = str_split($source);
        shuffle($characters);
        return implode($characters);
    }
}

if (isset($argv[0]) && basename($argv[0]) == basename(__FILE__)) {
    $pwdGenerator = new PasswordGenerator(4, 2, 2, 1);

    echo "Password with characters, caps, numbers, and symbols:\n";
    echo $pwdGenerator->generatePassword() . "\n";

    echo "Another password with the same set:\n";
    echo $pwdGenerator->generatePassword() . "\n";

    echo "Password with characters, caps, numbers, without symbols:\n";
    echo $pwdGenerator->generatePasswordWithoutSymbols() . "\n";

    echo "Password with numbers only (exactly 6 digits):\n";
    echo $pwdGenerator->generatePasswordWithNumbersOnly() . "\n";
}
?>
