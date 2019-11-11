#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main() {
  cout << "Please Enter Your Name: ";
  string name; 
  cin >> name;

  // number of rows above and below our name.
  const int rows = 2;
  const int totalRows = rows * 2 + 3;

  const string greeting = "Hello, " + name +  " !";
  const string::size_type totalCols = greeting.size() + 2 + 2;
  const string spaces(totalCols - 2, ' '); // every 'empty' line
  const string stars(totalCols, '*'); // first and last line

  cout << endl;
  for (int r = 0; r < totalRows; r++) {
    if (r == 0 || r == totalRows - 1) { 
      cout << stars << endl;
    } else if (r == totalRows / 2)  {
      cout << "* " + greeting + " *" << endl;
    } else {
      cout << "*" + spaces + "*" << endl;
    }
  }
  return 0;
}
