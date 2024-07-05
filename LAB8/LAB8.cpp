/*
Practice a bubble sort class;
*/
#include <iostream>
using namespace std;

class BubbleSortArray {

    private:
        int *array; // array need to be sorted
        int size;   // array size

    public:

        BubbleSortArray(int size_):size{size_},array(new int [size_]){
            cout << "**constructor executed**" << endl;
            cout << "Enter " << size << " intergers: ";
            for(int i = 0;i < size;++i){
                cin >> array[i];
            }
            
        } // (1) constructor
        ~BubbleSortArray(){cout << "**Destructor executed**" << endl;} // (2) destructors
        void bubbleSort();// (3) bubble sort function : void bubbleSort();
        void display(); // (4) display sorted array : void display();
        int* findMax();// (5) find the max number in array, 
        //     The function should return " int * " which points to the max number : int* findMax();
        
};


void BubbleSortArray::bubbleSort() {//
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void BubbleSortArray::display(){
    for(int i = 0;i < size;++i){
        cout << array[i] << " ";
    }
    cout << endl;
}
int* BubbleSortArray::findMax(){
    return &array[size - 1];//return the adress to let the pointer receive it, the aray after the bubblesort the max number will at the last index of array

}

int main() {

    /*     modify this block is not allowed      */

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    BubbleSortArray *bubble_ptr ;
    BubbleSortArray arr(n);
    
    bubble_ptr = &arr ;
    int *max_ptr = NULL; // point to the max number in array,max_ptr store the address of the max number

    /*     modify this block is not allowed      */



    // write your code in the below block
    // only use "bubble_ptr" and "max_ptr" 
    // can not initialize other parameter
    /*                                   */
    cout << "Original array: ";
    bubble_ptr->display();
    bubble_ptr->bubbleSort();

    cout << "Sorted array: ";
    bubble_ptr->display();
    max_ptr = bubble_ptr->findMax();
    cout << "Max value in the array: " << *max_ptr << endl;
    /*                                   */

    return 0;
}