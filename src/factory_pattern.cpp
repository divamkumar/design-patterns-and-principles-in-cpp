#include <iostream>

class Type
{
public:
  void print() {}

};

class Atype : Type
{
public:
  void print()
  {
    std::cout << "This is Atype" << "\n";
  }
};

class Btype : Type
{
public:
  void print()
  {
    std::cout << "This is Btype" << "\n";
  }
};

static void printType( Type t )
{
  std::cout << t.print() << "\n";
}

int main()
{
  Type t;

  char userInput; 
  std::cout << "What type do you want? (A or B): ";
  std::cin >> userInput;
  if ( userInput == 'A' )
    t = new Atype();
  if ( userInput == 'B' )
    t = new Btype();

  printType( t );
  return 0;
}
