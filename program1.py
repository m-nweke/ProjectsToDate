## Name: Michael Nweke #Section: COMP-SCI 101 0004 #Creation date:9/8/18 #Due date:9/9/18 #Program 1
#Start off by displaying a welcome message to the user
print("Welcome to Carmack's Bakery!")
print()
#Next ask the user how much of each product they want and assign their input to a variable
cookies=int(input('How many dozen cookies?\n'))
print()
cake=int(input('How many cakes?\n'))
print()
donuts=int(input('How many dozen donuts?\n'))
print()
#Determine how many ingredients are needed for each product and assign it to a variable
#Each products yields a certain amount of each ingredient per dozen
#That amount will vary based on the amount the user asks for
butter =(2.5*cookies)+(0.5*cake)+(0.25*donuts)
sugar= (2*cookies)+(1*cake)+(0.5*donuts)
eggs=(2*cookies)+(2*cake)+(3*donuts)
flour=(8*cookies)+(1.5*cake)+(5*donuts)
#Tell the user how much of each ingredient they'll need for the amount they requested
print('You will need to order:')
print(butter, 'cups of butter')
print(sugar, 'cups of sugar')
print(eggs, 'eggs')
print(flour, 'cups of flour')
