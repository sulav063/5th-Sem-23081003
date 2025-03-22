def primitive_roots(p):
    list_ =list(range(1,p))
    roots=[]
    for item in list_:
        gen_num=[]
        for i in range(p):
            gen_num.append((item **i)%p)
        gen_num=list(set(gen_num))
        gen_num.sort()
        if gen_num == list_:
            roots.append(item)
    return roots

def main():
    p=11
    roots=primitive_roots(p)
    print("Primitive Roots of",p,"are",roots)

main()