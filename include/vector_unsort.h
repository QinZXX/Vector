#ifndef VECTOR_VECTOR_UNSORT_H
#define VECTOR_VECTOR_UNSORT_H

#include "QRandom.h"

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi){  //[lo,hi) 随机置乱
    T* V = _elem + lo; //将子向量_elem[lo, hi)视作另一向量V[0, hi - lo)
    for ( Rank i = hi - lo; i > 0; i-- ) //自后向前
        swap ( V[i - 1], V[ getRandNum(0,i-1) ] ); //将V[i - 1]与V[0, i)中某一元素随机交换
} //Todo(): 每次种子改变了，不再是所谓的随机置乱

#endif //VECTOR_VECTOR_UNSORT_H
