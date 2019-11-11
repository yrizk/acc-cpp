#ifndef GUARD_student_info_h
#define GUARD_student_info_h

struct student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};
bool compare(const student_info&, const student_info&);
std::istream& read(std::istream&, student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif
