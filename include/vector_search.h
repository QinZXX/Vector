#ifndef VECTOR_VECTOR_SEARCH_H
#define VECTOR_VECTOR_SEARCH_H

#include "vector_search_binary.h"

template <typename T>  //在有序向量的区间[lo, hi)内，确定不大于e的最后一个节点的秩
Rank Vector<T>::search ( const T& e, Rank lo, Rank hi ) const {
    return binSearch (  e, lo, hi ) ;
}

#endif //VECTOR_VECTOR_SEARCH_H
