###Michael Nweke #Studenet ID: 16278575 #Week8
#Create a function that opens a file given by the user
def open_file():
#The function will continually ask the user for a file until a valid file is given
    while True:
        userfile=input('Enter the name of the input vehicle file ==>')
#The error 'FileNotFound' will be accounted for and if this occurs, the user will be prompted to input another input file 
        try:
            with open(userfile, 'r') as file:
#The file will be read and its contents assigned to a variable
                text=file.read()
                break
        except FileNotFoundError:
            print('Could not open file', userfile)
        except IOError:
            print('There was an IOError', userfile)
    return userfile
#The user will be asked for the mpg until they give a valid input
#A valid input is greater than 0 but less than 100
#They will be told what is wrong with their input
def get_mpg():
    ask=True
    while ask:
        try:
            mpg=int(input('Enter the minimum mpg ==>'))
            if mpg <= 0:
                print('Fuel economy must be greater than 0')
            elif mpg > 100:
                print('Fuel economy must be less than 100')
            else:
#When given a valid input, it will assign that to a variable and the loop will end
                ask=False
        except ValueError:
            print('You must enter a number for the fuel economy')
#The valid input will be returned
    mpg=float(mpg)
    return mpg
#Call the mpg function and return the valid mpg to a varible
mpg=get_mpg()
print()
#Call the get_file() function and assign the valid file to a variable
userfile=open_file()
#Ask the user what they want their output file to be called and prepare to write to that file
output_file= open(input('Enter the name of the file to output to ==>'), 'w')
#Open the userfile and read it line by line
with open(userfile, 'r') as file:
    text=file.readlines()
    for line in text:
        token=line.split('\t')
        try:
            num=float(token[7])
            if num >= mpg:
                output='{:<5}{:<20}{:<40}{:>10f}'.format(token[0],token[1],token[2],num)
                print(output, file=output_file)
        except ValueError:
            print('Could not convert value {} for {} {} {}'.format(token[7], token[2], token[1], token[0]))
output_file.close()
