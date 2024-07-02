/*
Write a porgram that have three fuction:
When you input -1 :the program end
When you input 0 :the program will replace the substring in the test array into graph array
When you input 1 : the program will replace the substring in the graph array into test array

str.replace:str.replace(string name,the length of the string that will be replaced,the replace string)
str.find():is to find the target string in our input
*/
// ------------- include header file you will use ------------- //
#include<iostream>
#include<string>

// ------------------------------------------------------------ //

using namespace std;

int main(){
	int mode;
	bool end = false;
	string str;
	string text[5], graph[5];
	text[0] = "(happy)";		graph[0] = "^w^";
	text[1] = "(heart)";		graph[1] = "<3";
	text[2] = "(confused)";		graph[2] = "?_?";
	text[3] = "(kiss)";			graph[3] = "-3-";
	text[4] = "(speechless)";	graph[4] = "= =";
	size_t found;

	// ------------- Coding in here ------------- //
    do
    {
        cout << " Please input the mode: ";
        cin >> mode;
        switch(mode){
            case -1:
                cout << "Program ends" << endl;
                break;
            case 0:
                cout << "Input: ";
                cin.ignore(100, '\n');//the progra, that must be added if we use the getline
                getline(cin,str);
                for(int i = 0;i < 5;++i){
                    found = str.find(text[i]);//str.find if do not find the fitting position will return npos
                    while(found != string::npos){//if find anything ,will run into this loop
                        str.replace(found,text[i].length(),graph[i]);
                        found = str.find(text[i], found);//update the place, find the key word from where we from last time
                    }
                }
                break;
            case 1:
                cout <<"Input: ";
                cin.ignore(100, '\n');
                getline(cin,str);
                for(int i = 0;i < 5;++i){
                    found = str.find(graph[i]);
                    while(found != string::npos){
                        str.replace(found,graph[i].length(),text[i]);
                        found = str.find(graph[i], found);
                    }
                }                
                break;
        }
        cout << "Output = " << str << endl;
        cout << "----------------------------------------" << endl;
    } while (mode != -1);
    





	// ------------------------------------------ //
		
	return 0;
}

/*
Hello (heart), does the c++ program work? (happy)

*/