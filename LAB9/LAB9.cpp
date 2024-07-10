#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*  map<key,value> key is the label of the type, and value is the corresponding content of the key;
we can use map[key_name] = value, to assign the value to the key;
we also can use the map.first to get the key, and map.second to get the value;

if we would like to check all the keys and values in the map, we can use the for loop to iterate the map, for(auto const& map_name:map){};
this also can apply on the vector , for(auto const& vector_name:vector){};

vector<type> is the dynamic array that do not have the fixed size, we can use vector.push_back(value) to add the value to the vector;

*/

using namespace std;
// Too hard to do this lab, I am referring the solutionfrom TA code.
// I will try to understand the code and write the code by myself.
class Student {
    public:
        Student(string _input_file,string _output_file):input_file{_input_file},output_file{_output_file}{}
        void ReadstudentInfo();
        void PrintstudentInfo();
    private:
        int student_num,subject_num;
        string input_file,output_file;
        map<string, vector<string>> student_map;

};

void Student::ReadstudentInfo(){
    ifstream ifs(input_file);
    int class_num;
    string student_name,subject_name;

    if(!ifs){
        cout << "Error: cannot open file" << input_file << endl;
    }

    ifs >> student_num >> subject_num;
    for(int i = 0;i < subject_num;++i){
        ifs >> subject_name;
        student_map[subject_name] = vector<string>();//create a vector for each subject to store student names
    }
    ifs.ignore();//ignore the newline character
    for(int i = 0;i < student_num;++i){
        ifs >> student_name >> class_num;
        for(int j= 0;j < class_num;++j){
            ifs >> subject_name;
            student_map[subject_name].push_back(student_name);//check the subject name and push the student name into the vector
        }
    }
    ifs.close();//close the file
}   

void Student::PrintstudentInfo(){
    ofstream ofs(output_file);
    if(!ofs){
        cout << "Error: cannot open file" << output_file << endl;//check if the file is open
    }

    for(auto const& map_name:student_map){
        const string subject_name = map_name.first;//use constant reference to prevent the value from being changed
        const vector<string> student_name = map_name.second;
        ofs << endl << "Class: " << subject_name << endl;
        for(auto const &name:student_name){
            ofs << name << " ";
        }
    }
    ofs.close();//close the file
}

int main(int argc, char **argv){
    if(argc != 3){
        cout << "Input wrong parameters" << endl;
    }
    string input_file,output_file;
    input_file = argv[1];
    output_file = argv[2];
    Student student(input_file,output_file);
    student.ReadstudentInfo();
    student.PrintstudentInfo();
    return 0;
}