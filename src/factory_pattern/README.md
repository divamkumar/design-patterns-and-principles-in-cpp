## Factory Pattern
A design pattern used when we want a function to return one of several different child class objects, which all have the same base class.

### Case study
Say we have a video game and we want to create an enemy from random.
- Have a random number generator choose a number
- Depending on the number, a specific type of enemy is chosen at runtime and returned

### Solution study
The solution implements the same functionality, but uses the factory pattern to modularize the code.
