# programming challenge
# Word occurrence
# python 3.7
# binariusO1

import re

word_occ=[]

text_file = open("text.txt","r")
words = ""
data = text_file.read()
result = re.sub("[^0-9a-z-_\s]", "",data, 0, re.IGNORECASE | re.MULTILINE)
words = result.split()
count_words = len(words)
text_file.close()

for w in words:
    word_occ.append(words.count(w))

print("Numbers of word:\n",count_words)

'''
print("List:")
for w in words:
    print(str(w))
print()

print("Occurrences:")
for w in word_occ:
    print(str(w))
print()
'''

print("Word + occurrences:")
for w in (zip(words, word_occ)):
    print(str(w))
print()

a = input("")
