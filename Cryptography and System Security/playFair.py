# to find index of char in matrix
def findIndex(c, matrix): 
    for i in range(5): 
        for j in range(5):
            if matrix[i][j] == c or c in matrix[i][j]: 
                return (i, j)
    return None

# to generate matrix 
def genMatrix(key): 
	# Generating matrix
	matrix = [[0 for i in range(5)] for j in range(5)]
	temp = key
	rows = 0
	cols = 0
	
	# pushing key in matrix 
	while temp:
		# the case of getting i in key
		if temp[0] == 'I':
		    matrix[cols][rows] = temp[0] + 'J'
		else: 
		    matrix[cols][rows] = temp[0]
		temp = temp[1:]
		rows +=1
		if rows == 5: 
			rows = 0
			cols += 1

	# 65-90 is A-Z
	code = 65
	while code < 91: 
		# if in key then skip
		if chr(code) in key:
			code += 1
			# ignoring J if I is already present in the key
			if 'I' in key and chr(code) == 'J':
				code += 1
			continue
		else: 
			# if i then add i and j
			if chr(code) == 'I':
				matrix[cols][rows] = chr(code) + chr(code+1)
				code += 1
			# else just add the current character
			else:      
				matrix[cols][rows] = chr(code)
		code += 1
		rows +=1
		if rows == 5: 
			rows = 0
			cols += 1
		if cols > 4: 
			break
	return matrix
	
def encrypt(pt, matrix): 
	temp = pt
	cipher = ''
	while temp:
		a = temp[0:2] # getting first two characters in a
		temp = temp[2:] # removing first two characters from temp
		a0 = findIndex(a[0], matrix)
		a1 = findIndex(a[1], matrix)
		if a0[0] == a1[0]:
			# same row
			cipher += matrix[a0[0]][(a0[1]+1)%5]
			cipher += matrix[a1[0]][(a1[1]+1)%5]
		elif a0[1] == a1[1]:
			# same column
			cipher += matrix[(a0[0]+1)%5][a0[1]]
			cipher += matrix[(a1[0]+1)%5][a1[1]]
		else: 
			# rectangle case
			cipher += matrix[a0[0]][a1[1]]
			cipher += matrix[a1[0]][a0[1]]
		a = '' 
	return cipher
    

pt = input('\nEnter plain text: ').upper()
if len(pt)%2!=0:
    pt += 'Z'
# 2 extra cases to handle: getting i, getting repeated char
key = input('Enter key: ').upper()

matrix = genMatrix(key)
cipher = encrypt(pt, matrix)

print()
for row in matrix: 
	print(row)
print('\nPlain Text:  ', pt)
print('Cipher Text: ', cipher, '\n')