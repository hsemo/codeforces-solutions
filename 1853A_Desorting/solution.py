def handle_test_case():
    n = int(input())
    a = list(map(int, input().split()))

    df = 999999999 # difference between numbers by substracting i'th from i'th+1
    d = 999999998 # distance between digits by substracting 1 from df
    ans = 0 # minimum number of operations for making the array non-sorted
    i = 0 # the chosen index

    for j in range(n - 1):
        tdf = a[j + 1] - a[j]
        if tdf < 0:
            print(0)
            return
        if tdf < df:
            df = tdf
            i = j

    d = df - 1 # -1 because the distance = how many digits are in between the two numbers
    ans = 1 # +1 for an extra step to make the numbers cross the distance between them
    if d % 2 == 0:
        ans += (d // 2)
    else:
        ans += ((d + 1) // 2) # extra +1 for matching numbers like (1,1), (2,2), (3,3)...
    print(ans)


def main():
    t = int(input())

    while t > 0:
        handle_test_case()
        t -= 1


main()
