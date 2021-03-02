
import time 

def largefile():
    print("Running a large file")
    time.sleep(2)
    print("Finished!")


if __name__ == '__main__':
    print("Might delete main")
    largefile()
