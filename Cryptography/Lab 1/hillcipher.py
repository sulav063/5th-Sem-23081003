import numpy as np

# Function to calculate the modular inverse of a matrix under mod 26
def mod_inverse(matrix, mod):
    det = int(round(np.linalg.det(matrix))) % mod  # Compute determinant mod 26
    det_inv = pow(det, -1, mod)  # Compute modular inverse of determinant
    
    if det_inv is None:
        raise ValueError("Key matrix is not invertible under modulo 26.")

    # Compute adjugate (cofactor) matrix
    matrix_adj = np.round(np.linalg.inv(matrix) * np.linalg.det(matrix)).astype(int) % mod
    matrix_adj = (matrix_adj + mod) % mod  # Ensure all values are positive

    return (det_inv * matrix_adj) % mod  # Multiply by modular inverse of determinant

# Function for Hill cipher encryption
def hill_encrypt(plaintext, key):
    mod = 26
    n = len(key)

    # Pad the plaintext if not a multiple of key size
    while len(plaintext) % n != 0:
        plaintext += 'X' 

    # Convert plaintext to numbers
    plaintext_numbers = [ord(char) - ord('A') for char in plaintext.upper()]

    # Encrypt message
    ciphertext_numbers = []
    for i in range(0, len(plaintext_numbers), n):
        block = np.array(plaintext_numbers[i:i+n])
        encrypted_block = np.dot(key, block) % mod
        ciphertext_numbers.extend(encrypted_block)

    # Convert numbers to text
    return ''.join(chr(num + ord('A')) for num in ciphertext_numbers)

# Function for Hill cipher decryption
def hill_decrypt(ciphertext, key):
    mod = 26
    n = len(key)
    key_inv = mod_inverse(key, mod)  # Compute inverse of key matrix

    # Convert ciphertext to numbers
    ciphertext_numbers = [ord(char) - ord('A') for char in ciphertext.upper()]

    # Decrypt message
    decrypted_numbers = []
    for i in range(0, len(ciphertext_numbers), n):
        block = np.array(ciphertext_numbers[i:i+n])
        decrypted_block = np.dot(key_inv, block) % mod
        decrypted_numbers.extend(decrypted_block)

    # Convert numbers to text
    return ''.join(chr(int(num) + ord('A')) for num in decrypted_numbers)

# Example usage
if __name__ == "__main__":
    key_matrix = np.array([[6, 24, 1], [13, 16, 10], [20, 17, 15]])  # Example 3x3 matrix key
    plaintext = "NEVERSETTLEONEPLUS"

    encrypted = hill_encrypt(plaintext, key_matrix)
    decrypted = hill_decrypt(encrypted, key_matrix)

    print(f"Encrypted: {encrypted}")
    print(f"Decrypted: {decrypted}")  # Should match original plaintext
