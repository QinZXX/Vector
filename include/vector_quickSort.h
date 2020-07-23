#ifndef VECTOR_VECTOR_QUICKSORT_H
#define VECTOR_VECTOR_QUICKSORT_H

#include "vector_partition.h"

template <typename T>
void Vector<T>::quickSort(Rank lo,Rank hi){
    if ( hi - lo < 2 )
        return; //单元素区间自然有序，否则...
    Rank mi = partition ( lo, hi ); //在[lo, hi)内构造轴点
    quickSort ( lo, mi ); //对前缀递归排序
    quickSort ( mi + 1, hi ); //对后缀递归排序
}

#endif //VECTOR_VECTOR_QUICKSORT_H
