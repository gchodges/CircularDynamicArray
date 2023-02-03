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
        //delete []CDArray;
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

    void addFront(elmtype v){
        //cout << "addFront() called" << endl;
        if(size == capacity){
            resizeArray();
        
        }
        // CDArray[(front - 1 + capacity) % capacity] = v;
        operator[](front - 1) = v;
        front = (front - 1 + capacity) % capacity;
        size++;
        back = (front + size - 1 + capacity) % capacity;
    }

    void addEnd(int v){
        if(size == capacity){
            resizeArray();
        
        }
        // CDArray[(back + 1 + capacity) % capacity] = v;
        operator[](back+1) = v;
        back = (back + 1 + capacity) % capacity;
        size++;
        front = (back - size + 1 + capacity) % capacity;
    }

    void delEnd(){
        if(!isReversed){
            back = (back - 1 + capacity) % capacity;
            size = size - 1;
        }
        if(((float)size)/((float)capacity) == .25){
            downsizeArray();
        }
    }

    void delFront(){
        if(!isReversed){
            front = (front + 1 + capacity) % capacity;
            size = size - 1;
        }
        if(((float)size)/((float)capacity) == .25){
            downsizeArray();
        }
    }

    int getCapacity(){
        return capacity;
    }

    int getSize(){
        return size;
    }
};
