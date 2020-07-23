#ifndef VECTOR_VECTOR_MERGESORT_H
#define VECTOR_VECTOR_MERGESORT_H

template <typename T> //�����鲢����
void Vector<T>::mergeSort ( Rank lo, Rank hi ) { //0 <= lo < hi <= size
    if ( hi - lo < 2 )
        return; //��Ԫ��������Ȼ����
    int mid = ( lo + hi ) >> 1; //���е�Ϊ��
    mergeSort ( lo, mid );
    mergeSort ( mid, hi ); //�ֱ�����
    merge ( lo, mid, hi ); //�鲢
}
 //Todo: change it into new style (recursize style)

#endif //VECTOR_VECTOR_MERGESORT_H
