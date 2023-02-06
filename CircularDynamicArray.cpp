#include <iostream>

using namespace std;

template <class elmtype>
class CircularDynamicArray
{
private:
    int capacity;
    int size;
    int front;
    int back;
    bool isReversed;
    elmtype* CDArray;
    elmtype error;
public:
    
    CircularDynamicArray(){
        CDArray = new elmtype[2];
        size = 0;
        capacity = 2;
        front = back = -1;
        isReversed = false;
    };

    CircularDynamicArray(int s){
        CDArray = new elmtype[s];
        size = s;
        capacity = s;
        front = 0;
        back = s;
        isReversed = false;
    };

    CircularDynamicArray(const CircularDynamicArray &old){
        front = old.front;
        back = old.back;
        size = old.size;
        isReversed = old.isReversed;
        capacity = old.capacity;
        CDArray = new elmtype[capacity];
        for(int i = 0; i< old.size;i++){
                CDArray[(front + i + capacity) % capacity] = old.CDArray[(front + i + capacity) % capacity];
            }
    }

    CircularDynamicArray& operator=(const CircularDynamicArray& old){
        if(this != &old){
            delete[] CDArray;
            front = old.front;
            back = old.back;
            size = old.size;
            isReversed = old.isReversed;
            capacity = old.capacity;
            CDArray = new elmtype[capacity];
            for(int i = 0; i< size;i++){
                CDArray[(front + i + capacity) % capacity]= old.CDArray[(front + i + capacity) % capacity];
            }
        }
        return *this;
    }

    ~CircularDynamicArray(){
        delete []CDArray;
    };

    elmtype& operator[](int i){
        if (i > (size)){
            cout << "Index out of bounds" << endl;
            return error;
        }
        else{
            return *(CDArray + ((front + i + capacity)%capacity));
        }
    }


    /*
    This method creates a new array of double the capacity of the current CDArray and 
    copies the contents of the old array to indices 0-(size - 1);
    */
    void resizeArray(){
        if(!isReversed){
                elmtype* newCDA = new elmtype[capacity * 2];
                for(int i = 0; i< size;i++){
                    // newCDA[i] = CDArray[(front + i + capacity) % capacity];
                    newCDA[i] = operator[](i);
                }
                delete []CDArray;
                CDArray = newCDA;
                front = 0;
                back = size - 1;
                capacity *= 2;
            }
            else{

            }
    }

    /*
    This method creates a new array of half the capacity of the current CDArray and 
    copies the contents of the old array to indices 0-(size - 1);
    */

    void downsizeArray(){
        if(!isReversed){
                elmtype* newCDA = new elmtype[capacity / 2];
                for(int i = 0; i< size;i++){
                    // newCDA[i] = CDArray[(front + i + capacity) % capacity];
                    newCDA[i] = operator[](i);
                }
                delete []CDArray;
                CDArray = newCDA;
                front = 0;
                back = size - 1;
                capacity /= 2;
            }
            else{

            }
    }

    /*
    This method adds a new element to the front of the circular dynamic array, resizing if necessary.
    */

    void addFront(elmtype v){
        //cout << "addFront() called" << endl;
        if(size == capacity){
            resizeArray();
        
        }
        // CDArray[(front - 1 + capacity) % capacity] = v;       // I prefer the cleaner use of the operator[](int i)
        operator[](front - 1) = v;
        front = (front - 1 + capacity) % capacity;
        size++;
        back = (front + size - 1 + capacity) % capacity;
    }

    /*
    This method adds a new element to the end of the circular dynamic array, resizing if necessary.
    */

    void addEnd(int v){
        if(size == capacity){
            resizeArray();
        
        }
        // CDArray[(back + 1 + capacity) % capacity] = v;       // I prefer the cleaner use of the operator[](int i)
        operator[](back+1) = v;
        back = (back + 1 + capacity) % capacity;
        size++;
        front = (back - size + 1 + capacity) % capacity;
    }

    /*
    This method 'deletes' the last element in the array by decreasing array size and decreasing the back index by one.
    */

    void delEnd(){
        if(!isReversed){
            back = (back - 1 + capacity) % capacity;
            size = size - 1;
        }
        if(((float)size)/((float)capacity) == .25){
            downsizeArray();
        }
    }

    /*
    This method 'deletes' the first element in the array by decreasing array size and increasing the front index by one.
    */

    void delFront(){
        if(!isReversed){
            front = (front + 1 + capacity) % capacity;
            size = size - 1;
        }
        if(((float)size)/((float)capacity) == .25){
            downsizeArray();
        }
    }

    //Getters below

    int capacity(){
        return capacity;
    }

    int length(){
        return size;
    }
};
