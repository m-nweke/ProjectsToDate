#Michael Nweke #Student ID:16278575 #Week 10
#Create a function that opens a file and saves it's contents to a dictionary
def open_passwords(file_handle):
    passwords= {}
    for line in file_handle:
        if '\t' in line:
            user, pw= line.split('\t')
            pw= pw.strip()
            passwords[pw]= passwords.get(pw, 0)+1
    return passwords
def get_output(passwords):
    total=0
    for num in passwords.values():
        total += num
    print("{:<15}{:>15}{:>10}".format("Passwords", "Frequency", "%"))
    print('='*45)
    for pw, frequency in passwords.items():
        print("{:<15}{:>15}{:>10.4%}".format(pw, frequency, frequency/total))

        
with open('testdata.txt') as file:
    passwords=open_passwords(file)
    get_output(passwords)

