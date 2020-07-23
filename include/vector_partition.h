#ifndef VECTOR_VECTOR_PARTITION_H
#define VECTOR_VECTOR_PARTITION_H

#include "QRandom.h"
#include <algorithm>

template <typename T> //��㹹���㷨��ͨ������Ԫ��λ�ù�������[lo, hi)����㣬����������
Rank Vector<T>::partition ( Rank lo, Rank hi ) {
    swap ( _elem[lo], _elem[ lo + getRandNum (0, hi - lo-1 ) ] ); //��ѡһ��Ԫ������Ԫ�ؽ���
    T pivot = _elem[lo]; //����Ԫ��Ϊ��ѡ��㡪�������Ͻ�������Ч�����ѡȡ
    int mi = lo;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //   ---- L < [lo] ----- ] ----- [lo] <= G --- ] [ ----- Unknown -------
    // X x . . . . . . . . . x . . . . . . . . . . . x . . . . . . . . . . x X
    // |                     |                       |                       |
    // lo (pivot candidate)  mi                      k                       hi
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for ( int k = lo + 1; k < hi; k++ ) //��������ɨ��
        if ( _elem[k] < pivot ) //����ǰԪ��_elem[k]С��pivot����
            swap ( _elem[++mi], _elem[k] ); //��_elem[k]������ԭmi֮��ʹL������������չ
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //   --------- L < [lo] ---------- ] ------------- [lo] <= G ----------]
    // X x . . . . . . . . . . . . . . x . . . . . . . . . . . . . . . . . x X
    // |                               |                                     |
    // lo (pivot candidate)            mi                                    hi
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    swap ( _elem[lo], _elem[mi] ); //��ѡ����λ
    return mi; //����������
}


#endif //VECTOR_VECTOR_PARTITION_H