#ifndef VECTOR_VECTOR_FIND_H
#define VECTOR_VECTOR_FIND_H

template <typename T> //无序向量的顺序查找：返回最后一个元素e的位置；失败时，返回lo - 1
Rank Vector<T>::find ( T const& e, Rank lo, Rank hi ) const {
    while ( ( lo < hi-- ) && ( e != _elem[hi] ) ); //从后向前，顺序查找
    return hi; //若hi < lo，则意味着失败；否则hi即命中元素的秩
}

#endif //VECTOR_VECTOR_FIND_H
