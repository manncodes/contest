
def solution(tasks):
    maximum_end_time = max(task[1] for task in tasks)
    timeline = [0] * maximum_end_time
    for start, end, _ in tasks:
        for i in range(start, end + 1):
            timeline[i-1] += 1


    timeline = [(i, timeline[i]) for i in range(len(timeline))]
    sorted_timeline = sorted(timeline, key=lambda x: x[1], reverse=True)

    ans = 0
    for idx, _ in sorted_timeline:
        usedby = []
        for tidx, task in enumerate(tasks):
            if task[2] == 0:
                continue
            if task[0] <= idx + 1 <= task[1]:
                usedby.append(tidx)
                task[2] -= 1

        # print(idx + 1, tasks, usedby) # use this to debug
        if usedby:
            ans += 1

    return ans


# test cases
tasks1 = [[1,3,2], [2,5,3], [5,6,2]] # 4
tasks2 = [[1,3,2],[4,6,2],[7,10,2]] # 6
tasks3 = [[1,3,2],[1,4,3],[1,5,3]] # 3
tasks4 = [[1,3,2],[1,4,3],[1,5,4],[5,8,3], [6,10,3]] # 6

if __name__ == "__main__":
    print(solution(tasks1))
    print(solution(tasks2))
    print(solution(tasks3))
    print(solution(tasks4))

