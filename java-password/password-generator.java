import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class PasswordGenerator {
    private static final String LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz";
    private static final String UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String NUMBERS = "0123456789";
    private static final String SYMBOLS = "!@#$%^&*_=+-/";

    private int charsCount;
    private int capsCount;
    private int numbersCount;
    private int symbolsCount;

    public PasswordGenerator(int charsCount, int capsCount, int numbersCount, int symbolsCount) {
        this.charsCount = Math.max(charsCount, 0);
        this.capsCount = Math.max(capsCount, 0);
        this.numbersCount = Math.max(numbersCount, 0);
        this.symbolsCount = Math.max(symbolsCount, 0);
    }

    public String generatePassword() {
        return generatePasswordSpecific(charsCount, capsCount, numbersCount, symbolsCount);
    }

    public String generatePasswordWithoutSymbols() {
        return generatePasswordSpecific(charsCount, capsCount, numbersCount, 0);
    }

    public String generatePasswordWithNumbersOnly() {
        return getRandomString(NUMBERS, 6);
    }

    private String generatePasswordSpecific(int charsCount, int capsCount, int numbersCount, int symbolsCount) {
        StringBuilder password = new StringBuilder();
        password.append(getRandomString(LOWERCASE_CHARS, charsCount))
                .append(getRandomString(UPPERCASE_CHARS, capsCount))
                .append(getRandomString(NUMBERS, numbersCount))
                .append(getRandomString(SYMBOLS, symbolsCount));

        return shuffle(password.toString());
    }

    private String getRandomString(String charSet, int count) {
        List<Character> characters = new ArrayList<>();
        for (char c : charSet.toCharArray()) {
            characters.add(c);
        }
        Collections.shuffle(characters);

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < count; i++) {
            result.append(characters.get(i));
        }

        return result.toString();
    }

    private String shuffle(String source) {
        List<Character> characters = new ArrayList<>();
        for (char c : source.toCharArray()) {
            characters.add(c);
        }
        Collections.shuffle(characters);

        StringBuilder result = new StringBuilder();
        for (char c : characters) {
            result.append(c);
        }

        return result.toString();
    }

    public static void main(String[] args) {
        PasswordGenerator pwdGenerator = new PasswordGenerator(4, 2, 2, 1);

        System.out.println("Password with characters, caps, numbers, and symbols:");
        System.out.println(pwdGenerator.generatePassword());

        System.out.println("Another password with the same set:");
        System.out.println(pwdGenerator.generatePassword());

        System.out.println("Password with characters, caps, numbers, without symbols:");
        System.out.println(pwdGenerator.generatePasswordWithoutSymbols());

        System.out.println("Password with numbers only (exactly 6 digits):");
        System.out.println(pwdGenerator.generatePasswordWithNumbersOnly());
    }
}
