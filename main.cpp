#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

void printint(CircularDynamicArray<int> cdarray){
    cout << "Print Called" << endl;
    for(int i = 0; i<cdarray.length();i++){
        cout << "i = " << i << ": "<<  cdarray[i] << endl;
    }
    cout << endl;
}

int main(){
    CircularDynamicArray<int> myCDArray;

    //srand((unsigned)time(NULL));


    for(int i = 0;i<15;i++){
        myCDArray.addEnd(i);
    }
    printint(myCDArray);
    myCDArray.reverse();
    printint(myCDArray);
    myCDArray.delEnd();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    myCDArray.delFront();
    printint(myCDArray);
    


    cout << myCDArray.binarySearch(12) << endl;

    cout << "myCDArray[5] = " << myCDArray[5] << endl;

    return 0;
}
