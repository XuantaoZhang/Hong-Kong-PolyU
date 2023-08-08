#Q3 (b)
install.packages("ggplot2")
library("ggplot2")

#returned the number of failures before the nth success
set.seed(42)
random=rnbinom(10000,20,0.5)
nb_data=table(random)
nb_data=data.frame(nb_data,stringsAsFactors=FALSE)
i=1
percent=c()
classification=c()
l=length(nb_data[,1])

#length(nb_data[,1])can determine the maximum value of i
l=length(nb_data[,1])
while(i<=l){
  percentage=nb_data[i,2]/10000
  percent=c(percent,percentage)
  classification=c('Random Data')
  i=i+1
}
nb_data=data.frame(nb_data,percent,classification)

#Derived probability mass function
#As the question's requirement, The number of failures is from 0 to 100
#so the range of sum of successes and failures is from 20 to 120
#My derived pdf is P(X=k;r;p)=(k-1)C(r-1)*p^r*(1-p)^(k-r)
#However,k is the sum of successes and failures, so k=failure+20
failure=0
r=20
p=0.5
pdf_failure=c()
pdf_percent=c()
class=c()
while(failure<=100){
  k=failure+20
  pdf_percentage=(factorial(k-1))/(factorial(k-r)*factorial(r-1))*(p^r)*p^(k-r)
  pdf_percent=c(pdf_percent,pdf_percentage)
  pdf_failure=c(pdf_failure,failure)
  class=c('Derived Formula')
  failure=failure+1
}

nb_pdf=data.frame(pdf_failure,pdf_percent,class)

#Combine two dataframes and plot the graph
names(nb_pdf)=c("random","percent","classification")
nb_data=nb_data[,-2]
com_data=rbind(nb_pdf,nb_data)
com_data$random=as.numeric(com_data$random)
ggp=ggplot(data=com_data)+
  geom_point(mapping=aes(x=random,y=percent,color=classification))+
  labs(x='Number of failures',y='Probability')
print(ggp)


#Q3 (d)

#This is a binomial distribution situation. 
#rbinom(n, size, r) simulates n times of hit times of the cat within 104 weeks
set.seed(104)
hit_time=rbinom(100000,104,0.05)
hit=data.frame(table(hit_time))

#Calculate the proportion of n times hits within 104 weeks
f=1
l_d=length(hit[,1])
d_proportion=c()
while(f<=l_d){
  d_proportion=c(d_proportion,hit[f,2]/100000)
  f=f+1
}
hit=data.frame(hit,d_proportion)

#One life, can die 0 times
one_life=hit[1,3]
#Two lives, can die 1 or fewer times
two_lives=hit[2,3]+one_life
#Three lives, can die 2 or fewer times
three_lives=hit[3,3]+two_lives
#Four lives, can die 3 or fewer times
four_lives=hit[4,3]+three_lives
#Five lives, can die 4 or fewer times
five_lives=hit[5,3]+four_lives
#Six lives, can die 5 or fewer times
six_lives=hit[6,3]+five_lives
#Severn lives, can die 6 or fewer times
seven_lives=hit[7,3]+six_lives
#Eight lives, can die 7 or fewer times
eight_lives=hit[8,3]+seven_lives
#Nine lives, can die 8 or fewer times
nine_lives=hit[9,3]+eight_lives

#Print out results
print(one_life)
print(two_lives)
print(three_lives)
print(four_lives)
print(five_lives)
print(six_lives)
print(seven_lives)
print(eight_lives)
print(nine_lives)

#(d) Alternative solution

#one life. 
#The following code describes the likelihood of most 104-1=103 failures before
#first hit, which means he will be hit at least in 104th week
p_1 = pnbinom(103,1,0.05)
#1-p_1 should be the answer since he needs to live at least 104 weeks
print(1-p_1)

#Nine lives.
#Same idea as before. The first parameter inside pnbinom should be 104-9=95
p_9=pnbinom(95,9,0.05)
print(1-p_9)