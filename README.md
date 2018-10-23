# PurdueSIGAI

Using C++, I will be creating a model that best fits the data points from the "train" file. I will then use my model to make my own predictions using the test file. This is part of Purdue's AI club.

Branch Simple-Linear-Regression-with-1-input (9-20-18 ~ 10-13-18) 
In this branch, it calculates a simple linear regression when you only have one input. This program use summations to determine the best slope based off the SS res (getting the smallest squares). 

Branch Simple-Linear-Model-with-8-inputs (10-13-18 ~ 10-16-18) 
This branch would use my little knowledge of Linear Algbera. Since it is not possible to get an equation that touches all these points, I will use linear algebra to basically solve for x^. At*A*x^ = At*b, A is the data set and At is the transpost. B is a vector that displays all the outputs when A * vector x^ is multiplied. Using x^, I should be able to get a line that best represent the model (median housing prices in the bay area) 

Branch Simple-Linear-Model-with-8-inputs (10-22-18) 
In this branch, I decided to create a parabolic model that best represented the graph. Based off of this mode, we got an R^2 value at about 0.678 which is an improvement than having a smiple linear model with 8 inputs. In this scenario, we had X^2 x and then a constant. I am planning to see if a cublic model is still possible but we hope to explore other options than just using basic Linear Algebra equations and theorems. 

CURRENT: Branch Masters (10-16-18) 
Based off the Simple-Linear-Model-with-8-inputs, we got an r^2 value of .586, which means a linear model in the 9th dimension does not best represent the data set. Therefore, we will be using a more complex model which have a b constant, coefficient for x, coefficient with x^2, and coefficient of x^3. This would get a more accurate model of the data set. 
