#ifndef VECTOR_VECTOR_QUICKSORT_H
#define VECTOR_VECTOR_QUICKSORT_H

#include "vector_partition.h"

template <typename T>
void Vector<T>::quickSort(Rank lo,Rank hi){
    if ( hi - lo < 2 )
        return; //��Ԫ��������Ȼ���򣬷���...
    Rank mi = partition ( lo, hi ); //��[lo, hi)�ڹ������
    quickSort ( lo, mi ); //��ǰ׺�ݹ�����
    quickSort ( mi + 1, hi ); //�Ժ�׺�ݹ�����
}

#endif //VECTOR_VECTOR_QUICKSORT_H
