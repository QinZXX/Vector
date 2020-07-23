#ifndef VECTOR_VECTOR_FIND_H
#define VECTOR_VECTOR_FIND_H

template <typename T> //����������˳����ң��������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo - 1
Rank Vector<T>::find ( T const& e, Rank lo, Rank hi ) const {
    while ( ( lo < hi-- ) && ( e != _elem[hi] ) ); //�Ӻ���ǰ��˳�����
    return hi; //��hi < lo������ζ��ʧ�ܣ�����hi������Ԫ�ص���
}

#endif //VECTOR_VECTOR_FIND_H
