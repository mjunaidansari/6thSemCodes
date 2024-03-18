def publicKey(x, a, q):
    return (a**x)%q

def secureKey(x, y, q):
    return (y**x)%q

q = 7
a = 3
print('q: ', q, 'a: ', a)
xa = int(input('Enter Private Key of A (less than q): '))
xb = int(input('Enter Private Key of B (less than q): '))

# generating public keys
ya = publicKey(xa, a, q)
yb = publicKey(xb, a, q)
print('\nSecure key of A: ', ya)
print('Secure key of B: ', yb)

# generating secure keys
ksa = secureKey(xa, yb, q)
ksb = secureKey(xb, ya, q)
print('\nSecure key of A: ', ksa)
print('Secure key of B: ', ksb)

# conclusion
if(ksa == ksb): 
    print('\nHence the key exchange is secure.')
else: 
    print('\nThe key exchange is not secure.')