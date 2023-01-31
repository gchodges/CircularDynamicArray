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
        //delete []CDArray;
        CDArray = old.CDArray;
        front = old.front;
        back = old.back;
        size = old.size;
        isReversed = old.isReversed;
        capacity = old.capacity;
    }

    CircularDynamicArray& operator=(const CircularDynamicArray& old){
        CDArray = old.CDArray;
        front = old.front;
        back = old.back;
        size = old.size;
        isReversed = old.isReversed;
        capacity = old.capacity;
        return *this;
    }

    ~CircularDynamicArray(){
        //delete []CDArray;
    };

    elmtype& operator[](int i){
        if (i > ((back - front + capacity) % capacity)){
            cout << "Index out of bounds" << endl;
        }
        else{
            return *(CDArray + ((front + i + capacity)%capacity));
        }
    }

    void resizeArray(){
        if(!isReversed){
                elmtype* newCDA = new elmtype[capacity];
                for(int i = 0; i< size;i++){
                    newCDA[i] = CDArray[(front + i + size) % size];
                }
                delete []CDArray;
                CDArray = newCDA;
                front = 0;
                back = size - 1;
            }
            else{

            }
    }

    void addFront(elmtype v){
        //cout << "addFront() called" << endl;
        if(size == capacity){
            capacity = capacity * 2;
            resizeArray();
        
        }
        CDArray[(front - 1 + capacity) % capacity] = v;
        front = (front - 1 + capacity) % capacity;
        size++;
        back = (front + size - 1 + capacity) % capacity;
    }

    void addEnd(int v){
        if(size == capacity){
            capacity = capacity * 2;
            resizeArray();
        
        }
        CDArray[(back + 1 + capacity) % capacity] = v;
        back = (back + 1 + capacity) % capacity;
        size++;
        front = (back - size + 1 + capacity) % capacity;
    }

    void delEnd(){
        if(!isReversed){
            back = back - 1;
            size = size - 1;
        }
        if(((float)size)/((float)capacity) == .25){
            capacity = capacity / 2;
            resizeArray();
        }
    }

    void delFront(){
        if(!isReversed){

        }
    }

    int getCapacity(){
        return capacity;
    }

    int getSize(){
        return size;
    }
};
