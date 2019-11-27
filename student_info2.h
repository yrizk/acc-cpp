#ifndef GUARD_student_info_h
#define GUARD_student_info_h

class student_info {
  public:
    std::string name() const { return n; }
    bool valid() const { return !hw.empty(); }
    double grade() const;
    std::istream& read(std::istream&);
}

#endif
