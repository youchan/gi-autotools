#include <iostream>
#include "greeting.hpp"

void Hello::Greeting::message(const char * name) {
  std::cout << "Hello, " << name << std::endl;
}
