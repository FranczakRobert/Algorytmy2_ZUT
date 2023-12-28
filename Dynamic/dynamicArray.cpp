//
// Created by Robert Franczak on 18/05/2023.
//
#include "iostream"
#include "stdio.h"
    #define DEFAULT_SIZE 2

template<typename T>
class dynamicArray {
private:
    int size;
    int elementCounter;
    T* array;


public:
    dynamicArray()  {
        size = 2;
        elementCounter = 0;
        array = nullptr;
    }

    ~dynamicArray() {
        delete(array);
        array = nullptr;
        size = 0;
        elementCounter = 0;
    }

    void show() {
        for(int i = 0; i < size; i ++) {
            printf("%d \n" , array[i]);
        }
    }

    void add(T element) {
        if(nullptr == array) {
            array = (T*)malloc(size * sizeof(T));
            if(nullptr == array) {
                printf("Error malloc...");
                return;
            }
            array[elementCounter] = element;
            elementCounter++;
        }
        else if(elementCounter < size) {
            printf("TABLICA ZMIENIA ROZMIAR!!! z %d NA %d \n",size , size * 2);
            size *= 2;
            T* tmpArray = array;
            array = nullptr;
            array = (T*) malloc(size * sizeof(T));
            for(int i = 0; i < size / 2; i ++) {
                array[i] = tmpArray[i];
            }
            delete (tmpArray);
            tmpArray = nullptr;
            array[elementCounter] = element;
            elementCounter++;
        } else {
            array[elementCounter] = element;
            elementCounter++;
        }

    }
};
