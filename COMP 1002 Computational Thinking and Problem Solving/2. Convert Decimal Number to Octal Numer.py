#Case 1
#input: 550
#expected output: 1046

#Case 2
#input: 10000
#expected output: 23420

def main():
    count = 0
    o = 0
    q = eval(input("Please enter a decimal number(an integer number in base 10). >>"))
    while q >0:
        r = q % 8
        q = q // 8
        o = o + 10**count*r
        count = count+1
        print("quotient",q)
        print("remainder",r)

    oct = str(o)
    print ("The octal number is:",oct)

main()
            
    
