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

    st = set()

    i = n - 1
    i -= 1 # the last element is of length 1 so no point in looping over it
    st.add(s[-1])
    while i >= 0:
        m = s[i:]
        i -= 1
        while len(m) >= 1:
            if m in st:
                break # if item is allready present in the set then break the loop
            st.add(m)
            m = remove_second_char(m)

    print(len(st))


def main():
    t = int(input())

    while t > 0:
        handle_test_case()
        t -= 1


main()
