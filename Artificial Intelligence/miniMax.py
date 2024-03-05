# MiniMax Algorithm

import math 

def printNodes(nodes, c): 
	# print(nodes, c)
	for i in range(c*2): 
		print("\t", end="")
	for node in nodes: 
		print(node, "\t", end="")
	print()

def miniMax(terminals): 
	nodes = terminals
	operation = True # true for max, false for min
	c = 0
	while len(nodes) != 1:
		printNodes(nodes, c)
		c += 1
		newNodes = []
		for i in range(0, len(nodes), 2): 
			if operation: 
				newNodes.append(max(nodes[i], nodes[i+1]))
			else: 
				newNodes.append(min(nodes[i], nodes[i+1]))
		nodes = newNodes
		operation = not operation
	printNodes(nodes, c)
	
def isPowerOf2(n): 
	return n > 0 and (n & n - 1 ) == 0

ip = input("Enter the Terminal Values: ")
terminals = [int(value) for value in ip.split()]

if not isPowerOf2(len(terminals)): 
	print("Number of Terminals must be in power of 2.")
	exit(1)

miniMax(terminals)

# -1 4 2 6 -3 -5 0 7