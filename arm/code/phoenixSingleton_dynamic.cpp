#include <iostream>
#include <exception>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Singleton {
public:
  static Singleton& getInstance() {
    static Singleton instance;
    if (destroyed) {
      new(pInstance) Singleton;
      atexit(KillSingleton);
    }
    if (nullptr == pInstance) {
      pInstance = &instance;
    }
    return *pInstance;
  }
  static void KillSingleton(void) {
    pInstance->~Singleton();
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
    pInstance = nullptr;
  }

  static bool destroyed;
  static Singleton* pInstance;
  // More Functions and Data
};
bool Singleton::destroyed = false;
Singleton* Singleton::pInstance = nullptr;


int main(int argc, const char *argv[])
{
  Singleton::getInstance().print();
  return 0;
}
