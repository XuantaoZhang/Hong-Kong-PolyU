#ZHANG Xuantao 22097272d

#a).

def myMedian(X):
    X = list(X)
    X = sorted(X)
    length = len(X)
    median = 1

    if length % 2 == 0: 
        median = median * (X[length//2-1]+X[length//2])/2

    else:
        median = median * (X[length//2])

    return median

#b).

def main():
    import csv
    infile=open("iris2021.csv","r")
    data=infile.readlines()
    length = len(data)
    listS=[]
    listV=[]
    listv=[]

    for i in range (length):
        if 'setosa'in data[i]:
            listS.append(data[i])
        elif 'versicolor' in data[i]:
            listV.append(data[i])
        elif 'virginica' in data[i]:
            listv.append(data[i])

    listS1=[]
    listV1=[]
    listv1=[]

    for S in listS:
        S = float(S.replace(",setosa",""))
        listS1.append(S)

    for V in listV:
        V = float(V.replace(",versicolor",""))
        listV1.append(V)

    for v in listv:
        v = float(v.replace(",virginica",""))
        listv1.append(v)


    X = listv1
    median = myMedian(X)
    print("The median of Petal.Width for virginica is {0:0.3f}.".format(median))

    X = listV1
    median = myMedian(X)
    print("The median of Petal.Width for versicolor is {0:0.3f}.".format(median))
    

    X = listS1
    median = myMedian(X)
    print("The median of Petal.Width for setosa is {0:0.3f}.".format(median))


main()
