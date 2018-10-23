# PurdueSIGAI

Using C++, I will be creating a model that best fits the data points from the "train" file. I will then use my model to make my own predictions using the test file. This is part of Purdue's AI club.

Branch simple-regression (9-20-18 ~ 10-13-18) 
In this branch, it calculates a simple linear regression when you only have one input. This program use summations to determine the best slope based off the SS res (getting the smallest squares). 

CURRENT: Branch Masters (10-13-18) 
This branch would use my little knowledge of Linear Algbera. Since it is not possible to get an equation that touches all these points, I will use linear algebra to basically solve for x^. At*A*x^ = At*b, A is the data set and At is the transpost. B is a vector that displays all the outputs when A * vector x^ is multiplied. Using x^, I should be able to get a line that best represent the model (median housing prices in the bay area) 
