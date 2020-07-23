#ifndef VECTOR_VECTOR_BUBBLESORT_C_H
#define VECTOR_VECTOR_BUBBLESORT_C_H

#include <iostream>
#include <util.h>

template <typename T> //向量的冒泡排序（提前终止版）
void Vector<T>::bubbleSort( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
    if ( lo >= hi ) {
        std::cout<<"Interval Error !"<<std::endl;
    }
    for (Rank i=lo;i<=hi-1;i++){
        bool isChanged=false;
        for(Rank j=lo;j<=hi-1+lo-i;j++){
            if(_elem[j]>_elem[j+1]){
                swap(_elem[j],_elem[j+1]);
                isChanged=true;
            }
        }
        if(!isChanged){
            break;
        }
    }
}

#endif //VECTOR_VECTOR_BUBBLESORT_C_H
