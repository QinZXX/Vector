#ifndef VECTOR_VECTOR_SELECTIONSORT_H
#define VECTOR_VECTOR_SELECTIONSORT_H

#include "util.h"

template <typename T> //ѡ������
void Vector<T>::selectionSort ( Rank lo, Rank hi ) { //0 <= lo < hi <= size
    if ( lo >= hi ) {
        std::cout<<"Interval Error !"<<std::endl;
    }
    while ( lo < --hi )
        swap ( _elem[max ( lo, hi ) ], _elem[hi] ); //��[hi]��[lo, hi]�е�����߽���
}

template <typename T>
Rank Vector<T>::max ( Rank lo, Rank hi ) { //��[lo, hi]���ҳ������
    Rank mx = hi;
    while ( lo < hi-- ) //����ɨ��
        if ( _elem[hi] > _elem[mx] ) //���ϸ�Ƚ�
            mx = hi; //������max�ж��ʱ��֤�������ȣ�������֤selectionSort�ȶ�
    return mx;
}


#endif //VECTOR_VECTOR_SELECTIONSORT_H
