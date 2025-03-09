from Crypto.Cipher import AES
import binascii
import os

# AES block size
BLOCK_SIZE = 16

# Function to pad data using PKCS7 padding
def pad(text):
    padding_length = BLOCK_SIZE - (len(text) % BLOCK_SIZE)
    return text + chr(padding_length) * padding_length

# Function to unpad data after decryption
def unpad(text):
    padding_length = ord(text[-1])  # Get padding length from last character
    return text[:-padding_length]

# Function to encrypt plaintext using AES in CBC mode
def aes_encrypt(plaintext, key):
    key = key.ljust(16, b'\0')[:16]  # Ensure key is exactly 16 bytes
    iv = os.urandom(16)  # Generate a random 16-byte IV
    cipher = AES.new(key, AES.MODE_CBC, iv)  # AES in CBC mode
    padded_text = pad(plaintext).encode()  # Apply PKCS7 padding
    encrypted_text = cipher.encrypt(padded_text)  # Encrypt
    return binascii.hexlify(iv + encrypted_text).decode()  # Return IV + ciphertext in hex

# Function to decrypt ciphertext using AES in CBC mode
def aes_decrypt(ciphertext, key):
    key = key.ljust(16, b'\0')[:16]  # Ensure key is exactly 16 bytes
    ciphertext = binascii.unhexlify(ciphertext)  # Convert hex to bytes
    iv, encrypted_text = ciphertext[:16], ciphertext[16:]  # Extract IV and ciphertext
    cipher = AES.new(key, AES.MODE_CBC, iv)  # AES in CBC mode
    decrypted_text = cipher.decrypt(encrypted_text).decode()  # Decrypt
    return unpad(decrypted_text)  # Remove padding

# Implementation
key = os.urandom(16)  # Generate a random 16-byte AES key
plaintext = "Hello I'm a secret message!"

ciphertext = aes_encrypt(plaintext, key)
print(f"Ciphertext: {ciphertext}")

decrypted_text = aes_decrypt(ciphertext, key)
print(f"Decrypted text: {decrypted_text}")
