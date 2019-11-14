#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;

typedef string::size_type string_size;
typedef vector<string>::size_type vector_size;

vector<string> split(const string& line) {
  vector<string> ret;
  string_size i = 0;
  while (i != line.size()) {
    // let's ignore leading spaces
    while (i != line.size() && isspace(line[i])) {
      i++;
    }
    string_size j = i;
    while (j != line.size() && !isspace(line[j])) {
      j++;
    }
    if (i != j) {
      ret.push_back(line.substr(i, j-i));
      i = j;
    }
  }
  return ret;
}

bool compare(const vector<string>& x, const vector<string>& y) {
  return x[0] < y[0];
}

vector<vector<string>> rotate(vector<string> words) {
  vector<vector<string>> ret; 
  ret.push_back(words);
  for (vector_size i = 0; i != words.size() - 1; i++) {
    vector<string> one_rot;
    vector_size j = i;
    vector_size rotations_completed = 0;
    while (rotations_completed != words.size()) {
      j++;
      if (j == words.size()) j = 0;
      one_rot.push_back(words[j]);
      rotations_completed++;
    }
    ret.push_back(one_rot);
  }
  return ret;
}

void print(const vector<vector<string>>& rotations) {
  for (vector_size i = 0; i != rotations.size(); i++) {
    for (vector_size j = 0; j != rotations[i].size(); j++) {
      cout << rotations[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  string s;
  cout << "start" << endl;
  while (getline(cin, s)) {
    vector<string> words = split(s);
    vector<vector<string>> rotations = rotate(words);
    sort(rotations.begin(), rotations.end(), compare);
    print(rotations);
  }
  return 0;
}
