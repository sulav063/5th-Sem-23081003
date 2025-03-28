import collections

def prime_factor(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return dict(collections.Counter(factors))

def etf(m):
    factors = prime_factor(m)
    prdt = m
    for p, e in factors.items():
        prdt *= (p - 1)
        prdt //= p
    return prdt

def main():
    a = 3
    m = 10
    etf_value = etf(m) 
    print("O(m) =", etf_value)

    if pow(a, etf_value, m) == 1:
        print("Thus,", etf_value, "numbers are relatively prime to", m)
    else:
        print("Thus,", etf_value, "numbers are not relatively prime to", m)

if __name__ == "__main__":
    main()
