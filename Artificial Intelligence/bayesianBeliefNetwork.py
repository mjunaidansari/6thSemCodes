# cases
burglary = {True: 0.001, False: 0.999}
fire = {True: 0.002, False: 0.998}

#alarm for burglary and fire 
alarm = {
	(True, True): {True: 0.95, False: 0.05},
	(True, False): {True: 0.94, False: 0.06},
	(False, True): {True: 0.29, False: 0.71},
	(False, False): {True: 0.001, False: 0.999}
}

# person for alarm
person1 = {
	True: {True: 0.95, False: 0.05},
	False: {True: 0.05, False: 0.95}
}
person2 = {
	True: {True: 0.8, False: 0.2},
	False: {True: 0.01, False: 0.99}
}

ip = input("\nEnter the values for case P(person1, person2, alarm, burglary, fire): ")
p1, p2, a, b, f = [bool(int(value)) for value in ip.split()]

p = person1[a][p1] * person2[a][p2] * alarm[(b, f)][a] * burglary[b] * fire[f]

print("The Probability of occurence of above case: ", p, "\n")