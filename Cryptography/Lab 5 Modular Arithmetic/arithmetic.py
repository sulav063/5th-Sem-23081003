import math

def additive_inverse(a, m):
    """Finds the additive inverse of 'a' under modulo 'm'"""
    return (-a) % m

def gcd_extended(a, b):
    """Extended Euclidean Algorithm to find gcd and multiplicative inverse"""
    if a == 0:
        return b, 0, 1
    else:
        gcd, x1, y1 = gcd_extended(b % a, a)
        x = y1 - (b // a) * x1
        y = x1
        return gcd, x, y

def multiplicative_inverse(a, m):
    """Finds the multiplicative inverse of 'a' under modulo 'm' if it exists"""
    gcd, x, _ = gcd_extended(a, m)
    if gcd != 1:
        return None  # No multiplicative inverse if gcd is not 1
    else:
        return x % m  # Ensure the result is positive

def is_relatively_prime(a, b):
    """Checks if 'a' and 'b' are relatively prime"""
    return math.gcd(a, b) == 1

a, m = 5, 7
print(f"Additive inverse of {a} mod {m}: {additive_inverse(a, m)}")
print(f"Multiplicative inverse of {a} mod {m}: {multiplicative_inverse(a, m)}")
print(f"Are {a} and {m} relatively prime? {is_relatively_prime(a, m)}")
