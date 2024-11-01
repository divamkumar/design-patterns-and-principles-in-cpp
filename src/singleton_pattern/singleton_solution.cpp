#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
private:
  static std::unique_ptr<Singleton> instance;
  static std::mutex mtx;
  Singleton() {}

public:
  Singleton( const Singleton& other ) = delete;
  Singleton& operator=( const Singleton& right ) = delete;

  static Singleton* getInstance()
  {
    if ( instance == nullptr )
    {
      std::lock_guard<std::mutex> lock( mtx );
      if ( instance == nullptr )
        instance.reset( new Singleton() );
    }
    return instance.get();
  }
};

std::unique_ptr<Singleton> Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main()
{
  return 0;
}
