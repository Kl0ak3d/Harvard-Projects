from cs50 import get_int

def main():
    while True:
        number = get_int("Number: ")
        if number < 0:
            print("The number must be a non-negative integer!")
        else:
            break

    digits, sum_of_odds, sum_of_evens, last, sec_last = count_text_stats(number)
    first_two_digits = last * 10 + sec_last
    total_sum = sum_of_odds + sum_of_evens

    if is_valid(total_sum):
        if digits == 13 or digits == 16 and is_visa(last):
            print("VISA")
        elif digits == 15 and is_amex(first_two_digits):
            print("AMEX")
        elif digits == 16 and is_mastercard(first_two_digits):
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")

def count_text_stats(number):
    digits = 0
    sum_of_odds = 0
    sum_of_evens = 0
    last = sec_last = 0

    while number > 0:
        digits += 1
        sec_last = last
        last = number % 10

        if digits % 2 == 0:
            multiplier = last * 2
            sum_of_evens += multiplier // 10 + multiplier % 10 if multiplier >= 10 else multiplier
        else:
            sum_of_odds += last

        number //= 10

    return digits, sum_of_odds, sum_of_evens, last, sec_last

def is_visa(first_digit):
    return first_digit == 4

def is_amex(first_two_digits):
    return first_two_digits == 34 or first_two_digits == 37

def is_mastercard(first_two_digits):
    return 51 <= first_two_digits <= 55

def is_valid(total_sum):
    return total_sum % 10 == 0

if __name__ == "__main__":
    main()
