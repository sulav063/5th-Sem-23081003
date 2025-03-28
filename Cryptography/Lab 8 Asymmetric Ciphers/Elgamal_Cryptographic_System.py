from random import randint
from sympy import isprime, mod_inverse

# Function to generate large prime number
def generate_large_prime():
    while True:
        prime_candidate = randint(10**5, 10**6)
        if isprime(prime_candidate):
            return prime_candidate

# Key generation
def generate_keys():
    p = generate_large_prime()  # Large prime number
    g = randint(2, p - 1)       # Generator
    x = randint(1, p - 2)       # Private key
    y = pow(g, x, p)            # Public key
    return (p, g, y), x

# Encryption
def encrypt(public_key, message):
    p, g, y = public_key
    k = randint(1, p - 2)       # Random integer
    c1 = pow(g, k, p)
    c2 = (message * pow(y, k, p)) % p
    return c1, c2

# Decryption
def decrypt(private_key, public_key, ciphertext):
    p, g, y = public_key
    c1, c2 = ciphertext
    s = pow(c1, private_key, p)
    s_inv = mod_inverse(s, p)
    message = (c2 * s_inv) % p
    return message

# Main function
if __name__ == "__main__":
    # Generate keys
    public_key, private_key = generate_keys()
    print("Public Key:", public_key)
    print("Private Key:", private_key)

    # Input message
    message = int(input("Enter a message (as an integer): "))
    print("Original Message:", message)

    # Encrypt the message
    ciphertext = encrypt(public_key, message)
    print("Encrypted Message:", ciphertext)

    # Decrypt the message
    decrypted_message = decrypt(private_key, public_key, ciphertext)
    print("Decrypted Message:", decrypted_message)