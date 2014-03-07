#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

class Singleton {
public:
  static Singleton& Instance() {
    static Singleton instance;
    return instance;
  }
private:
  Singleton () = default;
  Singleton (const Singleton&) = delete;
  Singleton operator= (const Singleton&) = delete;
  ~Singleton () = default;

  // More Functions and Data
};


int main(int argc, const char *argv[])
{
  return 0;
}
