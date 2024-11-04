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

class BigUfoEnemyShip : public EnemyShip
{
public:
  BigUfoEnemyShip()
  {
    setName( "Big UFO Enemy Ship" );
    setDamage( 40 );
  }
};

class EnemyShipFactory
{
public:
  std::unique_ptr< EnemyShip > makeEnemyShip( std::string newShipType )
  {
    std::unique_ptr< EnemyShip > newEnemy = nullptr;
    if ( newShipType == "U" )
      return std::make_unique< UfoEnemyShip >();
    else if ( newShipType == "R" )
      return std::make_unique< RocketEnemyShip >();
    else if ( newShipType == "B" )
      return std::make_unique< BigUfoEnemyShip >();
    else
    {
      std::cout << "Wrong input" << std::endl;
      return nullptr;
    }
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
  EnemyShipFactory shipFactory;
  std::unique_ptr< EnemyShip > theEnemy;
  std::string enemyShipOption;

  std::cout << "What type of ship? (U/R/B): ";
  std::cin >> enemyShipOption;

  theEnemy = shipFactory.makeEnemyShip( enemyShipOption );

  if ( theEnemy != nullptr )
    doStuffEnemy( *theEnemy );
  else
    std::cout << "Enter U, R, or B next time";

  return 0;
}
