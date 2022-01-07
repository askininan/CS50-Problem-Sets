from cs50 import get_string

symbols = {'!', '.', '?'}                     # Define symbol table
alpha = sentence = word = 0
text = get_string("Text:")                      # Prompt user for input
textLength = len(text)

for i in text:
    if i.isalpha():                             # Check if char is alpabetic
        alpha = alpha + 1
    if i.isspace() and text.index(i)+1 != " ":  # Find word
        word = word + 1
    if i in symbols:                            # Find symbols which helps to count the senteces
        sentence = sentence + 1

print("Alpha: ", alpha, "Word: ", word + 1, "Sentences: ", sentence)

L = (alpha / (word + 1)) * 100.0                                    # Average number of letters per 100 words
S = (sentence / (word + 1)) * 100.0                                 # Average number of senteces per 100 words
index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade ", index)
