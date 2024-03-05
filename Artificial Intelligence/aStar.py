def aStarAlgo(graph, startNode, stopNode): 
	openSet = set(startNode)
	closedSet = set()
	g = {} # to store distance from starting node
	parents = {} # contains an adjaceny map of all nodes

	# distance of starting node from itself is zero
	g[startNode] = 0
	# start node has no parent node
	parents[startNode] = startNode

	while len(openSet) > 0: 
		n = None
		# select node with f(n)
		for v in openSet: 
			if n == None or g[v] + h(v) < g[n] + h(n):
				n = v
		
		if n == stopNode or graph[n] == None:
			pass
		else: 
			for (m, weight) in graph[n]: 
				# if node m is not in openSet and closedSet, add it to first
				if m not in openSet and m not in closedSet: 
					openSet.add(m)
					parents[m] = n
					g[m] = g[n] + weight
				else: 
					if g[m] > g[n] + weight: 
						g[m] = g[n] + weight
						parents[m] = n
						if m in closedSet: 
							closedSet.remove(m)
							openSet.add(m)
		if n == None:
			break
		
		# if n is stop node then reconstruct the path
		if n == stopNode: 
			path = []
			while parents[n] != n:
				path.append(n)
				n = parents[n]
			path.append(startNode)
			path.reverse()
			print('Path found: ', path, 'with Cost: ', g[stopNode])
			return path, g[stopNode]
		
		# remove n from openset and add to closedset as all neighbours are inspected
		openSet.remove(n)
		closedSet.add(n)
	print('Path does not exists!')
	return None

# for now we will consider heuristic values static
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