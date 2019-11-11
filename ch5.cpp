#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

string::size_type width(const vector<string>& words) {
  string::size_type maxlen = 0;
  for (string::size_type i = 0; i < words.size(); i++) {
    maxlen = max(maxlen, words[i].size());
  }
  return maxlen;
}


vector<string> frame(vector<string> words) {
  vector<string> result;
  string::size_type w = width(words);
  string border(w + 4, '*');
  result.push_back(border);
  for (string::size_type i = 0; i < words.size(); i++) {
    string test = "* " + words[i] + string(w - words[i].size(), ' ') + " *";
    result.push_back(test);
    cout << test << endl;
  }
  result.push_back(border);
  return result;
}


int main() {
  cout << "start" << endl;
  vector<string> w;
  string x;
  while(cin >> x) {
    w.push_back(x);
  }
  vector<string> result = frame(w);
  return 0;
}
