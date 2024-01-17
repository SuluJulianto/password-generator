class PasswordGenerator
  LOWERCASE_CHARS = "abcdefghijklmnopqrstuvwxyz"
  UPPERCASE_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  NUMBERS = "0123456789"
  SYMBOLS = "!@#$%^&*_=+-/"

  def initialize(chars_count = 4, caps_count = 1, numbers_count = 1, symbols_count = 1)
    @chars_count = [chars_count, 0].max
    @caps_count = [caps_count, 0].max
    @numbers_count = [numbers_count, 0].max
    @symbols_count = [symbols_count, 0].max
  end

  def generate_password
    generate_password_specific(@chars_count, @caps_count, @numbers_count, @symbols_count)
  end

  def generate_password_specific(chars_count, caps_count, numbers_count, symbols_count)
    password = "#{get_random_string(LOWERCASE_CHARS, chars_count)}" \
               "#{get_random_string(UPPERCASE_CHARS, caps_count)}" \
               "#{get_random_string(NUMBERS, numbers_count)}" \
               "#{get_random_string(SYMBOLS, symbols_count)}"
    shuffle(password)
  end

  def generate_password_without_symbols
    generate_password_specific(@chars_count, @caps_count, @numbers_count, 0)
  end

  def generate_password_with_numbers_only
    get_random_string(NUMBERS, 6)
  end

  def get_random_string(char_set, count)
    characters = char_set.chars.shuffle
    characters[0, count].join
  end

  def shuffle(source)
    source.chars.shuffle.join
  end
end

pwd_generator = PasswordGenerator.new(4, 2, 2, 1)

puts "Password with characters, caps, numbers, and symbols:"
puts pwd_generator.generate_password

puts "Another password with the same set:"
puts pwd_generator.generate_password

puts "Password with characters, caps, numbers, without symbols:"
puts pwd_generator.generate_password_without_symbols

puts "Password with numbers only (exactly 6 digits):"
puts pwd_generator.generate_password_with_numbers_only
