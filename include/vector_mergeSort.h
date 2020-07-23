#ifndef VECTOR_VECTOR_MERGESORT_H
#define VECTOR_VECTOR_MERGESORT_H

template <typename T> //向量归并排序
void Vector<T>::mergeSort ( Rank lo, Rank hi ) { //0 <= lo < hi <= size
    if ( hi - lo < 2 )
        return; //单元素区间自然有序
    int mid = ( lo + hi ) >> 1; //以中点为界
    mergeSort ( lo, mid );
    mergeSort ( mid, hi ); //分别排序
    merge ( lo, mid, hi ); //归并
}
 //Todo: change it into new style (recursize style)

#endif //VECTOR_VECTOR_MERGESORT_H
