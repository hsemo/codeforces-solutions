def remove_second_char(s):
    '''removes the second character from the string'''
    if len(s) == 1:
        return ''
    if len(s) == 2:
        return s[0]

    return s[0] + s[2:]


def handle_test_case():
    n = int(input()) # length of string
    s = input() # the string

    ps = set() # possible string characters for string of length n
    ans = 0
    for i in s:
        ps.add(i)
        ans += len(ps)

    print(ans)


def main():
    t = int(input())

    while t > 0:
        handle_test_case()
        t -= 1


main()
