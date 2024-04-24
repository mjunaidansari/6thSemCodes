def aStarAlgo(graph, startNode, stopNode):
	openSet = set(startNode)
	closedSet = set()
	g = {} # to store distance from starting node
	parents = {} # contains an adjacency map of all nodes

	g[startNode] = 0
	parents[startNode] = startNode

	while len(openSet) > 0: 
		n = None
		# select node with smallest f(n)
		for v in openSet: 
			if n == None or g[v] + h(n) < g[n] + h(n):
				n = v

		# pass if n is stopNode or n does not have any child nodes
		if n == stopNode or graph[n] == None: 
			pass
		else: 
			for (m, weight) in graph[n]: 
				# if node m is not in openSet and closedSet, add it to openSet
				if m not in openSet and m not in closedSet: 
					openSet.add(m)
					g[m] = g[n] + weight
					parents[m] = n
				else: 
					if g[m] > g[n] + weight: 
						g[m] = g[n] + weight
						parents[m] = n
						if m in closedSet: 
							closedSet.remove(m)
							openSet.add(m)

		if n == None: 
			break

		# if n is stopNode then reconstruct the path
		if n == stopNode: 
			path = []
			while parents[n] != n: 
				path.append(n)
				n = parents[n]
			path.append(startNode)
			path.reverse()
			print('Path: ', path)
			print('Cost: ', g[stopNode])
			return path, g[stopNode]
		
		# remove n from openSet and add to closedSet as all neighbours are inspected
		openSet.remove(n)
		closedSet.add(n)
	print('Path does not exists ')
	return None

def h(n): 
	heuristic = {'A': 11, 'B': 6, 'C': 99, 'D': 1, 'E': 7, 'G': 0}
	return heuristic[n]
						
graph = {
	'A': [('B', 2), ('E', 3)],
	'B': [('C', 1), ('G', 9)],
	'C': None,
	'E': [('D', 6)],
	'D': [('G', 1)],
	'G': None
}

aStarAlgo(graph, 'A', 'G')