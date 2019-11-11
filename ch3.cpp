#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
  cout << "Please enter your name : ";
  string name;
  cin >> name;
  cout << "Please enter your grades, one line at a time. Terminate with EOF/^d/(ctrl+d)" << endl;
  vector<double> grades;
  double total;
  double grade;
  while (cin >> grade) {
    grades.push_back(grade);
    total += grade;
  }
  typedef vector<double>::size_type vector_sz;
  vector_sz size = grades.size();
  if (size == 0) {
    cout << "You did not enter any grades. Please try again." << endl;
    return 1;
  }
  sort(grades.begin(), grades.end());
  double median = size % 2 == 0 ? (grades[size/2] + grades[size/2 + 1])/ 2 : grades[size/2];
  streamsize prec = cout.precision();
  cout << "Grade Statistics" << endl;
  cout << "No. of grade entries: " << grades.size() << endl;
  cout << "Median: " << median << endl;
  cout << "Average: " << total/size << endl;
  setprecision(prec);
  return 0;
}
