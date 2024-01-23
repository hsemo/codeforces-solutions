def handle_test_case():
    n = int(input())
    a = list(map(int, input().split()))

    m = [1, 2, 4, 8, 16] # 1 <= 2^m <= n <= 20 ( 0 <= m <= 4)
    m = [i - 1 for i in m] # index starts from 0

    for i in range(n-1):
        if a[i] > a[i+1] and i not in m:
            print("NO")
            return

    print("YES")


def main():
    t = int(input())
    while t > 0:
        handle_test_case()
        t -= 1


main()
