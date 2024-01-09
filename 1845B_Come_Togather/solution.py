def handleTestcase():
    xa, ya= list(map(int, input().split()))
    xb, yb= list(map(int, input().split()))
    xc, yc= list(map(int, input().split()))

    dbx = xb - xa
    dby = yb - ya
    dcx = xc - xa
    dcy = yc - ya

    ds = 1 # by default they are walking along for 1 cell

    if dbx * dcx > 0 :
        ds += min(abs(dbx), abs(dcx))

    if dby * dcy > 0 :
        ds += min(abs(dby), abs(dcy))

    print(ds)


t = int(input())
for i in range(t):
    handleTestcase()
