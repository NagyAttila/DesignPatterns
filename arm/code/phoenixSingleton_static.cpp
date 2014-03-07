#include <iostream>
#include <exception>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Singleton {
public:
  static Singleton& getInstance() {
    if (destroyed) {
      new(instance) Singleton;
      atexit(KillSingleton);
    }

    return *instance;
  }
  static void KillSingleton(void) {
    instance->~Singleton();
  }
  void print(){cout<<"out";}
private:
  Singleton () {
    destroyed = false;
  }
  Singleton (const Singleton&) = delete;
  Singleton operator= (const Singleton&) = delete;
  ~Singleton () {
    destroyed = true;
  }

  static bool destroyed;
  static Singleton* instance;
  // More Functions and Data
};
bool Singleton::destroyed = false;
Singleton* Singleton::instance = new Singleton;


int main(int argc, const char *argv[])
{
  Singleton::getInstance().print();
  return 0;
}
