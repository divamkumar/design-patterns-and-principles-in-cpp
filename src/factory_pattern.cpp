#include <iostream>
#include <memory>

class Type
{
public:
  Type() {}
  Type( const Type& right ) {}
  Type& operator=( Type& right )
  {
    return *this;
  }

  // Virtual destructor so that in the case of Type* t = new AType()
  // AType's destructor can still be called through Type*
  virtual ~Type() = default;

  virtual void print() const {}

};

// Make sure to inherit publicly since private inheritance is the default
// so that polymorphism can be achieved.
// Private inheritance is not polymorphism, but child class can explicitly
// call base class's methods to perform polymorphism "explicitly" and hide
// the base class interface, in a way.
class AType : public Type
{
public:
  void print() const override
  {
    std::cout << "This is AType" << "\n";
  }
};

class BType : public Type
{
public:
  void print() const override
  {
    std::cout << "This is BType" << "\n";
  }
};

// Make sure to pass by reference or pointer to prevent
// object slicing, which is when a child class is passed 
// by value or assigned to a base class object, and the 
// derived attributes are "sliced off, leaving only the 
// base class part. This can cause bugs and resource issues.
static void printType( Type& t )
{
  t.print();
}

int main()
{
  std::unique_ptr<Type> t;

  char userInput; 
  std::cout << "What type do you want? (A or B): ";
  std::cin >> userInput;
  if ( userInput == 'A' )
    t = std::make_unique<AType>();
  else if ( userInput == 'B' )
    t = std::make_unique<BType>();
  else
    std::cout << "Invalid input" << "\n";

  printType( *t );
  return 0;
}
