# input
# 3
# 4
# 4 1
# 4 5
# 1 1
# 2 3
# 3
# 2 4
# 2 6
# 2 3
# 1
# 2 65

def solve():
    ans = 0
    n_boxes = int(input())
    sizes = [list(map(int, input().split())) for _ in range(n_boxes)]
    sizes.sort(key=lambda x: (x[0], x[1]))
    ans += sizes[-1][1]
    for i in range(n_boxes):
        ans += sizes[i][0]

    print(ans * 2)




if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        solve()