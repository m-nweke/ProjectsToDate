######################
#Michael Nweke       #
#Student ID: 16278575#
#Lab13               #
######################
#Import time as it will be used later in the program
import time
#Define a class that takes numbers and dissplays them in a 'time format'
class Clock(object):
    def __init__(self, hour, minute, second, clock_type = 0):
        self.hour = hour
        self.minute = minute
        self.second = second
        self.clock_type=clock_type
    def __str__(self):
        if self.clock_type == 0:
            return ('{:02}:{:02}:{:02}'.format(self.hour, self.minute, self.second))
        else:
            if self.hour<12:
                ampm= 'am'
            else:
                ampm='pm'
            hour=self.hour
            if hour < 1:
                hour=12
                
            return ('{:02}:{:02}:{:02} {}'.format(self.hour, self.minute, self.second, ampm))
    def tick(self):
        self.second += 1
        if self.second >60:
            self.second = 0
            self.minute += 1
        elif self.minute > 59:
            self.minute = 0
            self.hour += 1


hour=int(input('What is the current hour? ==>'))
minute=int(input('What is the current minute? ==>'))
second=int(input('What is the current second? ==>'))
clock=Clock(hour,minute,second, 1)
while True:
    print(clock)
    clock.tick()
    time.sleep(0.1)
