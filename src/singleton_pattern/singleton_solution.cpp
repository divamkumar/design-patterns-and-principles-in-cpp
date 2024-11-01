#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
private:
  static Singleton std::unique_ptr<Singleton> instance;
  static mutex mtx;
  Singleton() {}

public:
  Singleton( const Singleton& other ) = delete;

  static std::unique_ptr<Singleton> getInstance()
  {
    if ( instance == nullptr )
    {
      std::lock_guard<mutex> lock( mtx );
      if ( instance == nullptr )
        instance = new Singleton();
    }
    return instance;
  }

};
