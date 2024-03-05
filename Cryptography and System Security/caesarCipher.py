# Caesar Cipher Algorithhm
data = input("\nEnter a String: ")
n = int(input("Enter the Key Value: "))

# encryption function
def encrypt(data):
    encryptedData = ''
    for c in data: 
        encryptedData += chr((ord(c)+n))
    return encryptedData

# decryption function
def decrypt(encryptedData):
    decryptedData = ''
    for c in encryptedData: 
        decryptedData += chr((ord(c)-n))
    return decryptedData

encryptedData = encrypt(data)
decryptedData = decrypt(encryptedData)

print('\nEncrypted Data: ', encryptedData)
print('Decrypted Data: ', decryptedData)