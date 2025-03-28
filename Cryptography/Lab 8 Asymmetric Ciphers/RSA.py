import random
from sympy import isprime

# Function to find gcd
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Function to find modular inverse
def mod_inverse(e, phi):
    for d in range(1, phi):
        if (e * d) % phi == 1:
            return d
    return None

# Function to generate RSA keys
def generate_keys():
    # Generate two large prime numbers
    while True:
        p = random.randint(100, 500)
        if isprime(p):
            break
    while True:
        q = random.randint(100, 500)
        if isprime(q) and q != p:
            break

    # Calculate n and phi
    n = p * q
    phi = (p - 1) * (q - 1)

    # Choose e such that 1 < e < phi and gcd(e, phi) = 1
    while True:
        e = random.randint(2, phi - 1)
        if gcd(e, phi) == 1:
            break

    # Calculate d (modular inverse of e)
    d = mod_inverse(e, phi)

    return (e, n), (d, n)

# Function to encrypt a message
def encrypt(public_key, plaintext):
    e, n = public_key
    ciphertext = [pow(ord(char), e, n) for char in plaintext]
    return ciphertext

# Function to decrypt a message
def decrypt(private_key, ciphertext):
    d, n = private_key
    plaintext = ''.join([chr(pow(char, d, n)) for char in ciphertext])
    return plaintext

# Main program
if __name__ == "__main__":
    print("RSA Encryption/Decryption")
    public_key, private_key = generate_keys()
    print(f"Public Key: {public_key}")
    print(f"Private Key: {private_key}")

    message = input("Enter a message to encrypt: ")
    encrypted_message = encrypt(public_key, message)
    print(f"Encrypted Message: {encrypted_message}")

    decrypted_message = decrypt(private_key, encrypted_message)
    print(f"Decrypted Message: {decrypted_message}")