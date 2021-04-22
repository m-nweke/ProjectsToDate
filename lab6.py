##Name: Michael Nweke #Student ID: 16278575 #Week6
import random
print('Try to guess the code word')
letters='ABCDEFGHIJ'
def code_creater():
    letters='ABCDEFGHIJ'
    code=''
    for num in range(5):
        character=random.choice(letters)
        code= code+character
        letters=letters.replace(character,'')
    return code
code=code_creater()
print(code)

def get_guess(letters):
    while True:
        guess=input('Enter your guess 5 characters ==>').upper()
        no = 0
        if len(guess) != 5:
            print('Error. Too many characters. Only 5.')
            continue
        elif guess.isalpha() == False:
            print('Error. Characters only')
        for ch in guess:
            if ch not in letters:
                no += 1
        if no != 0:
            print('Invalid characters. Use characters', letters)
        return guess
def ch_correct(guess):
    correct=0
    results =0
    for ch in guess:
        if ch in code:
            correct+=1
        else:
            continue
        for i,value in enumerate(guess):
            if guess[i]==ch:
                results+=1
                print(results)
    return (correct, results)
guess=get_guess(letters)
correct, right=ch_correct(guess)
print('You got',correct, 'correct')
print(right, 'in the right space')
def play_again():
    while True:
        redo=input('Do you want to play again (Y/N) ==>').upper()
        if redo =='Y':
            return True
        if redo =='N':
            return False


