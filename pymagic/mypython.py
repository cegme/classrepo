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
    # match = re.search(r"password", mystring)

    # pattern = r"\d+" # Matched 1234
    #pattern = r"\d+\w+\d+"
    #pattern = r"\d+[a-zA-Z]+\d+"
    #program = re.compile(pattern)

    #pattern = r"([pP]\w*w\w*) is (\d+[a-zA-Z]+\d+)"
    pattern = r"(?P<user_term>[pP]\w*w\w*) is (?P<user_password>\d+[a-zA-Z]+\d+)"
    match = re.search(pattern, mystring)

    if match:
        # print("Matched!", match.group(1), match.group(2))
        print("Matched!", match.group(1,2))
        print("Matched!", match.group("user_term", "user_password"))
    else:
        # Match is None
        print("No match")


# Dunder = double underscore
if __name__ == '__main__':
    print("Main function")
    magic()
    # mightdelete.largefile()
    dore("Okay cool. My password is 12abc34 don't tell anyone.")
