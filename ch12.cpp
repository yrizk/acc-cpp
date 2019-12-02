#include "str.h"
#include <iostream>
int main() {
  Str s;
  std::cin >> s;
  std::cout << s << std::endl;
  std::cout << s.c_str() << std::endl;
  return 0;
}
