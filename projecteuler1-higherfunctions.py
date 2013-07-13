#!/usr/bin/python
def sumupto(n):
    return reduce( lambda x,y: x+y, filter(lambda n: (n%3==0 or n%5==0), range(1000)))

if __name__ == '__main__':
    print sumupto(1000)
