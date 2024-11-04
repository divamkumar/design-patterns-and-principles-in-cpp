#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>
#include <random>
#include <stack>
#include <string>
#include <thread>

class Singleton
{
private:
  static std::unique_ptr< Singleton > instance;
  static std::mutex mtx;
  Singleton()
  {
    std::random_device rd;
    std::mt19937 g( rd() );
    std::shuffle( scrabbleLetters.begin(), scrabbleLetters.end(), g );
    scrabbleStack = std::stack< std::string, std::vector< std::string > >( scrabbleLetters );
  }

  std::vector<std::string> scrabbleLetters = {
        "a", "a", "a", "a", "a", "a", "a", "a", "a",
        "b", "b", "c", "c", "d", "d", "d", "d", "e", "e", "e", "e", "e",
        "e", "e", "e", "e", "e", "e", "e", "f", "f", "g", "g", "g", "h",
        "h", "i", "i", "i", "i", "i", "i", "i", "i", "i", "j", "k", "l",
        "l", "l", "l", "m", "m", "n", "n", "n", "n", "n", "n", "o", "o",
        "o", "o", "o", "o", "o", "o", "p", "p", "q", "r", "r", "r", "r",
        "r", "r", "s", "s", "s", "s", "t", "t", "t", "t", "t", "t", "u",
        "u", "u", "u", "v", "v", "w", "w", "x", "y", "y", "z"
  };

  std::stack<std::string, std::vector<std::string>> scrabbleStack;

public:
  Singleton( const Singleton& other ) = delete;
  Singleton& operator=( const Singleton& right ) = delete;

  static Singleton* getInstance()
  {
    if ( instance == nullptr )
    {
      std::lock_guard<std::mutex> lock( mtx );
      if ( instance == nullptr )
      {
        instance.reset( new Singleton() );
        std::cout << "Singleton instance created at address: " << instance.get() << std::endl;
      }
    }
    std::cout << "Accessing singleton instance at address: " << instance.get() << std::endl;
    return instance.get();
  }

  std::vector< std::string > getTiles( std::uint32_t numTiles )
  {
    std::vector< std::string > userTiles;
    for ( std::uint32_t i = 0; i < numTiles && !scrabbleStack.empty(); i++ )
    {
      userTiles.push_back( scrabbleStack.top() );
      scrabbleStack.pop();
    }
    return userTiles;
  }
};

std::unique_ptr< Singleton > Singleton::instance = nullptr;
std::mutex Singleton::mtx;

void playerDrawTiles( const std::string& playerName, std::uint32_t numTiles )
{
  Singleton* gameInstance = Singleton::getInstance();
  std::vector< std::string > tiles = gameInstance->getTiles( numTiles );
  std::cout << playerName << " drew tiles: ";
  for ( const std::string& tile : tiles )
    std::cout << tile << " ";
  std::cout << std::endl;
}

int main()
{
  std::thread player1( playerDrawTiles, "Player 1", 7 );
  std::thread player2( playerDrawTiles, "Player 2", 7 );
  player1.join();
  player2.join();
  return 0;
}
