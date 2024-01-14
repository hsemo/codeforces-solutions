def progress_fib(a, b, k):
    '''
    progress the series with a, b till k and checks if it is valid or not
    if it is valid then returns True else returns False
    '''
    l = 2
    for i in range(2, k):
        b = a - b
        a = a - b
        if b > a:
            break
        l += 1

    if l == k:
        return True
    return False


def handle_test_case():
    n, k = list(map(int, input().split()))
    ans = 0

    for i in range(n//2, n+1):
        if progress_fib(n, i, k):
            ans += 1

    print(ans)


def main():
    t = int(input())
    while t > 0:
        handle_test_case()
        t -= 1

main()
