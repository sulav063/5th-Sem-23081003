import numpy as np
def findIndex(matrix, letter):
    r=0
    for row in matrix:
        c=0
        for element in row:
            if element == letter:
                return (r,c)
            elif(letter in element):
                return r,c
            c+=1
        r+=1
def encryptMessage(message,key):
    keyMatrix=generateMatrix(key)
    message.replace(" ",'')
    message=list(message)
    cipherText=''
    for i in range(int(np.ceil(len(message)/2))):
        digraph=message[0:2]
        if len(digraph)==2:
            if digraph[0]!=digraph[1]:
                message.pop(0)
                message.pop(0)
            elif digraph[0]!='X':
                digraph[1]='X'
                message.pop(0)
            else:
                digraph[1]='Q'
                message.pop(0)
        elif digraph[0]!='X':
            digraph.append('X')
            message.pop(0)
        else:
            digraph.append('Q')
            message.pop(0)
        r1,c1=findIndex(keyMatrix, digraph[0])
        r2,c2=findIndex(keyMatrix, digraph[1])
        if r1==r2:
            if c1!=4 and c2!=4:
                cipherText+=keyMatrix[r1][c1+1]
                cipherText+=keyMatrix[r1][c2+1]
            elif c1!=4:
                cipherText+=keyMatrix[r1][c1+1]
                cipherText+=keyMatrix[r1][0]
            else:
                cipherText+=keyMatrix[r1][0]
                cipherText+=keyMatrix[r1][c2+1]
        elif c1==c2:
            if r1!=4 and r2!=4:
                cipherText+=keyMatrix[r1+1][c1]
                cipherText+=keyMatrix[r2+1][c1]
            elif r1!=4:
                cipherText+=keyMatrix[r1+1][c1]
                cipherText+=keyMatrix[0][c2]
            else:
                cipherText+=keyMatrix[0][c1]
                cipherText+=keyMatrix[r2+1][c1]
        else:
            cipherText+=keyMatrix[r1][c2]
            cipherText+=keyMatrix[r2][c1]
    return cipherText
def generateMatrix(key):
    matrix=[]
    keyMatrix=[[None for _ in range(5)] for _ in range(5)]
    for i in range(len(key)):
        if key[i] not in matrix:
            if key[i] not in ['I','J']:
                matrix.append(key[i])
            else:
                matrix.append('I')
    for j in range(26):
        if letters[j] not in matrix:
            if letters[j] not in ('I','J'):
                matrix.append(letters[j])
            elif 'I' not in matrix:
                matrix.append('I')
            else:
                continue
    count=0
    for rows in range(5):
        for cols in  range(5):
            keyMatrix[rows][cols]=matrix[count]
            count+=1
    print(keyMatrix)
    return keyMatrix
letters=[]
for i in range(65,91):
    letters.append(chr(i))
message="CRYPTOGRAPHY"
key="ACHS"
print(encryptMessage(message.upper(),key.upper()))