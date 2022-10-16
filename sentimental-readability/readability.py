# TODO
# Prompt user for text
text = input("Enter text: ")
# Initialize letters and sentences
letters = 0
sentences = 0
# Divide text into a list of words
words = len(text.split())
# iterate through text, keeping track of words and sentences
for i in text:
    if i.isalpha():
        letters += 1
    elif i == "." or i == "!" or i == "?":
        sentences += 1
# calculate necessary variables of coleman's index
L = float((letters/words) * 100)
S = float((sentences/words) * 100)
# calculate index
raw_index = (0.0588 * L) - (0.296 * S) - 15.8
index = round(raw_index, 0)
# print relevant output
if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {int(index)}")