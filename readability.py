from cs50 import get_string

def is_word_end(c): return c == " "
def is_sentence_end(c): return c in ".!?"
def is_letter(c): return c.isalpha()

def coleman_liau_index(letter_count, word_count, sentence_count):
    l = 100 * letter_count / word_count
    s = 100 * sentence_count / word_count
    return round(0.0588 * l - 0.296 * s - 15.8)

def count_text_stats(text):
    letter_count = sum(1 for c in text if is_letter(c))
    word_count = sum(1 for c in text if is_word_end(c)) + 1
    sentence_count = sum(1 for c in text if is_sentence_end(c))
    return letter_count, word_count, sentence_count

text = get_string("Text: ")
letter_count, word_count, sentence_count = count_text_stats(text)

index = coleman_liau_index(letter_count, word_count, sentence_count)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print("Grade", index)
