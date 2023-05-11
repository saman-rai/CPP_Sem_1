#include<iostream>
using namespace std;

void printArray(int*, int);
void bubblesort(int*, int);
double mean(int*, int);
int mode(int*, int);
double median(int*, int);
int main() {
    const int ArraySize = 10;
    int mainArray[ArraySize] = {4,7,5,2,0,6,6,1,9,4};

    cout<<"Unsorted Array :"<<endl;
    printArray(mainArray, ArraySize);

    cout<<"Sorted Array :"<<endl;
    bubblesort(mainArray, ArraySize);
    printArray(mainArray, ArraySize);

    double meanValue = mean(mainArray, ArraySize);
    cout<<"Mean value is "<<meanValue<<endl;
    
    int modeValue = mode(mainArray, ArraySize);
    cout<<"Mode value is "<<modeValue<<endl;

    double medianValue = median(mainArray, ArraySize);
    cout<<"Median value is "<<medianValue<<endl;

    return 0;
}

// function defination
void printArray(int* arrayPtr, int size){
    for(int i = 0; i<size; i++){
        cout<<arrayPtr[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int* arrayPtr, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size- i - 1; j++){
            if (arrayPtr[j] > arrayPtr[j + 1]){
                int temp = arrayPtr[j];
                arrayPtr[j] = arrayPtr[j + 1];
                arrayPtr[j + 1] = temp;
            }
        }
    }
}

double mean(int* arrayPtr, int size){
    double sum = 0;
    for(int i = 0; i<size; i++){
        sum+=arrayPtr[i];
    }
    return (sum/size);
}

int mode(int* arrayPtr, int size){
    int mode = *arrayPtr;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<size; i++)
    {
        if (arrayPtr[i] == *arrayPtr) 
            ++count;
        else
        { 
                if (count > countMode) 
                {
                    countMode = count;
                    mode = *arrayPtr;
                }
            count = 1;
            *arrayPtr = arrayPtr[i];
        }
    }

   return mode;
}

double median(int* arrayPtr, int size){
    if (size % 2 != 0)
      return (double)arrayPtr[size/2];
   return (double)(arrayPtr[(size-1)/2] + arrayPtr[size/2])/2.0;
}