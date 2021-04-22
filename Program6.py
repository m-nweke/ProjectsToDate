######################
#Michael Nweke       #
#Student ID: 16278575#
#Program6#           # 
######################
#Import the random module to use later in the program
import random
#Create a function that converts the contents of the file into a dictionary
def get_dictionary(given):
    definitions={}
    num=0
    with open(given, 'r') as file:
        contents=file.readlines()
        for line in contents:
            num += 1
            num=chr(num)
            eng, span=line.split(':')
            eng=eng.strip()
            span=span.strip()
            definitions[eng+num]=span
            num=ord(num)
    for i in definitions.keys():
        if ',' in definitions[i]:
            token=definitions[i].split(',')
            definitions[i]=token[0] + ' ' + token[1]
    return definitions
#Create a function that ask the user for the number of questoins they want
#It will contiinue to ask until a number between 0 and 10 is given
def get_num():
    ask=True
    while ask:
        try:
            num=int(input('How many words in your quiz? ==>'))
            if (num > 10) or (num < 0):
                print('Number must be greater than zero but less that ten')
            else:
                return num
        except ValueError:
            print('You must enter an integer')
#Create a function that uses the number of desired questions and get gets a random entry and quizes with that entry
def get_quiz(num, dictionary, dict1):
    i=1
    correct=0
    while i <= num:
        q=random.randint(1,10)
        q=chr(q)
        for key in dict1.keys():
            for k in dictionary.keys():
                if q in k:
                    if k == key:
                        key=key.replace(q, '')
                        answer=input('#{}. Enter a valid spanish phrase for {}\n==>'.format(i, key))
#If the user is correct, their score will go up one
#If not, they will be notified of the correct answer
                        if answer== dictionary[k]:
                            print('Correct. Good work')
                            correct +=1
                        else:
                            print('Incorrect, valid choice(s) were {}'.format(dictionary[k]))
        i += 1
#The user score will be calculated and displayed
        result=(correct/num)*100
        result=round(result, 2)
    print('You got {} out of {}, which is {}%'.format(correct, num, result))
#Import os as it will be used later in the program
import os
def get_files():
#Use the os module to get the contents of the directory
    contents = os.listdir()
    files=[]
    for i in contents:
        if '.txt' in i:
#Add those contents that are text files to a list
            files.append(i)
        else:
            break
    return files
#A list if valid choice is created
valid_choice=['1','2','q','Q']
files=get_files()
ask=True
i=len(files)
while ask:
#If there are no text files in the directory, the program will end
    if len(files) <1:
        ask=False
#If there is only one text file the user will be given the option to use that file or quit
    elif len(files) == 1:
        choice=input('''
Vocabulary Program
Choose a file with the proper number or press Q to quit
    1. {}

Q. Quit Program

==>'''.format(files[0])).lower()
        if choice not in valid_choice:
            print('You must choose from one of the valid options 1,Q')
        elif choice == '1':
            dict1=get_dictionary(files[0])
            dictionary=get_dictionary(files[0])
            num=get_num()
            get_quiz(num, dict1, dictionary)
        elif choice == 'q':
            ask=False
    
#If there are 2 files, the text files from the directory will be added as choices 1 and 2
    elif len(files) == 2:
        choice=input('''
Vocabulary Program
Choose a file with the proper number or press Q to quit
    1. {}
    2. {}

Q. Quit Program

==>'''.format(files[0], files[1])).lower()
        if choice not in valid_choice:
            print('You must choose from one of the valid options 1,2,Q')
        elif choice == '1':
            dict1=get_dictionary(files[0])
            dictionary=get_dictionary(files[0])
            num=get_num()
            get_quiz(num, dict1, dictionary) 
        elif choice == '2':
            dict2=get_dictionary(files[1])
            num=get_num()
            get_quiz(num, dict2)
        elif choice == 'q':
            ask=False
