import sys

visited = []
vertices = []
edges = []
h = []
cost = 0
goal = 0

n = int(input("Enter The number of vertices : "))

# Input vertices
for i in range(n):
    vertices.append(str(input("Enter vertex : ")))

# Input edge costs
for i in range(n):
    print(vertices[i], ": Enter the cost of the connected edge in the order of vertices above")
    print("If edge exists: Enter cost, If no edge: Enter 0")
    x = list(map(int, input().split()))
    edges.append(x)

print(edges)

# Print vertices
for i in range(n):
    print(i + 1, ":", vertices[i])

goal = int(input("Enter Goal State : ")) - 1

# Input heuristic values
for i in range(n):
    print("Enter Heuristic value for:", vertices[i])
    h.append(int(input()))

visited.append(vertices[0])

def astar(i):
    global goal
    global cost

    min_val = sys.maxsize
    min_index = 0

    for j in range(len(i)):
        if i[j] != 0 and vertices[j] not in visited:
            x = i[j] + h[j]  # f(n) = g(n) + h(n)


        # updating the cost where x is calculated cost &
        # min_val is current min cost 
            
            if x < min_val:
                min_val = x
                min_index = j

    visited.append(vertices[min_index])
    cost += i[min_index]

    if min_index != goal:
        astar(edges[min_index])
    else:
        print("Goal found.")

astar(edges[0])
print(visited)
print(cost)


# Number of vertices: 4
# Vertices: A, B, C, D

# Edge costs:
# A: 0 2 0 1
# B: 2 0 3 0
# C: 0 3 0 1
# D: 1 0 1 0

#goal : 4

# Heuristic values:
# A: 5
# B: 4
# C: 3
# D: 2

# Goal State: D

