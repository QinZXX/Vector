#ifndef VECTOR_VECTOR_INSERT_H
#define VECTOR_VECTOR_INSERT_H

template <typename T> //��e��Ϊ��ΪrԪ�ز���
Rank Vector<T>::insert ( Rank r, T const& e ) { //assert: 0 <= r <= size
    expand(); //���б�Ҫ������
    for ( int i = _size; i > r; i-- )
        _elem[i] = _elem[i-1]; //�Ժ���ǰ�����Ԫ��˳�κ���һ����Ԫ
    _elem[r] = e;
    _size++; //������Ԫ�ز���������
    return r; //������
}

#endif //VECTOR_VECTOR_INSERT_H
