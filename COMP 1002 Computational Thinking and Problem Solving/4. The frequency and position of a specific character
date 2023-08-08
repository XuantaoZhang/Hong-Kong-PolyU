def search(s,c):
    s = list(s)
    index = 0
    count = 0
    position = 1
    list_1 = []

    for s[index] in s:
        if s[index] == c:
            list_1 = list_1+[position]
            index = index + 1
            count = count + 1
            position = position + 1
        else:
            index = index + 1
            position = position + 1

    return list_1,count
        

def main():

    s = input("Input text:")
    c = input("Input a character to be searched:")

    list_1,count = search(s,c)
    print("The character",c,"in the text occured",count,"times at",list_1,".")
    
main()

    
    
