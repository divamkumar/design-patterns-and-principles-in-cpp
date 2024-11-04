## Singleton Pattern

A design pattern used when we only want one object and that's it.

### Case Study

We will be creating a class that holds all the Scrabble letters and outputs new letters upon request.
- Players will share the same object that spits out letters
- Players will have their own set of letters.

### Solution
singleton_solution.cpp holds the solution to the above scenario, includeing thread-testing code to make sure only 1 Singleton instance is ever created.
