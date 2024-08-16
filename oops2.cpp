#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
 
class Student {
private:
    std::string name;
    int rollNumber;
    std::string className;
    char division;
    std::string dateOfBirth;
    std::string bloodGroup;
    std::string contactAddress;
    std::string telephoneNumber;
    std::string drivingLicenseNumber;
 
public:
    // Default constructor
    Student() 
        : rollNumber(0), division('A') {}
 
    // Parameterized constructor
    Student(std::string name, int rollNumber, std::string className, char division, std::string dateOfBirth,
            std::string bloodGroup, std::string contactAddress, std::string telephoneNumber, std::string drivingLicenseNumber) 
        : name(name), rollNumber(rollNumber), className(className), division(division), dateOfBirth(dateOfBirth),
          bloodGroup(bloodGroup), contactAddress(contactAddress), telephoneNumber(telephoneNumber), drivingLicenseNumber(drivingLicenseNumber) {}
 
    // Copy constructor
    Student(const Student &other)
        : name(other.name), rollNumber(other.rollNumber), className(other.className), division(other.division),
          dateOfBirth(other.dateOfBirth), bloodGroup(other.bloodGroup), contactAddress(other.contactAddress),
          telephoneNumber(other.telephoneNumber), drivingLicenseNumber(other.drivingLicenseNumber) {}
 
    // Destructor
    ~Student() {
        std::cout << "Destructor called for student: " << name << std::endl;
    }
 
    // Friend class declaration
    friend class StudentDatabase;
 
    // Inline member functions
    inline void display() const {
        std::cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << className << "\nDivision: " << division 
                  << "\nDate of Birth: " << dateOfBirth << "\nBlood Group: " << bloodGroup << "\nContact Address: " << contactAddress 
                  << "\nTelephone Number: " << telephoneNumber << "\nDriving License Number: " << drivingLicenseNumber << std::endl;
    }
};
 
class StudentDatabase {
private:
    std::vector<Student*> students;
    static int studentCount;
 
public:
    // Constructor
    StudentDatabase() {}
 
    // Destructor
    ~StudentDatabase() {
        for (Student* student : students) {
            delete student;
        }
    }
 
    // Static member function
    static int getStudentCount() {
        return studentCount;
    }
 
    // Function to add a student
    void addStudent(std::string name, int rollNumber, std::string className, char division, std::string dateOfBirth,
                    std::string bloodGroup, std::string contactAddress, std::string telephoneNumber, std::string drivingLicenseNumber) {
        try {
            Student* newStudent = new Student(name, rollNumber, className, division, dateOfBirth, bloodGroup, contactAddress, telephoneNumber, drivingLicenseNumber);
            students.push_back(newStudent);
            studentCount++;
        } catch (const std::bad_alloc &e) {
            std::cerr << "Allocation failed: " << e.what() << std::endl;
        }
    }
 
    // Function to display all students
    void displayAllStudents() const {
        for (const Student* student : students) {
            student->display();
            std::cout << std::endl;
        }
    }
};
 
// Initialize static member
int StudentDatabase::studentCount = 0;
 
int main() {
    StudentDatabase db;
 
    db.addStudent("Ayush", 1, "SE Comp", 'B', "2005-12-25", "AB+", "Virgin Island", "6969696969", "Not Permitted(have porche)");
    db.addStudent("Daksh", 2, "Se Comp", 'B', "1995-10-12", "B+", "Wednesday peth", "4204204200", "No Car(Broke)");
 
    std::cout << "Total number of students: " << StudentDatabase::getStudentCount() << std::endl;
 
    db.displayAllStudents();
 
    return 0;
}
