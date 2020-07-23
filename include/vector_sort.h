#ifndef VECTOR_VECTOR_SORT_H
#define VECTOR_VECTOR_SORT_H

#include "QRandom.h"

template <typename T> void Vector<T>::sort ( Rank lo, Rank hi ) { //��������[lo, hi)����
    switch ( getRandNum(0,5) ) {
        case 1:  bubbleSort ( lo, hi ); break; //��������
        case 2:  selectionSort ( lo, hi ); break; //ѡ������
        case 3:  mergeSort ( lo, hi ); break; //�鲢����
        case 4:  quickSort ( lo, hi ); break; //��������
        case 5:  shellSort ( lo, hi ); break; //ϣ������
        //case 0:  heapSort ( lo, hi ); break; //������ Todo
    } //���ѡ���㷨��ʵ��ʱ���Ӿ���������ص����ȷ��������
}

#endif //VECTOR_VECTOR_SORT_H
