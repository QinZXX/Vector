#ifndef VECTOR_VECTOR_PARTITION_H
#define VECTOR_VECTOR_PARTITION_H

#include "QRandom.h"
#include <algorithm>

template <typename T> //轴点构造算法：通过调整元素位置构造区间[lo, hi)的轴点，并返回其秩
Rank Vector<T>::partition ( Rank lo, Rank hi ) {
    swap ( _elem[lo], _elem[ lo + getRandNum (0, hi - lo-1 ) ] ); //任选一个元素与首元素交换
    T pivot = _elem[lo]; //以首元素为候选轴点——经以上交换，等效于随机选取
    int mi = lo;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //   ---- L < [lo] ----- ] ----- [lo] <= G --- ] [ ----- Unknown -------
    // X x . . . . . . . . . x . . . . . . . . . . . x . . . . . . . . . . x X
    // |                     |                       |                       |
    // lo (pivot candidate)  mi                      k                       hi
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for ( int k = lo + 1; k < hi; k++ ) //自左向右扫描
        if ( _elem[k] < pivot ) //若当前元素_elem[k]小于pivot，则
            swap ( _elem[++mi], _elem[k] ); //将_elem[k]交换至原mi之后，使L子序列向右扩展
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //   --------- L < [lo] ---------- ] ------------- [lo] <= G ----------]
    // X x . . . . . . . . . . . . . . x . . . . . . . . . . . . . . . . . x X
    // |                               |                                     |
    // lo (pivot candidate)            mi                                    hi
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    swap ( _elem[lo], _elem[mi] ); //候选轴点归位
    return mi; //返回轴点的秩
}


#endif //VECTOR_VECTOR_PARTITION_H
