#include <iostream>

using namespace std;

template <class elmtype>
class CircularDynamicArray
{
private:
    int cap;
    int size;
    int front;
    int back;
    bool isReversed;
    elmtype* CDArray;
    elmtype error;

    /*
    This method creates a new array of double the cap of the current CDArray and 
    copies the contents of the old array to indices 0-(size - 1);
    */
    void resizeArray(){
                elmtype* newCDA = new elmtype[cap * 2];
                for(int i = 0; i< size;i++){
                    // newCDA[i] = CDArray[(front + i + cap) % cap];
                    newCDA[i] = operator[](i);
                }
                delete []CDArray;
                CDArray = newCDA;
                front = 0;
                back = size - 1;
                cap *= 2;
                isReversed = false;
    }

    /*
    This method creates a new array of half the cap of the current CDArray and 
    copies the contents of the old array to indices 0-(size - 1);
    */

    void downsizeArray(){
        //if(!isReversed){
                elmtype* newCDA = new elmtype[cap / 2];
                for(int i = 0; i< size;i++){
                    // newCDA[i] = CDArray[(front + i + cap) % cap];
                    newCDA[i] = operator[](i);
                }
                delete []CDArray;
                CDArray = newCDA;
                front = 0;
                back = size - 1;
                cap /= 2;
                isReversed = false;
    }

public:
    
    CircularDynamicArray(){
        CDArray = new elmtype[2];
        size = 0;
        cap = 2;
        front = back = -1;
        isReversed = false;
    };

    CircularDynamicArray(int s){
        CDArray = new elmtype[s];
        size = s;
        cap = s;
        front = 0;
        back = s;
        isReversed = false;
    };

    CircularDynamicArray(const CircularDynamicArray &old){
        front = old.front;
        back = old.back;
        size = old.size;
        isReversed = old.isReversed;
        cap = old.cap;
        CDArray = new elmtype[cap];
        for(int i = 0; i< old.size;i++){
                CDArray[(front + i + cap) % cap] = old.CDArray[(front + i + cap) % cap];
            }
    }

    CircularDynamicArray& operator=(const CircularDynamicArray& old){
        if(this != &old){
            delete[] CDArray;
            front = old.front;
            back = old.back;
            size = old.size;
            isReversed = old.isReversed;
            cap = old.cap;
            CDArray = new elmtype[cap];
            for(int i = 0; i< size;i++){
                CDArray[(front + i + cap) % cap]= old.CDArray[(front + i + cap) % cap];
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
            if(isReversed == true) return *(CDArray + ((back - i + cap) % cap));
            else return *(CDArray + ((front + i + cap) % cap));
        }
    }

    /*
    This method adds a new element to the front of the circular dynamic array, resizing if necessary.
    */

    void addFront(elmtype v){
        //cout << "addFront() called" << endl;
        if(size == cap){
            resizeArray();
        
        }
        // CDArray[(front - 1 + cap) % cap] = v;       // I prefer the cleaner use of the operator[](int i)
        operator[](front - 1) = v;
        front = (front - 1 + cap) % cap;
        size++;
        back = (front + size - 1 + cap) % cap;
    }

    /*
    This method adds a new element to the end of the circular dynamic array, resizing if necessary.
    */

    void addEnd(int v){
        if(size == cap){
            resizeArray();
        
        }
        // CDArray[(back + 1 + cap) % cap] = v;       // I prefer the cleaner use of the operator[](int i)
        operator[](back+1) = v;
        back = (back + 1 + cap) % cap;
        size++;
        front = (back - size + 1 + cap) % cap;
    }

    /*
    This method 'deletes' the last element in the array by decreasing array size and decreasing the back index by one.
    */

    void delEnd(){
        if(!isReversed){
            back = (back - 1 + cap) % cap;
            size--;
        }
        else{
            front = (front + 1 + cap) % cap;
            size--;
        }
        if(((float)size)/((float)cap) == .25){
            downsizeArray();
        }
    }

    /*
    This method 'deletes' the first element in the array by decreasing array size and increasing the front index by one.
    */

    void delFront(){
        if(!isReversed){
            front = (front + 1 + cap) % cap;
            size--;
        }
        else{
            back = (back - 1 + cap) % cap;
            size--;
        }
        if(((float)size)/((float)cap) == .25){
            downsizeArray();
        }
    }

    /*
    This method deallocates any memory currently allocated for the CDA and creates a new array of size 0 and cap 2.
    */

   void clear(){
        size = 0;
        cap = 2;
        isReversed = false;
        front = back = -1;
        delete[] CDArray;
        CDArray = new elmtype[2];
   }

   /*
   This method performs a linear search of the circular dynamic array and returns the index of the first appearance of elmtype e or -1 if it is not found.
   */

    int linearSearch(elmtype e){
        for (int i =0; i < size;i++){
            if (operator[](i) == e){
                return i;
            }
        }
        return -1;
    }

    /*
    This method performs a binary search of the circular dynamic array and returns the index of elmtype e in the array if found, otherwise
    it returns -1. Assumes the array is already sorted in ascending order.
    */

    int binarySearch(elmtype e){
        int l = 0;
        int r = size - 1;
        int mid;

        while (l<=r){
            mid = (l + r) / 2;
            if(operator[](mid) == e) return mid;
            if(operator[](mid) < e) l = mid + 1;
            if(operator[](mid) > e) r = mid - 1;
        }

        return -1;
    }

    /*
    This method flips the isReversed boolean, thus changing how other functions 'see' the array.
    */

   void reverse(){
    if (isReversed == true){
        isReversed = false;
    }
    else{
        isReversed = true;
    }
   }

    //Getters below

    int capacity(){
        return cap;
    }

    int length(){
        return size;
    }
};
