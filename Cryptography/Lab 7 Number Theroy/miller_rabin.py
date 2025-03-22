from random import randint

def miller_rabin(n, a):
    
    m = n - 1
    k = 0
    while m % 2 == 0:
        m //= 2
        k += 1


    T = pow(a, m, n)
    if T == 1 or T == n - 1:
        return True 

    for _ in range(k - 1):
        T = pow(T, 2, n)
        if T == n - 1:
            return True  
        if T == 1:
            return False 

    return False  

def main():
    n = 937
    a = randint(2, n - 2)
    is_prime = miller_rabin(n, a)
    
    if is_prime:
        print(n, "is a prime number")
    else:
        print(n, "is a composite number")

if __name__ == "__main__":
    main()
