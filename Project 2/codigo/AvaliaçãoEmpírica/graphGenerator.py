import sys
from random import randint as rd
from math import ceil as c

'''
Script que gera um grafo com N nós de acordo com os limites do dataset original
O número de Edges, E, é calculado segundo um FACTOR de multiplicação
Coloca o resultado na pasta ../input, em formato "graph<N>.txt"
'''

ORIGINAL = "../../input/graph50.txt"
MAXIMUM = 100000
MINIMUM = -1
FACTOR = 5

def getBounds() -> list:

    allData = []
    with open(ORIGINAL, 'r') as file:
        
        allData = [     [   int(element) 
                            for element in line.strip().split(" ")  ] 
                            for line in file.readlines()[1:]               ]
        file.close()

    minCapacity, maxCapacity, minTime, maxTime = MAXIMUM, MINIMUM, MAXIMUM, MINIMUM
    
    for edge in allData:
        minCapacity = min(minCapacity, edge[2])
        maxCapacity = max(maxCapacity, edge[2])
        minTime = min(minTime, edge[3])
        maxTime = max(maxTime, edge[3])
        
    return [minCapacity, maxCapacity, minTime, maxTime]

def generate(nodes : int):

    [minCapacity, maxCapacity, minTime, maxTime] = getBounds()
    fileName = "graph{}.txt".format(nodes)
    edges = FACTOR * nodes
    oldEdges = []

    with open("../../input/" + fileName, 'w') as file:
        
        file.write("{} {}\n".format(nodes, edges))

        while (edges):
            origin = rd(1, nodes)
            destiny = rd(1, nodes)
            if (list([origin, destiny]) not in oldEdges):
                oldEdges.append(list([origin, destiny]))
                file.write(" ".join(str(item) for item in [origin, destiny, rd(minCapacity, maxCapacity), rd(minTime, maxTime)]))
                if edges != 1: file.write("\n")
                edges -= 1

        file.close()
        
if __name__ == "__main__":
    generate(int(sys.argv[1]))