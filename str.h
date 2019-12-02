#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cctype>

using std::vector;

class Str {
  public:
    typedef vector<char>::size_type size_type;

    friend std::istream& operator>>(std::istream& is, Str& s) {
      s.data.clear();

      char c;
      while (is.get(c) && std::isspace(c))
        ;

      if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        if (is)
          is.unget();
      }
      return is;
    }

    // default ctor, makes an empty string
    Str() {}

    Str(size_type n, char c): data(n, c) {}

    Str(const char* cp) { std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));} 

    template <class In> Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    size_type size() const { return data.size(); }

    Str& operator+=(const Str& other) {
      std::copy(other.data.begin(), other.data.end(), std::back_inserter(data));
      return *this;
    }

    char* c_str() {
      char* result = new char[size() + 1];
      for (size_type i = 0; i != size(); i++) {
        result[i] = data[i];
      }
      result[size() + 1] = '\0';
      return result;
    }

  private:
    vector<char> data;
};

std::ostream& operator<<(std::ostream& os, Str& s) {
  for (Str::size_type i = 0; i != s.size(); i++) 
    os << s[i];
  return os;
}

Str operator+(const Str& s, const Str& t) {
  Str r = s;
  r += t;
  return r;
}
