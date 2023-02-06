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

    for(int i = 0;i<15;i++){
        myCDArray.addEnd(i);
    }
    printint(myCDArray);

    // for(int i = 0;i<15;i++){
    //     //if(i % 2 == 1)
         myCDArray.delFront();
         myCDArray.delEnd();
         myCDArray.delFront();
         myCDArray.delEnd();
         myCDArray.delFront();
         myCDArray.delEnd();
         myCDArray.delFront();
         myCDArray.delEnd();
         myCDArray.delFront();
         myCDArray.delEnd();
        //  myCDArray.delFront();
         myCDArray.delEnd();       

    //     cout << myCDArray.getCapacity() << endl;
        printint(myCDArray);
    // }

    cout << "myCDArray[5] = " << myCDArray[5] << endl;

    return 0;
}
