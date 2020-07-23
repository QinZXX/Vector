#ifndef VECTOR_VECTOR_BRACKET_H
#define VECTOR_VECTOR_BRACKET_H

template <typename T>
T & Vector<T>::operator[] ( Rank r ) //�����±������
{ return _elem[r]; } // assert: 0 <= r < _size

template <typename T>
const T & Vector<T>::operator[] ( Rank r ) const //����������ֵ
{ return _elem[r]; } // assert: 0 <= r < _size

#endif //VECTOR_VECTOR_BRACKET_H
