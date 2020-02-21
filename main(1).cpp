//============================================================================
// Name        : tutoringProject.cpp
// Author      : Andy Bryant and Suraj Patel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <string>
#include <ifstream>
using namespace std;

    
class Exam {
private:
	bool _completed; // true means pass, false means fail, intialized as fail/incomplete
public:
    Exam(){ _completed = false };
    
    void setCompleted(bool passed) { // sets whether exam has been passed or failed
        _completed = passed;
    }
    bool getPassFail() { // fetches if exam has been passed or failed/not complete
        return _completed;
    }
};

class Tutorial {
private:
    string _tName;
    string _subject;
	bool _completed;  // true means pass, false means fail, initialized as false
    int _minViewTime;
	int _maxViewTime;
	int _timeTaken; // time taken by student to complete tutorial (passed in by client-side program)
	vector<Exam> _exams;
public:
    Tutorial(){}; // default constructor
    Tutorial(string t, string s, bool c, int min, int max, int t) { // n-arg constructor
        _tName = string t;
        _subject = s;
        _bool = b;
        _minViewTime = min;
        _maxViewTime = max;
        _timeTaken = t;
    }
    
    string setName(string name){
        _tName = name;
    }
    string getName(){
        return _tName;   
    }
    string getSubject(){      //accessors and mutators for subject, completed, min and max view time, and time taken.
        return _subject;
    }
    bool getCompleted(){
        return _completed;
    }
    int getMinViewTime(){
        return _minViewTime;
    }
    int getMaxViewTime(){
        return _maxViewTime;
    }
    int getTimeTaken(){
        return _timeTaken;
    }
    void setCompleted(bool b){
        _completed = b;
    }
    void setMinViewTime(int minimum){
        _minViewTime = minimum;
    }
    void setMaxViewTime(bool maximum){
        _maxViewTime = maximum;
    }
    void setTimeTaken(int timeTaken){
        _timeTaken = timeTaken;
    }
    void setSubject(string s){
        _subject = s;
    }
    void addExam(Exam test) { // add and remove exam from tutorial. 
        _exams.push_back(test);
    }
    void removeExam(Exam test) {
        _exams.erase(test);
    }
    void checkExams() {
        bool allPassed = true; // flag to be raised if there is at least one exam not completed
        for(int i = 0; i < _exams.length(); i++) {
            if(_exams[i]._completed == false) {
                allPassed = false; // raise flag, there is at least one exam not completed
            }
        }
        if(allPassed == true) { // if all exams are completed the tutorial is completed
            this._completed = true;
        }
    }
     bool checkWatched() { // checks to see if student watched a tutorial
        bool passingTime = false; // variable to keep track if the tutorial was watched
            if((_minViewTime > _timeTaken) && (_maxViewTime < _timeTaken)){ // student needs to still complete the tutorial and/or watch it again
                passingTime = true;
            }
        return passingTime;
    }
};

class Subject {
private:
    string _sName;
	vector<Tutorial> _tutorials;
public:
    Subject(){}; // default constructor
    
    Subject(string name, vector<Tutorial> videos) { // n-arg constructor
        _tutorials = videos;                            
        _sName = name;
    } 
    Tutorial getTutorial(int input) {
        return _tutorials.
    }
};


class StudyAreas {
private:
	vector<Subject> _subjects;
public:
    StudyAreas() {} // default constructor
    
    void addSubject(Subject topic) { // add subject to array of study areas
        _subjects.push_back(topic);
    }
    void removeSubject(Subject topic) { // remove subject from array of study areas
        _subjects.erase(topic);
    }
    Subject returnSubject(int input) {
        return _subjects[input];
    }
    
};
class Student {
private:
    string _name;
    vector<Tutorial> _studentTutorials; // vector of tutorials specified for Student
    vector<Subject> _studentSubjects;   // vector of subjects specified for Student
public:
    Student(){}; // default constructor
    Student(string s) { // n-arg constructor
        _name = s;
    }
    
