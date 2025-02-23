def encryptMessage(plainText, key):
    cipherText=''
    for letter in plainText:
        if letter in lowerCase:
            index=lowerCase.index(letter)
            shiftedIndex=(index+key)%26
            cipherText+=lowerCase[shiftedIndex]
        elif letter in upperCase:
            index=upperCase.index(letter)
            shiftedIndex=(index+key)%26
            cipherText+=upperCase[shiftedIndex]
        else:
            cipherText+=letter
    return cipherText

def decryptMessage(ciphertext,key):
    plainText=''
    for letter in ciphertext:
        if letter in lowerCase:
            index=lowerCase.index(letter)
            shiftedIndex=(index-key)%26
            plainText+=lowerCase[shiftedIndex]
        elif letter in upperCase:
            index=upperCase.index(letter)
            shiftedIndex=(index-key)%26
            plainText+=upperCase[shiftedIndex]
        else:
            plainText+=letter

upperCase=[]
lowerCase=[]
for i in range(65,91):
    upperCase.append(chr(i))
for j in range(97, 123):
    lowerCase.append(chr(j))

message=input('Enter your message here: ')
key=input('Enter your key here: ')
ciphertext=encryptMessage(message,int(key))
print(f'Others will see: {ciphertext}')
key2=input('Please enter the key to decrypt your message: ')
plainText=decryptMessage(ciphertext,int(key2))
print(f'Hidden Message seen by recevier: {plainText}')