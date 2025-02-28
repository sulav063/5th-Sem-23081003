def encryptMessage(message, key):
    cipherText = ''
    c = 0
    r = 0
    i = 0
    down = True
    matrix = [[None for _ in range(len(message))] for _ in range(key)]

    while c < len(message): 
        matrix[r][c] = message[i]
        if down:
            r += 1
        else:
            r -= 1
        if r + 1 == key:
            down = False
        elif r == 0:
            down = True
        c += 1
        i += 1

    # Print matrix (for debugging)
    for row in matrix:
        print(row)
        for item in row:
            if item is not None:  
                cipherText += item

    return cipherText

print(encryptMessage('CRYPTOGRAPHY', 2))  
