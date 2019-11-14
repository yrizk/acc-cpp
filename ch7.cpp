#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using std::istream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::find_if;

// produces clarity in the compiler as to which version of the STL isspace() 
// is intended.
bool space(char c) {
  return isspace(c);
}

bool not_space(char c) {
  return !isspace(c);
}

vector<string> split(const string& line) {
  typedef string::const_iterator iter;
  vector<string> answer;
  iter i = line.begin();
  while (i != line.end()) {
    // again, let's ignore the leading spaces.
    // this function will move to one past the predicate function.
    i = find_if(i, line.end(), not_space);
    // again, this will move one past the predicate and land on a non-space character.
    iter j = find_if(i, line.end(), space);
    if (i != line.end())  {
      answer.push_back(string(i, j));
    }
    i = j;
  }
  return answer;
}


map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split) {
  typedef vector<string>::const_iterator iter;
  int line_number = 0;
  string s;
  map<string, vector<int> > result;
  while (getline(in, s)) {
    line_number++;
    vector<string> words = find_words(s);
    for(iter it = words.begin(); it != words.end(); it++) {
      result[*it].push_back(line_number);
    }
  }
  return result;
}

void print(const vector<string>& rotations) {
  for (vector<string>::size_type j = 0; j != rotations.size(); j++) {
    cout << rotations[j] << endl; 
  }
  cout << endl;
}

void print(const map<string, vector<int> > ds) {
  for (map<string, vector<int> >::const_iterator it = ds.begin(); it != ds.end(); it++)  {
    cout << "Word: " << it->first << " occurs on line(s):" << endl;
    for (vector<int>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      cout << "\t " << *it2 << endl;
    }
  }
}

int main() {
  print(xref(cin));
  return 0;
}
