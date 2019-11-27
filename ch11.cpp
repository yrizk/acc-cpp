#include "vec.h"
#include <string>
#include <iostream>
// implement the heavier declerations done in the header file.
template<class T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
  if (&rhs != this) {
    uncreate();
    create(rhs.begin(), rhs.end());
  }
  return *this;
}

int main() {
  // test the vec implementation.
  std::string s; 
  Vec<std::string> v;
  while(getline(std::cin, s)) { 
    v.push_back(s);
  }
  std::cout << v.size() << std::endl;
  for (Vec<std::string>::size_type i = 0; i != v.size() ; i++) 
    std::cout << v[i] << std::endl;
  return 0;
}
