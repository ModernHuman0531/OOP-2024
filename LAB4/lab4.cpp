/*Goal
Create a stack,and we can choose what to input based on the operation number we input;
Operation 0 is input an int ,Operation 1 is to input a char, Operation 2 is to pop out the data we input;
When the stack is empty ,print "the stack is empty" 
*/

/*Solution
create a data that contain three part int, char, bool;
when operation == 0,input int,and store bool = 0;
else operation == 1,input char, andf store bool = 1;
when operation == 2,first watch bool to judge the output type;
*/
#include <iostream>
using namespace std;
#define DEBUG

struct Data
{
    int number;
    char letter;
    bool is_number;
};

class Stack
{
    public:
        Stack():index{0}{}
        void push(Data);
        Data pop();
        bool is_empty();
    private:
        int index;
        Data data[];
};

void Stack::push(Data input_data){
    data[index] = input_data;
    ++index;
    return;
}

Data Stack::pop(){
    --index;
    return data[index];
    #ifdef DEBUG
    cout << "index = " << index << endl;
    #endif
}

bool Stack::is_empty(){
    if(index < 0)
        return 1;
    else
        return 0;
}

int main()
{
    int operation;
    Data data;
    Stack stack;
    do
    {   cout << "choose the operation: " << endl;
        cin >> operation;
        if(operation != 2){
            if(operation == 0){
                cout << "push a number: " << endl;
                cin >> data.number;
                data.is_number = 0;
            }
            else if(operation == 1){
                cout << "push a letter: " << endl;
                cin >> data.letter;
                data.is_number = 1;
            }
            stack.push(data);
        }
        else{
            data = stack.pop(); 
            cout << "pop stack: " << endl;
            if(data.is_number == 0)
                cout << data.number << endl;
            else if(data.is_number == 1)
                cout << data.letter << endl;
        }

        
    } while (stack.is_empty() == 0);
     cout << "the stack is empty" << endl;

     return 0;
}
    

