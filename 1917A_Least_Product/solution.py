def handleTestCase():
    n = int(input())
    res = 1
    for a in input().split():
        a = int(a)
        if a < 0:
            res *= -1
        elif a > 0:
            res *= 1
        else:
            res = 0
            break

    if res > 0:
        print("1\n1 0")
        return

    print(0)


def main():
    t = int(input())

    while t:
        handleTestCase()
        t -= 1


main()
