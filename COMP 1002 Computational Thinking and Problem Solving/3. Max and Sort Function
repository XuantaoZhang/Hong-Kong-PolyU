#a).

def myMax(numbers):
    total = len(numbers)
    a = numbers[0]
    count = 0
    b = 0
   

    while count<=(total-1):
        if a > numbers[count]:
            count = count + 1
            
            
        elif a <= numbers[count]:
            a = numbers[count]
            count = count + 1
            b = count
            
    return a,b

def main_1():
    numbers = eval(input("Please enter a list of different numbers separated by ',':"))
    a,b=myMax(numbers)
    print("The maximal number is",a,".")
    print("Its location index is",b,".")
main_1()

#b).

def mySort(numbers):
    list_1=[]
    numbers=list(numbers)
    list_2=numbers
    l = len(list_2)

    while l != 0:
        a,b=myMax(numbers)
        l = l - 1
        list_2.remove(a)
        list_1.append(a)

    
    return list_1,list_2


def main_2():
    numbers = eval(input("Please enter a list of different numbers separated by ',':"))
    list_1,list_2=mySort(numbers)

    print("A list of sorting values in descending order:",list_1,".")
    
main_2()
    
    
    

    


            




    
