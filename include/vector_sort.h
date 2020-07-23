#ifndef VECTOR_VECTOR_SORT_H
#define VECTOR_VECTOR_SORT_H

#include "QRandom.h"

template <typename T> void Vector<T>::sort ( Rank lo, Rank hi ) { //向量区间[lo, hi)排序
    switch ( getRandNum(0,5) ) {
        case 1:  bubbleSort ( lo, hi ); break; //起泡排序
        case 2:  selectionSort ( lo, hi ); break; //选择排序
        case 3:  mergeSort ( lo, hi ); break; //归并排序
        case 4:  quickSort ( lo, hi ); break; //快速排序
        case 5:  shellSort ( lo, hi ); break; //希尔排序
        //case 0:  heapSort ( lo, hi ); break; //堆排序 Todo
    } //随机选择算法。实用时可视具体问题的特点灵活确定或扩充
}

#endif //VECTOR_VECTOR_SORT_H
