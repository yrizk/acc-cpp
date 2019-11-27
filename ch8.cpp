#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <list>
#include <iterator>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::isspace;
using std::ostream;
using std::ostream_iterator;


bool space(char c) { return isspace(c); } 

bool not_space(char c) { return !isspace(c); }

template <class Out>
void split(const string& str, Out os) {
  typedef string::const_iterator iter;
  iter i = str.begin();
  while (i != str.end()) {
    // move past the leading spaces
    i = find_if(i, str.end(), not_space);
    iter j = find_if(i, str.end(), space);
    if (i!= str.end()) {
      *os++= string(i,j);
    }
    i = j;
  }
}

template <class In, class Out>
Out copy(In begin, In end, Out dest) {
  while (begin != end) {
    *dest++=*begin++;
  }
  return dest;
}

template<class For, class X>
void replace(For beg, For end, const X& x1, const X& x2) {
  while (beg != end)  {
    if (*beg == x1) 
      *beg=x2;
    ++beg;
  }
}

template<class In, class X>
In find(In begin, In end, const X& x) {
  while (begin != end) {
    if (*begin = x)
      return begin;
    begin++;
  }
  return begin;
}

int main(){
  string s; 
  cout << "go" << endl;
  list<string> word_list;
  while (getline(cin, s)) {
   split(s, back_inserter(word_list)); 
   copy(word_list.begin(), word_list.end(), ostream_iterator<string>(cout, "\n"));
    // split(s, ostream_iterator<string>(cout, "\n"));
  }
  cout << "done" << endl;
  return 0;
}
