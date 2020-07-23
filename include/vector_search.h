#ifndef VECTOR_VECTOR_SEARCH_H
#define VECTOR_VECTOR_SEARCH_H

#include "vector_search_binary.h"

template <typename T>  //����������������[lo, hi)�ڣ�ȷ��������e�����һ���ڵ����
Rank Vector<T>::search ( const T& e, Rank lo, Rank hi ) const {
    return binSearch (  e, lo, hi ) ;
}

#endif //VECTOR_VECTOR_SEARCH_H
