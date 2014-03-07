#include <iostream>
#include <exception>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Singleton {
public:
  static Singleton& Instance() {
    static Singleton instance;
    if (destroyed) {
      throw runtime_error("Dead Reference");
    }
    return instance;
  }
private:
  Singleton () = default;
  Singleton (const Singleton&) = delete;
  Singleton operator= (const Singleton&) = delete;
  ~Singleton (){
    destroyed = true;
  }

  static bool destroyed;
  // More Functions and Data
};
bool Singleton::destroyed = false;


int main(int argc, const char *argv[])
{
  return 0;
}
