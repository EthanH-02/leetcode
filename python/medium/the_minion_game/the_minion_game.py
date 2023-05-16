VOWELS = ['A', 'E', 'I', 'O', 'U']

def minion_game(string):
    # your code goes here
    vowel = 0
    const = 0
    
    for i in range(1, len(string) + 1):
        i *= -1
        if string[i] in VOWELS:
            vowel += len(string[i:])
        else:
            const += len(string[i:])
    
    if (vowel < const):
        print("Stuart " + str(const))
    elif (vowel > const):
        print("Kevin " + str(vowel))

if __name__ == '__main__':
    s = input()
    minion_game(s)
