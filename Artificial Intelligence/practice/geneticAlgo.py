import random

def initialize(): 
	chromosomes = [''] * 4
	for i in range(4): 
		for j in range(8): 
			chromosomes[i] += str(random.randint(0, 9))
	return chromosomes

def calcFitness(chromosomes): 
	fitness = [0] * 4
	for i, c in enumerate(chromosomes): 
		fitness[i] = (int(c[0]) + int(c[1])) - (int(c[2]) + int(c[3])) + (int(c[4]) + int(c[5])) - (int(c[6]) + int(c[7]))
	return fitness

def selection(fitness): 
	sortedIndices = sorted(range(len(fitness)), key=lambda i: fitness[i])
	print(sortedIndices)
	return sortedIndices[-2:]

def crossover(c1, c2): 
	chromosomes = [''] * 4
    # One-point crossover
	chromosomes[0] = c1[0:4] + c2[4:8]
	chromosomes[1] = c2[0:4] + c1[4:8]
    # Two-point crossover
	chromosomes[2] = c1[0:2] + c2[2:6] + c1[6:8]
	chromosomes[3] = c2[0:2] + c1[2:6] + c2[6:8]
	return chromosomes

def mutation(chromosomes): 
	for i in range(4): 
		chromosomes[i] = chromosomes[i][:2] + str(random.randint(0, 9)) + chromosomes[i][3:5] + str(random.randint(0, 9)) + chromosomes[i][6:]
	return chromosomes

def avg(fitness): 
	return sum(fitness) / len(fitness)

def printGen(chromosomes, fitness, gen):
    print('Gen' + str(gen) + ':')
    for j in range(4):
        print('c' + str(j) + ': ' + str(chromosomes[j]) + ', fitness: ' + str(fitness[j]))
    print('Average Fitness:', avg(fitness))
    print()

def geneticAlgo(): 
	i = 0
	chromosomes = initialize()
	fitness = calcFitness(chromosomes)
	printGen(chromosomes, fitness, i)
	while True: 
		selected = selection(fitness)
		newChromosomes = crossover(chromosomes[selected[0]], chromosomes[selected[1]])
		newChromosomes = mutation(newChromosomes)
		newFitness = calcFitness(newChromosomes)
		printGen(newChromosomes, newFitness, i+1)
		if avg(fitness) > avg(newFitness):
				return chromosomes, fitness, i
		chromosomes = newChromosomes
		fitness = newFitness 
		i += 1

chromosomes, fitness, gen = geneticAlgo()
print("\t*** Optimized Generation: ***")
printGen(chromosomes, fitness, gen)
