# dichotomy
Dichotomy is a mathematical method to solve an equation, with this code we can  solve the equation of f(x)=0

This methoode will take an intevale and divided in two parts, if it the multiplication between the middle of  this interval and one of the interval limits is negative (<0) then we choose a nea intervale in wich the terminals this time are the first terminal and the middle of the old interval
With this process we will be closer and closer to the solution, and this  is what the algorithm will do


- you will have to gave the give the interval where the solution is (evem if its a large one)
- you will also have to provide the error estimate or how small should the solution be (for instance 10^-3)

With that it will count the number of iterations, or how many time should the process be repeated until it gets the solution


As a result, you would have am array showing the the intevrals choosen, the number of the iteration, and the result each time

## NOTE:

This algorithm use a very important library called **tinyexpr** which is use so it can takke the input of the user when he is writing the mathamtical function

and this is why we cant write e^x but exp(x) instead
and not ln(x) but log(x) (the same goes for log) ect.. 

So concider installing **tinyexpr** when you try to run the code 

**HERE IS THE LINK**
https://github.com/codeplea/tinyexpr

## Note N=2
*D'ont mind the french comments in the code*
