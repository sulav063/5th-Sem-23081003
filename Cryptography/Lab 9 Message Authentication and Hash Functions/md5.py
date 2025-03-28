import hashlib

def calculate_md5(input_string):
    # Create an MD5 hash object
    md5_hash = hashlib.md5()

    # Update the hash object with the string (encoded to bytes)
    md5_hash.update(input_string.encode())

    # Get the hexadecimal representation of the hash
    return md5_hash.hexdigest()

def main():
    # Input string
    input_string = "Virat Kohli"

    # Calculate MD5 hash
    md5_result = calculate_md5(input_string)

    # Output the result
    print(f"MD5 Hash of the string: {md5_result}")

if __name__ == "__main__":
    main()
