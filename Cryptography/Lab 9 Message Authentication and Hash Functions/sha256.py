import hashlib

def main():
    # Input string
    input_string = "sushant kc"

    # Create a SHA-256 hash object
    sha256_hash = hashlib.sha256()

    # Update the hash object with the string (encoded to bytes)
    sha256_hash.update(input_string.encode())

    # Get the hexadecimal representation of the hash
    sha256_result = sha256_hash.hexdigest()

    print(f"SHA-256 Hash of the string: {sha256_result}")

if __name__ == "__main__":
    main()
