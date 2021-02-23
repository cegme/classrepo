import re
import mightdelete


def magic():
    print("Do some magic")

    if (True):
        a = 5 * 3

# PEP 8
class MyPythonClass(object):
    def __init__(x,y):
        self.x = x
        self.y = y
        self._z = x * y # Private



def dore(mystring = "My password"):
    match = re.search(r"password", mystring)


# Dunder = double underscore
if __name__ == '__main__':
    print("Main function")
    magic()
    # mightdelete.largefile()
    dore("Okay cool. My password is 1234 don't tell anyone.")
