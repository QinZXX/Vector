#ifndef VECTOR_VECTOR_CONSTRUCTOR_BY_COPYING_H
#define VECTOR_VECTOR_CONSTRUCTOR_BY_COPYING_H

template <typename T>
void Vector<T>::copyFrom ( T const* A, Rank lo, Rank hi ) {  //以数组区间A[lo, hi)为蓝本复制向量
    _elem = new T[_capacity = 2 * ( hi - lo ) ];
    _size = 0; //分配空间，规模清零
    while ( lo < hi ) //A[lo, hi)内的元素逐一复制至_elem[0, hi - lo)
        _elem[_size++] = A[lo++];
}
#endif //VECTOR_VECTOR_CONSTRUCTOR_BY_COPYING_H
