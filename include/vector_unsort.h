#ifndef VECTOR_VECTOR_UNSORT_H
#define VECTOR_VECTOR_UNSORT_H

#include "QRandom.h"

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi){  //[lo,hi) �������
    T* V = _elem + lo; //��������_elem[lo, hi)������һ����V[0, hi - lo)
    for ( Rank i = hi - lo; i > 0; i-- ) //�Ժ���ǰ
        swap ( V[i - 1], V[ getRandNum(0,i-1) ] ); //��V[i - 1]��V[0, i)��ĳһԪ���������
} //Todo(): ÿ�����Ӹı��ˣ���������ν���������

#endif //VECTOR_VECTOR_UNSORT_H
