
import sqlite3


def readdb():
    connection = sqlite3.connect(":memory:")
    connection = sqlite3.connect("deniro.db")

    cursor = connection.cursor()

    rows = cursor.execute("select year, title, rating from deniro").fetchall()

    for row in rows:
        print(row)

    cursor.close()
    connection.close()


    return None


if __name__ == '__main__':
    readdb()
