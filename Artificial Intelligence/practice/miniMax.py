def miniMax(terminals): 
	nodes = terminals
	operation = True 
	print('Terminals: ', nodes)
	while(len(nodes) != 1): 
		newNodes = []
		for i in range(0, len(nodes), 2): 
			if operation: 
				newNodes.append(max(nodes[i], nodes[i+1]))
			else:
				newNodes.append(min(nodes[i], nodes[i+1]))
		if operation: 
			print('Maximization: ', newNodes)
		else: 
			print('Minimization: ', newNodes)
		nodes = newNodes
		operation = not operation

def isPowerOf2(n): 
	return n > 0 and ( n & n - 1) == 0

ip = input("Enter the Terminal Values: ")
terminals = [int(value) for value in ip.split()]

if not isPowerOf2(len(terminals)): 
	exit(1)

miniMax(terminals)