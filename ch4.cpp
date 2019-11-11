#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include "student_info.h"
#include "median.h"

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::sort;
using std::istream;
using std::max;
using std::streamsize;
using std::domain_error;
using std::setprecision;
using std::string;

typedef vector<double>::size_type vec_sz;

double median(vector<double> grades) {
  vec_sz size = grades.size();
  if (size == 0) {
    throw domain_error("median of empty vector");
  }
  sort(grades.begin(), grades.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (grades[mid - 1] + grades[mid]) / 2 : grades[mid];
}

double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0) {
    throw domain_error("No homework entered for student");
  }
  return grade(midterm, final, median(hw));
}

double grade(const student_info& s) {
  return grade(s.midterm, s.final, s.homework); 
}

istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    hw.clear();
    double x;
    while (in >> x) {
      hw.push_back(x);
    }
    in.clear();
  }
  return in;
}

istream& read(istream& is, student_info& s) {
  is >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework);
  return is;
}

bool compare(const student_info& l, const student_info& r) {
  return l.name < r.name;
}

int main() {
  cout << "Please enter your name, final , midterm and hw grades." << endl;
  vector<student_info> students;
  student_info record;
  string::size_type maxlen = 0;
  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }
  cout << "processed "  << students.size() << " students "  << endl;
  sort(students.begin(), students.end(), compare);

  for (vector<student_info>::size_type i = 0; i != students.size(); i++) {
    cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << "Your final grade is " << setprecision(3) << final_grade << setprecision(prec) << endl;
    } catch(domain_error e) {
      cout << e.what();
      cout << endl << "you must enter your grades. Please try again. " << endl;
    }
    cout << endl;
  }
  return 0;
}
