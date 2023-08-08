install.packages("ggplot2")
library("ggplot2")

#(a)
#Open the file. The file is put in my desktop
setwd("C:/Users/jeff8/Desktop")
employees=read.csv("employees.csv", header=TRUE, sep=",")

#Salary Per Year creation
people = 1
Salary_Per_Year=c()
year_salary=0

while(people<=35){
  year_salary=employees[people,4]*12
  Salary_Per_Year=c(Salary_Per_Year,year_salary)
  people=people+1
}
employees=data.frame(employees,Salary_Per_Year)

#(b)
p=1
male_sum=0
male=0
female_sum=0
female=0
while(p<=35){
  if(employees[p,2]=='Male'){
    male=male+1
    male_sum=male_sum+employees[p,5]
  }
  else{
    female=female+1
    female_sum=female_sum+employees[p,5]
  }
  p=p+1
}
male_average=round(male_sum/male,digits=2)
female_average=round(female_sum/female,digits=2)

print(paste("The average salary per year for male employees is",male_average))
print(paste("The average salary per year for female employees is",
            female_average))

#(c)
c=ggplot(data=employees)+
  geom_histogram(mapping=aes(x=Years_of_Experience),binwidth=1,fill="orange",
                 color="black")+labs(x='Years of Experience',y='Frequency')
print(c)

#(d)
d=ggplot(data=employees)+
  geom_point(mapping=aes(x=Years_of_Experience,y=Monthly_Salary,color=Gender))+
  labs(x='Years of Experience',y='Monthly Salary')
print(d)

