##Michael Nweke #Student ID: 16278575
#Import random so that random numbers can be generated throughout program
import random
#While playing is set to true, the program will execute
#A variable(redo) will determine whether the game runs or not
redo='Y'
while redo== 'Y':
    playing = True
    while playing:
        rounds= 5
        correct= 0
#Assign a variable that increases with every problem, so that when it gets to 5 problems, the game stops
        attempt= 0
        while attempt <= 4:
            playing = False
            for rnd in range (1, rounds+1):
                num1=random.randint(1,10)
                num2=random.randint(1,10)
#Make the operation of the function random each time
                if random.random()<0.5 :
                    answer= num1+num2
                    answer_sign=str(num1)+'+'+str(num2)
                else:
                    answer= num1-num2
                    answer_sign= str(num1)+'-'+str(num2)
#Display the problem using the random numbers and signs
            print('What is', answer_sign, '?')
            attempt = attempt + 1
#The user input will be set to answer, if they're correct, they'll be notified, if not, they can guess again
#The user will get 3 guesses, if they're all wrong, they will be told the answer and it'll move to the next problem
            user_answer= int(input('Guess #1:\n'))
            if user_answer == answer:
                print('You are correct')
                correct += 1
            elif user_answer!=answer:
                user_answer= int(input('Guess #2:\n'))
                if user_answer== answer:
                    print('You are correct')
                    correct += 1
                elif user_answer!= answer:
                    user_answer= int(input('Guess #3:\n'))
                    if user_answer== answer:
                        print('You are correct')
                        correct += 1
                    else:
                        print('The answer is', answer, 'not', user_answer)
    
#Once the user is done with the 5 questions, their score will be calculated
    print('You got', correct, 'out of 5')
    print('That is', (correct/rounds)*100, '%')
#Ask the user if they want to play again
#The variable(redo) comes back into play and will decide if the game runs again
    redo=input('Do you want to play again? Y to continue, N to quit ==> ')
    if redo=='N':
        break
