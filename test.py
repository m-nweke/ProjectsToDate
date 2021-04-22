#Name: Michael Nweke #Section: COMP-SCI 101-0004 #Creation Date: 9/17/18 #Due Date: 9/23/18
#Display a welcome message to the user
print('WELCOME TO GREEDY DICE')
print()
#import random so that random numbers can be generated later in the program
import random
user=False
ai=False
total=0
#Create a function that turns the random numbers into either 'H' for heads or 'T' for tails
def coin_convert(flip1,flip2,flip3):
    if flip1 ==1:
        c1='H'
    if flip2 ==1:
        c2='H'
    if flip3 ==1:
        c3='H'
    if flip1 ==0:
        c1='T'
    if flip2 ==0:
        c2='T'
    if flip3 ==0:
        c3='T'
    return c1+c2+c3
#Create the variables for the scores and the pot
user_score=0
ai_score=0
pot=0
redo='N'
#Display the score before the user's turn begins
print('SCORE  You :', user_score,'        AI :',ai_score)
print()
#Prompt the user to start the game by pressing enter
#A blank space is the equivalent to pressing enter so once the user presses enter, the game will begin
game=input('Your turn. Hit enter to continue.')
if game=='':
    user=True
while user:
#The game should run as long as the user's score is less than 20 or the decide to hold
    while user_score<20:
#3 random numbers are generated and then added together and assigned to a variable
        set1=random.randint(0,1)
        set2=random.randint(0,1)
        set3=random.randint(0,1)
        i=set1+set2+set3
        #If the only zeros are generated, this results in a 'bust' which will also end the loop
        if i==0:
            pot=0
            print('Bust')
            print()
            print('SCORE  You :', user_score,'        AI :',ai_score)
            game2=input("It's the computers turn. Hit enter to continue.")
        else:
            pot=pot+i
            total=pot
            user_score=total
            cont=input('(F)lip again or (H)old?')
#The random numbers are then turned into 'H' or 'T' using the earlier defined function and displayed to the user
            print('COINS :',coin_convert(set1,set2,set3),'Pot:',pot)
            user =False
            if user_score >=20:
                user=False
                print('Congratulations, you won')
                print('SCORE:  You', user_score, 'AI ',ai_score)
                redo=input('Do you want to play Greedy Coin again? (YES/Y/NO/N)')
                redo=redo.upper()
            if 'Y' in redo:
                user_score=0
                ai_score=0
                pot=0
                total=0
                total1=0
                i=0 
                ii=0
                print('SCORE  You :', user_score,'        AI :',ai_score)
                game2=input("It's the computers turn. Hit enter to continue.")
                ai=True
            elif 'N' in redo:
                pass
                    
#After each turn, the loop will be set to false, ending it
#If the user wants to flip again, they should press 'f' and the loop will run again
            
            if cont== 'f':
                user=True
            elif cont=='h':
                user==False
                print()
                print('SCORE  You :', user_score,'        AI :',ai_score)
                game2=input("It's the computers turn. Hit enter to continue.")
                ai=True
#Once the loop is over, the user will be notified that it is the computers turn and prompted to press enter to continue
#There will be another loop as well as another set of variables similar to those in the user game loop for the computer's turn
total1=0
pot1=0
ii=0
if game2=='':
    ai=True
while ai:
   while ai_score<=8:
       aset1=random.randint(0,1)
       aset2=random.randint(0,1)
       aset3=random.randint(0,1)
       ii=aset1+aset2+aset3
       pot1=pot1+ii
       total1=pot
       ai_score=total1
       print('COINS :',coin_convert(aset1,aset2,aset3),'Pot:',pot1)


