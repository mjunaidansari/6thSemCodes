def findD(e, n, pn):
    d = 0
    for i in range(1, n+1):
        d = ((pn * i) + 1)/e
        if d.is_integer(): 
            return int(d)

def rsa(p, q, e):
    n = p*q
    pn = (p-1)*(q-1)
    d = findD(e, n, pn)
    return (e, n), (d, n)

def encrypt(key, m): 
    c = m**key[0] % key[1]
    return c
    
def decrypt(key, c): 
    m = c**key[0] % key[1]
    return m

m = int(input('\nEnter Message: '))

# p, q, e = 13, 11, 13
p, q, e = 61, 53, 17
# p, q, e = 17, 19, 7
# p, q, e = 7, 11, 17

print('p: {}, q: {}'.format(p, q))

publicKey, privateKey = rsa(p, q, e)
print('\nPublic Key (e, n): ', publicKey, '\nPrivate Key (d, n): ', privateKey)

c = encrypt(publicKey, m)
m = encrypt(privateKey, c)

print('\nCipher Text: ', c, '\nDecrypted Message: ', m, '\n')
