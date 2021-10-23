#Michael Nweke #Student ID:16278575 #Week 12
def get_words(userfile):
#This function reads through the file given by the user and adds all the words with a length greater than 3 to a list
#It also accounts for punctuation and new lines
    words=[]
    with open(userfile) as file:    
        for line in file:
            content=line.split(' ')
            for i in content:
                if len(i) > 3:
                    words.append(i)
    lst=[]
    for i in words:
        i=i.replace('\n', '')
        i=i.replace('.','')
        i=i.replace('!','')
        i=i.replace('?','')
        i=i.replace(':','')
        i=i.replace(';','')
        i=i.replace('-','')
        i=i.replace(',','')
        i=i.lower()
        if len(i) >3:
            lst.append(i)
    return lst

def make_dict(words):
#This function takes the list created from the previous function and puts each word into a dictionary with a number
#That number goes up every time that word is found in the dictionary
    count={}
    for i in words:
        count[i]=count.get(i, 0)+1
    return count
def get_total(word_count):
#This function goes through the previously created dictionary and finds the words that have a value of one and increments a variable as the total
    total = 0
    for num in word_count.values():
        if num == 1:
            total += 1
    return total
def get_unique(word_count):
#This function goes through the dictionary and takes each entry and increments a variable that will be the number of unique words
    total=0
    for num in word_count.values():
        total += 1
    return total
def sort_dict(word_count):
#This function sorts the dictionary and creates a tuple with those sorted entries
#The function then slices that tuple to get the top 10 words
    top_10=sorted(word_count.items(), key=lambda x:x[1], reverse=True)
    top_10=top_10[0:10]
    return top_10


def get_output(top_10):
#This function outputs the results
    print('Most frequently used words')
    print("{:<10}{:>10}{:>10}".format("#", "Word", "Freq."))
    print('='*45)
    num=1
    for word, freq in top_10:
        print("{:<10}{:>10}{:>10}".format(num, word , freq))
        num +=1
#A while loop is created that will ask for a file until a valid input is given
#Errors will be accounted for
#The functions will then be conducted in order and output the results
ask=True
while ask:
    try:
        userfile=input('Enter the name of the file to open ')
        print()
        words=get_words(userfile)
        word_count=make_dict(words)
        top_10=sort_dict(word_count)
        get_output(top_10)
        total=get_total(word_count)
        unique=get_unique(word_count)
        print('There are {} words that occur only once'.format(total))
        print('There are {} unique words in the document'.format(unique))
        ask=False
    except:
        print('Could not open file',userfile)
        print('Please try again')
        print()

