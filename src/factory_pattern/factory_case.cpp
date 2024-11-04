#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

class EnemyShip
{
private:
  std::string name;
  std::uint32_t amtDamage;

public:
  EnemyShip() {}
  EnemyShip( const EnemyShip& other )
    : name( other.name),
      amtDamage( other.amtDamage )
  {}

  EnemyShip& operator=( const EnemyShip& right )
  {
    if ( this != &right )
    {
      name = right.name;
      amtDamage = right.amtDamage;
    }
    return *this;
  }

  // Virtual destructor so that in the case of EnemyShip* e = new UfoEnemyShip(),
  // UfoEnemyShip's destructor can still be called through EnemyShip*
  virtual ~EnemyShip() = default;

  const std::string& getName() const
  {
    return name;
  }

  void setName( const std::string& name )
  {
    this->name = name;
  }

  std::uint32_t getDamage() const
  {
    return amtDamage;
  }

  void setDamage( std::uint32_t amtDamage )
  {
    this->amtDamage = amtDamage;
  }

  void followHeroShip()
  {
    std::cout << getName() << " is following the hero\n";
  }

  void displayEnemyShip()
  {
    std::cout << getName() << " is on the screen\n";
  }

  void enemyShipShoots()
  {
    std::cout << getName() << " attacks and does damage " << getDamage() << "\n";
  }
};

// Make sure to inherit publicly so that (1) true polymorphism can be acheived
// and (2) private inheritance is the default, preventing true polymorphism
//
// Private inheritance is not true polymorphism, but the child class can explicitly
// call the base class's methods to perform polymorphism "explicitly" and hide
// the base class interface, in a way
class UfoEnemyShip : public EnemyShip
{
public:
  UfoEnemyShip()
  {
    setName( "UFO Enemy Ship" );
    setDamage( 20 );
  }
};

class RocketEnemyShip : public EnemyShip
{
public:
  RocketEnemyShip()
  {
    setName( "Rocket Enemy Ship" );
    setDamage( 10 );
  }
};

// Make sure to pass by reference or pointer to prevent
// object slicing, which is when a child class is passed 
// by value or assigned to a base class object, and the 
// derived attributes are "sliced off, leaving only the 
// base class part
// This can cause bugs and memory issues
static void doStuffEnemy( EnemyShip& anEnemyShip )
{
  anEnemyShip.displayEnemyShip();
  anEnemyShip.followHeroShip();
  anEnemyShip.enemyShipShoots();
}

int main()
{
  std::unique_ptr< EnemyShip > theEnemy;
  std::string enemyShipOption;
  std::cout << "What type of ship? (U/R): ";
  std::cin >> enemyShipOption;

  // These if statements are bad because alhtough it's dynamic,
  // it doesn't close the implementation from being modified 
  // (someone can just change the if statements and mess the program)
  if ( enemyShipOption == "U" )
    theEnemy = std::make_unique< UfoEnemyShip >();
  else if ( enemyShipOption == "R" )
    theEnemy = std::make_unique< RocketEnemyShip >();
  else
  {
    std::cout << "Wrong input" << std::endl;
    return 0;
  }

  doStuffEnemy( *theEnemy );
  return 0;
}
