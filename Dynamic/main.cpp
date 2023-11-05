#include <iostream>
#include "dynamicArray.cpp"

int main() {
    dynamicArray<int> x;
//    for (int i = 0; i < 20; ++i) {
//        x.add(i);
//    }


    x.add(3);
    x.add(2);
    x.add(4);
//    x.add(2);
    x.show();


    return 0;
}
