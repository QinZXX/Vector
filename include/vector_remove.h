#ifndef VECTOR_VECTOR_REMOVE_H
#define VECTOR_VECTOR_REMOVE_H

template <typename T>
T Vector<T>::remove ( Rank r ) { //删除向量中秩为r的元素，0 <= r < size
    T e = _elem[r]; //备份被删除元素
    remove ( r, r + 1 ); //调用区间删除算法，等效于对区间[r, r + 1)的删除
    return e; //返回被删除元素
}

#endif //VECTOR_VECTOR_REMOVE_H
