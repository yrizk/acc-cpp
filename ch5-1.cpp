#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

vector<string> split(string line) {
  vector<string> result;
  string::size_type i, j = 0;
  while (j != line.size()) {
    while(i != line.size() && !isspace(line[i])) {
      i++;
    }
    cout << "found space at index " << i << endl;
    result.push_back(line.substr(j, i - j));
    j = i + 1;
  }
  return result;
}

int main() {
  string s;
  while (getline(cin, s)) {
    vector<string> words = split(s);
    for (vector<string>::size_type i = 0; i < words.size(); ++i) cout << words[i] << endl;
  }
  return 0;
}
