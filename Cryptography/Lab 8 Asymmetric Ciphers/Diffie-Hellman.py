from random import randint  # Fixed import typo

class User:
    def __init__(self, p, g) -> None:
        self.private = randint(1, p)  # Fixed randint typo
        self.public = pow(g, self.private, p)
    
    def get_public_key(self):
        return self.public
    
    def get_shared_key(self, public_other, p):
        return pow(public_other, self.private, p)  # Fixed return typo

def main():
    p = 23  # Prime number
    g = 5   # Generator
    
    alice = User(p, g)
    bob = User(p, g)
    
    Ya = alice.get_public_key()
    Yb = bob.get_public_key()
    
    Ska = alice.get_shared_key(Yb, p)
    Skb = bob.get_shared_key(Ya, p)
    
    print("Alice's shared key:", Ska)
    print("Bob's shared key:", Skb)
    print("Public key of Alice:", Ya) 
    print("Public key of Bob:", Yb)

if __name__ == "__main__":
    main()
