#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class Student
{
private:
  string id;
  string lname;
  string fname;
  int age;
  int phone;
public:
  void setId(string);
  void setLname(string);
  void setFname(string);
  void setAge(int age);
  void setPhone(int);
  string getId();
  string getLname();
  string getFname();
  int getAge();
  int getPhone();
};
//Student setter methods
void Student::setId(string student_id)
{
  id = student_id;
}
void Student::setLname(string last_name)
{
  lname = last_name;
}
void Student::setFname(string first_name)
{
  fname = first_name;
}
void Student::setAge(int student_age)
{
  age = student_age;
}
void Student::setPhone(int student_phone)
{
  phone = student_phone;
}
//Student getter methods
string Student::getId()
{
  return id;
}
string Student::getLname()
{
  return lname;
}
string Student::getFname()
{
  return fname;
}
int Student::getAge()
{
  return age;
}
int Student::getPhone()
{
  return phone;
}

int main()
{
  Student student_array[MAX_SIZE];
  int index;
  string discard;
  ifstream Studentfile;
  //populate student_array
  Studentfile.open("Library_System_Management_Record_Book.txt", ios::in);
  if (Studentfile.fail())
  {
    cout << "File was not found\n";
    system("PAUSE");
    exit(1);
  }
  getline(Studentfile, discard);
  index = 0;
  string id, lname, fname;
  int age, phone;

  while (index  < MAX_SIZE && Studentfile >> id >> lname >> fname >> age >> phone)
  {
    student_array[index].setId(id);
    student_array[index].setLname(lname);
    student_array[index].setFname(fname);
    student_array[index].setAge(age);
    student_array[index].setPhone(phone);
    index++;
  }
  cout << "Number of students read: " << index << "\n\n";
  // Studentfile.close(); not needed
  system("PAUSE");
  return 0;
}