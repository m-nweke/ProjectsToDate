##Name: Michael Nweke #Student ID: 16278575 #Week9
#Create global variable for the weighted test and assignment score
test_weight=0.6
assign_weight=0.4
#Create empty lists for the tests scores and assignment scores
test_scores=[]
assign_scores=[]

#Define a function that adds a test grade
def add_test():
    score=float(input('Enter a new Test score 0-100 ==>'))
    test_scores.append(score)
#Define a function that removes a test grade
def remove_test():
    score=float(input('Enter the Test score to remove 0-100 ==>'))
    if score in test_scores:
        test_scores.remove(score)
    else:
        print('Could not find that score to remove')
#Define a function that clears all test grades
def clear_test():
    test_scores.clear()
#Define a function that adds an assignment
def add_assign():
    score=float(input('Enter a new Assignment score 0-100 ==>'))
    assign_scores.append(score)
#Define a function that removes an assignment
def remove_assign():
    score=float(input('Enter the Assignment score to remove 0-100 ==>'))
    if score in assign_scores:
        assign_scores.remove(score)
    else:
        print('Could not find that score to remove')
#Define a function that clears all assignments
def clear_assign():
    assign_scores.clear()
#Define a function that get the average scores
def get_avg(scores):
    try:
        total=sum(scores)
        length=len(scores)
        avg=sum(scores)/len(scores)
    except ZeroDivisionError:
        avg= 0
    return avg
def get_std(scores):
    std=0
    average=get_avg(scores)
    for score in scores:
        std += (average-score)**2
        return (std/len(scores))**0.5
#Define a function that displays the scores
def display_scores():
    print('\n{}{:>15}{:>10}{:>10}{:>10}{:>15}'.format('Type', '#', 'min', 'max', 'avg', 'std'))
    print('======================================================================')
    if test_scores == []:
        weighted_test = 0
        print('{}{:>14}{:>10}{:>10}{:>10}{:>15}'.format('Tests', 'n/a', 'n/a', 'n/a', 'n/a', 'n/a'))
    else:
        amounttest = len(test_scores)
        mintest = min(test_scores)
        maxtest = max(test_scores)
        scoretest = 0
        for i in test_scores:
            scoretest += i
        testaverage = get_avg(test_scores)
        weighted_test = testaverage * test_weight
        try:
            test_std = get_std(test_scores)
        except ZeroDivisionError:
            test_std = 'n/a'
        print('{}{:>14}{:>10}{:>10}{:>10}{:>15}'.format('Tests', amounttest, mintest, maxtest, testaverage, test_std))
    if assign_scores == []:
        weighted_assign = 0
        print('{}{:>14}{:>10}{:>10}{:>10}{:>15}'.format('Assignments', 'n/a', 'n/a', 'n/a', 'n/a', 'n/a'))
    else:
        amountassign = len(assign_scores)
        minassign = min(assign_scores)
        maxassign = max(assign_scores)
        scoreassign = 0
        for i in assign_scores:
            scoreassign += i
        assignaverage = get_avg(assign_scores)
        weighted_assign = assignaverage * assign_weight
        try:
            assign_std = get_std(assign_scores)
        except ZeroDivisionError:
            assign_std = 'n/a'
        print('{}{:>8}{:>10}{:>10}{:>10}{:>15}'.format('Programs', amountassign, minassign, maxassign, assignaverage, assign_std))
    weighted = weighted_test + weighted_assign
    print('\nThe weighted score is %d' %weighted)         

#Set a variable to true that will continue to print the menu and executer command until the user decides to quit
ask=True
while ask:
#The menu will continually ask the user for a choice until they enter 'q' for quit
    choices=['1','2','3','4','5','6','D', 'Q', 'd', 'q']
    menu=input('''
\tGrade Menu
1 - Add Test
2 - Remove Test
3 - Clear Tests
4 - Add Assignment
5 - Remove Assignment
6 - Clear Assignments
D - Display Scores
Q - Quit
==>''')

#Put all the functions together in the menu prompt
    if menu == '1':
        add_test()
    elif menu == '2':
        remove_test()
    elif menu == '3':
        clear_test()
    elif menu == '4':
        add_assign()
    elif menu == '5':
        remove_assign()
    elif menu == '6':
        clear_assign()
    elif menu == 'd':
        assignment_avg=get_avg(assign_scores)
        test_avg=get_avg(test_scores)
        display_scores()
    elif menu == 'D':
        assignment_avg=get_avg(assign_scores)
        test_avg=get_avg(test_scores)
        diplay_scores()
    elif menu == 'q':
        ask=False
    elif menu=='Q':
        ask=False
    elif menu not in choices:
        print('Not a valid choice, choose from the menu')
