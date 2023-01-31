#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

void printint(CircularDynamicArray<int> cdarray){
    cout << "Print Called" << endl;
    for(int i = 0; i<cdarray.getSize();i++){
        cout << "i = " << i << ": "<<  cdarray[i] << endl;
    }
    cout << endl;
}

int main(){
    CircularDynamicArray<int> myCDArray;

    for(int i = 0;i<15;i++){
        myCDArray.addEnd(i);
    }
    printint(myCDArray);

    for(int i = 0;i<15;i++){
        myCDArray.delEnd();
        cout << myCDArray.getCapacity() << endl;
        printint(myCDArray);
    }

    cout << "myCDArray[5] = " << myCDArray[5] << endl;

    return 0;
}
