def int_input():
    nums = []
    num = ''
    for c in input():
        if c == ' ':
            nums.append(int(num))
            num = ''
        num += c

    nums.append(int(num))
    return nums


def handle_test_case():
    n, q = int_input()
    a = int_input()
    x = int_input()

    s = []
    for i in x:
        if i not in s:
            s.append(i)

    for j in range(n):
        for i in range(len(s)):
            if a[j] % (1 << s[i]) == 0: # 1 << x = 2^x
                a[j] += 1 << (s[i] - 1)

    for j in range(n - 1):
        print(a[j], end = ' ')
    print(a[-1])


def main():
    t = int(input())
    while t > 0:
        handle_test_case()
        t -= 1


def make_input():
    a = ['536870912' for i in range(100000)]
    x = ['536870913' for i in range(100000)]

    f = open('input2.txt', 'w')
    f.write('1')
    f.write('\n')
    f.write('100000 100000')
    f.write('\n')
    f.write(' '.join(a))
    f.write('\n')
    f.write(' '.join(x))
    f.close()


main()
