# programming challenge
# Eulerian path (drawing version)
# python 3.7
# v1.0
# using script from https://www.geeksforgeeks.org/eulerian-path-and-circuit/
# binariusO1

from turtle import *    #for drawing

import math
from collections import defaultdict      # +find duplicates

# drawing section
def draw_graph(n1,x,y):
    r = 20.0
    pen(shown=False,fillcolor='white', pencolor='blue', pensize=2)
    penup()
    setpos( float(x),float(y-r) )
    pendown()
    begin_fill()
    circle(r)
    end_fill()

    penup()
    setpos(float(x),float(y-10.0))
    pendown()
    write(n1, align='center', font=("Arial", 15, "bold"))
    return 0

def draw_path(x1,y1,x2,y2,color):
    pen(shown=False, pencolor=color, pensize=2)
    penup()
    setpos( float(x1),float(y1) )
    pendown()
    setpos( float(x2),float(y2) )
    return 0

def draw_path_r(x1,y1,x2,y2,color):
    pen(shown=False, pencolor=color, pensize=2)
    penup()
    setpos( float(x1),float(y1) )
    pendown()
    # setpos( float(x2),float(y2) )
    if x2 > x1:
        right(90)
    elif x2 < x1:
        left(90)
    elif y2 > y1:
        right(0)
    elif y2 < y1:
        right(180)
    circle(  (math.sqrt( pow ((abs(x1-x2)) ,2) + pow((abs(y1-y2)),2 ) ))/2,180 )
    setheading(0)
    # right(270)
    return 0

def write_text(text,color):
    pen(shown=False, pencolor=color, pensize=2)
    penup()
    setpos( float(0.0),float(-400.0) )
    pendown()
    write(text, align='center', font=("Arial", 15, "bold"))
    return 0

# This class represents a undirected graph using adjacency list representation
class Graph:

    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

        # A function used by isConnected

    def DFSUtil(self, v, visited):
        # Mark the current node as visited
        visited[v] = True

        # Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[i] == False:
                self.DFSUtil(i, visited)

    '''Method to check if all non-zero degree vertices are 
    connected. It mainly does DFS traversal starting from  
    node with non-zero degree'''

    def isConnected(self):

        # Mark all the vertices as not visited
        visited = [False] * (self.V)

        #  Find a vertex with non-zero degree
        for i in range(self.V):
            if len(self.graph[i]) > 1:
                break

        # If there are no edges in the graph, return true
        if i == self.V - 1:
            return True

        # Start DFS traversal from a vertex with non-zero degree
        self.DFSUtil(i, visited)

        # Check if all non-zero degree vertices are visited
        for i in range(self.V):
            if visited[i] == False and len(self.graph[i]) > 0:
                return False

        return True

    '''The function returns one of the following values 
       0 --> If grpah is not Eulerian 
       1 --> If graph has an Euler path (Semi-Eulerian) 
       2 --> If graph has an Euler Circuit (Eulerian)  '''

    def isEulerian(self):
        # Check if all non-zero degree vertices are connected
        if self.isConnected() == False:
            return 0
        else:
            # Count vertices with odd degree
            odd = 0
            for i in range(self.V):
                if len(self.graph[i]) % 2 != 0:
                    odd += 1
            if odd == 0:
                return 2
            elif odd == 2:
                return 1
            elif odd > 2:
                return 0

        # Function to run test cases

    def test(self):
        res = self.isEulerian()
        if res == 0:
            txt = ("graph is not Eulerian")
            write_text(txt,'red')
            print(txt)
            return 0
        elif res == 1:
            txt = ("graph has a Euler path")
            write_text(txt,'green')
            print(txt)
            return 1
        else:
            txt = ("graph has a Euler cycle")
            write_text(txt,'green')
            print(txt)
            return 1

vertex=[]
paths=[]
paths2=[]
double=[]
# occurrence=[]
arr=[]
ct=0
# input numbers

t = int(input())
while True:
    a,c,d = input().split()
    # occurrence.append(0)
    vertex.append([int(a),float(c),float(d)])
    t -= 1
    if t == 0:
        break

t = int(input())
g1 = Graph(t)
while True:
    a,b = input().split()
    g1.addEdge(int(a), int(b))

    k =  float(math.sqrt( pow(int(a),2) + pow(int(b),2 ) ))
    if k in double:
        paths2.append( [float(vertex[int(a)][1]) , float(vertex[int(a)][2]) , float(vertex[int(b)][1]) , float(vertex[int(b)][2])] )
    double.append(k)
    
    # occurrence[int(a)]+=1
    # occurrence[int(b)] += 1
    paths.append( [float(vertex[int(a)][1]) , float(vertex[int(a)][2]) , float(vertex[int(b)][1]) , float(vertex[int(b)][2])] )
    t-=1
    if t == 0:
        break
# g1.test()

for i in range(len(paths)):
    draw_path( paths[i][0] , paths[i][1], paths[i][2] , paths[i][3]  , 'blue')

for i in range(len(paths2)):
    draw_path_r(paths2[0][0], paths2[0][1], paths2[0][2], paths2[0][3], 'blue')
    
for i in range(len(vertex)):
    draw_graph( vertex[i][0] , float(vertex[i][1]) , float(vertex[i][2]))


if g1.test()==1:
    for i in range(len(paths)):
        draw_path(paths[i][0], paths[i][1], paths[i][2], paths[i][3], 'green')
    for i in range(len(paths2)):
        draw_path_r(paths2[0][0], paths2[0][1], paths2[0][2], paths2[0][3], 'green')



print(paths2)
# print(occurrence)
# print(min(occurrence))
print("end")

done()
