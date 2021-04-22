###Michael Nweke #Studenet ID: 16278575 #Week5
#Start by importing whitespace
from string import whitespace 
#Define a function called print_menu
menu= ('Menu\n e - Enter a new string value\n c - Number of non-whitespace characters\n w - Number of words\n s - Shorten spaces\n q - Quit')
def print_menu():
#A loop will be executed that runs until a choice is made. If an invalid choice is made, the user will be prompted to choose again
    men=True
    while men == True:
        print(menu)
        print()
        choice=input('Choose an option: ==>')
        if choice == 'e':
            men=False
            return choice
        elif choice == 'c':
            men=False
            return choice
        elif choice == 'w':
            men=False
            return choice
        elif choice == 's':
            men=False
            return choice
        elif choice == 'q':
            men=False
            return choice
        else:
            print('You must choose one of the valid choices given')

def is_whitespace(string):
#This function will tell if a single character is a whitespace or not
    if string in whitespace:
        return True
    else:
        return False
def get_num_non_ws_chars(value):
#This functions tests each individual character with is 'is_whitespace()' function
#A variable is set to 0 and if the whitepace function returns false, the variable goes up one, indicating a non whitespace character
    num=0
    for ch in value:
        if not is_whitespace(ch):
            num= num + 1
    return num
def get_num_words(value):
#This functon finds the number of words in a string
#It does this by using the whitespace function as well
#A variable is set to 0
#Each character is tested and when a whitespace is found between 2 characters, the variable goes up 1
    words=0
    is_word=False

    for ch in value:
        if is_whitespace(ch):
            if is_word:
                words += 1
            is_word=False
        else:
            is_word=True
    if is_word:
        words += 1
    return words

def shorten_space(string):
#This function removes extra spaces in a string via the strip and replace functions 
    string=string.strip()
    sep=' '
    results= string.split(sep)
    newstr=' '.join(results)
    newstr= newstr.replace('  ', ' ')
    return newstr
#A loop is set to true, and will prompt the user to enter a string
#Once the user string is declared, the menu function will be called and the choice will be assigned to a variable
#That variable will determine which function is called and carried out
#This loop will run and continue to ask the user for their choice until they decide to quit
loop=True
user_string=input('Enter the string to evaluate ==>')
while loop:
    print()
    choice=print_menu()
    if choice == 'e':
        user_string=input('Enter a new string to evaluate\n')
        continue
    elif choice == 'c':
        non=get_num_non_ws_chars(user_string)
        print('The number of non whitespace characters is', non)
        print()
    elif choice == 'w':
        word=get_num_words(user_string)
        print('The number of words is', word)
        print()
    elif choice == 's':
        newst=shorten_space(user_string)
        print('The new string is\n', newst)
        print()
    elif choice == 'q':
        loop = False
    
























