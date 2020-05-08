
def anagram_check(word1,word2):
    if (sorted(word1) == sorted(word2)):
        return 1
    else:
        return 0

word1 = input()
word2 = input()
print(anagram_check(word1,word2))

input()