    string getStudentName(){
        return _name;
    }
    void setStudentName(string studentName) {   // accessors and mutators for Student name.
        _name = studentName;
    }
    void addTutorial(Tutorial studenttutorial) {    // add and remove for tutorials.
        _studentTutorials.push_back(studenttutorial);
    }
    void removeTutorial(Tutorial studenttutorial) {
        _studentTutorials.erase(studenttutorial);
    }
    void addStudentSubject(Subject studentSubject) {    // add and remove for subjects
        _studentSubjects.push_back(studentSubject);
    }
    void removeStudentSubject(Subject studentSubject) {
        _studentSubjects.erase(studentSubject);
    }
    int StudentSubjectLength() {
       return _studentSubjects.length();
    }
};
    
class StudentList {
private:
    vector<Student> _tutees;    // all students currently enrolled in the tutoring program - passed in using data file
public:
    StudentList(){};
    
    void addTutee(Student tutee){   // add and remove students alongside modify student name.
        _tutees.push_back(tutee);
    }
    void removeTutee(Student tutee){
        _tutees.erase(tutee);
    }
    void changeStudentName(string newName) {
        _tutess.Student.setStudentName(newName);
    }
    void addStudentTutorial(Tutorial newTutorial) { // add and remove tutorial pertaining to individual students
        _tutees.Student.addTutorial(newTutorial)
    }
    void removeStudentTutorial(Tutorial newTutorial) {
        _tutees.Student.removeTutorial(newTutorial);
    }
    void addStudentExam(Exam test){                     // add and remove exams pertaining to individual students
        tutees.Student._studentTutorials.addExam(test);
    }
    void removeStudentExam(Exam test){
        tutees.Student._studentTutorials.removeExam(test);
    }
};
    
StudyAreas fullLoadPopulate() {// full load of all possible subjects, tutorials, and exams that can be used to build new students
    ifstream inFile;
    inFile.open("fullLoad.txt"); // opens the file containing all the information
    
    if(!inFile) { // file does not exist
        cout << "File does not exist!";
        exit(-1);
    }
    
    StudyAreas fullLoad; // create an object to hold all possible subjects, tutorials, and exams that can be used to build new students
    
    while(!inFile.eof()) {
        string temp = getline(inFile, temp); // creates a string to temporarily hold the line of a file, to send/store elsewhere
        if(temp == "Math" || temp == "History" || temp == "Language" || temp == "Science") { // line is a subject
            Subject tempSubject(temp);
            fullLoad.addSubject(tempSubject); // creates a subject object and adds it to possible study areas
        }
        
        if(temp.at(0) == 'm') {// math tutorial; math tutorials start with lowercase m in the loaded file; add tutorial to existing subjects
            string tempName = temp;
            string maxTime = getline(inFile, maxTime)
            Tutorial tempTutorial("Math", )
        }
    }
}
StudentList loadEnrolledStudents() { // loads in all currently enrolled students, and their subjects, tutorials, and exams into objects
    ifstream inFile;
    inFile.open("currentlyEnrolled"); // opens the file containing all the information
    
    if(!inFile) { // file does not exist
        cout << "File does not exist!";
        exit(-1);
    }
    StudentList currentlyEnrolled; // instantiates an object to hold currently enrolled students
}

    
    
void writeToFile(fullLoad) {
    ofstream file ("Output.txt");
    if (file.is_open()) {
        for(i= 0 ; i<StudentList._tutees.length()-1< i++ ) {
            file << StudentList._tutees[i].getStudentName() << endl;
            if(i < StudentList._tutees[i].StudentSubjectLength()-1){
                file << StudentList._tutees[i].returnsubject[i] << endl;
            }
            if(i < StudentList._tutees[i].)
            file << StudentList._tutees[i].StudentSubjectLength() << endl;
            }
        }
    }
    
    

int main() {
	cout << "Hello World" << endl; // prints Hello World
	return 0;
};




