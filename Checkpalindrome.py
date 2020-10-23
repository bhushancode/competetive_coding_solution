t=int(input())
while t>0:
    list_n=input().split(" ")
    list_n.pop(-1)
    list_r=list_n[:]
    list_n.reverse()
    if list_n==list_r:
        print("YES")
    else:
        print("NO")
    t=t-1
