from cs50 import get_string

def count_letters(text):
    letters = 0
    for c in text:
        if c.isalpha():
            letters += 1
    return letters

def count_words(text):
    return text.count(" ") + 1

def count_sentences(text):
    sentences = 0
    for c in text:
        if c in ['.', '!', '?']:
            sentences += 1
    return sentences

def main():

    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)


    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

if __name__ == "__main__":
    main()

