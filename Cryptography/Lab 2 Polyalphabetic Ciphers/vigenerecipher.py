import numpy as np

def encryptMessage(plainText, key):
    cipherText = ''
    keylen = int(np.ceil(len(plainText) / len(key)))
    key *= keylen  # Extend key to match length
    count = 0
    
    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index + shifter) % 26
            cipherText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count])  # Keep using lowercase index for shift
            shiftedIndex = (index + shifter) % 26
            cipherText += upperCase[shiftedIndex]
            count += 1
        else:
            cipherText += letter  # Keep spaces, punctuation unchanged
    return cipherText

def decryptMessage(cipherText, key):
    plainText = ''
    keylen = int(np.ceil(len(cipherText) / len(key)))
    key *= keylen  # Extend key to match length
    count = 0
    
    for letter in cipherText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index - shifter) % 26
            plainText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count])  # Keep using lowercase index for shift
            shiftedIndex = (index - shifter) % 26
            plainText += upperCase[shiftedIndex]
            count += 1
        else:
            plainText += letter  # Keep spaces, punctuation unchanged
    return plainText

# Creating uppercase and lowercase letter lists
upperCase = [chr(i) for i in range(65, 91)]
lowerCase = [chr(i) for i in range(97, 123)]

# User Input
message = input('Enter your Message: ')
key = 'messi'

# Encrypting Message
cipherText = encryptMessage(message, key)
print(f'Your encrypted Message: {cipherText}')

# Decryption with user-provided key
key2 = input('Please enter the secret key to decrypt the message: ')
plainText = decryptMessage(cipherText, key2)

print(f'Your hidden message is: {plainText}')
