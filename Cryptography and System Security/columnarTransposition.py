# columnar transposition cipher
pt = input('\nEnter Plain Text: ')
keyword = input('Enter Keyword: ')

def simplifyKey(keyword):
    # converting the string to list
    ar = [ord(char) for char in keyword]
    # sorting the list first and getting their indices as ranks
    ranks = [sorted(ar).index(x)+1 for x in ar]
    # converting list elements to string and then joining them
    key = ''.join(map(str, ranks))
    return key

def encrypt(pt, keyword):
    key = simplifyKey(keyword)
    pt = pt.replace(" ", "").upper()
    while len(pt)%len(key) != 0:
        pt += 'Z'
    # initializing the table
    table = [[0 for i in range(len(key))] for j in range(int(len(pt)/len(key)))]
    counter = 0
    # filling the table
    for i in range(len(table)): 
        for j in range(len(table[0])):
            table[i][j] = pt[counter]
            counter += 1
    # creating a dictionary for key values and its index
    key_dict = {}
    for i, n in enumerate([int(char) for char in key]): 
        key_dict[n] = i
    # getting cipher by reading the keys in sorted order and getting values from table through its value
    cipher = ''
    for key, value in dict(sorted(key_dict.items())).items(): 
        for j in range(len(table)):
            cipher += table[j][value]
    return cipher

def decrypt(cipher, keyword):
    key = simplifyKey(keyword) 
    # creating a dictionary for key values and its index and sorting it
    key_dict = {}
    for i, n in enumerate([int(char) for char in key]): 
        key_dict[n] = i
    key_dict = dict(sorted(key_dict.items()))
    # initializing the table
    table = [[0 for i in range(len(key))] for j in range(int(len(cipher)/len(key)))]
    # filling the table
    counter = 0
    for key, value in key_dict.items():
        for i in range(len(table)): 
            table[i][value] = cipher[counter]
            counter += 1
    # generating plain text
    pt = ''
    for a in table:
        for c in a: 
            pt += c
    return pt

cipher = encrypt(pt, keyword)
print('Encrypted Cipher: ', cipher)
newPt = decrypt(cipher, keyword)
print('Decrypted Text: ', newPt, '\n')


# kill corona virus at twelve am tomorrow
# 4312567
# i am not going to college tomorrow
# 35214