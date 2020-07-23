#ifndef VECTOR_VECTOR_CONSTRUCTOR_BY_COPYING_H
#define VECTOR_VECTOR_CONSTRUCTOR_BY_COPYING_H

template <typename T>
void Vector<T>::copyFrom ( T const* A, Rank lo, Rank hi ) {  //����������A[lo, hi)Ϊ������������
    _elem = new T[_capacity = 2 * ( hi - lo ) ];
    _size = 0; //����ռ䣬��ģ����
    while ( lo < hi ) //A[lo, hi)�ڵ�Ԫ����һ������_elem[0, hi - lo)
        _elem[_size++] = A[lo++];
}
#endif //VECTOR_VECTOR_CONSTRUCTOR_BY_COPYING_H
