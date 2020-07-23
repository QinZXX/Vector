#ifndef VECTOR_VECTOR_SEARCH_BINARY_H
#define VECTOR_VECTOR_SEARCH_BINARY_H

template <typename T> // [lo,hi)
Rank Vector<T>::binSearch(const T& e,Rank lo,Rank hi) const { // issue: When hi=INT_MAX, lo=1
    while ( lo < hi ) { //ÿ������������һ�αȽ��жϣ���������֧
        Rank mi = ( lo + hi ) >> 1; //���е�Ϊ��㣨�����ȵ��۰룬��Ч�ڿ��֮��ֵ��ʾ�����ƣ�
        ( e < _elem[mi] ) ? hi = mi : lo = mi + 1; //���ȽϺ�ȷ������[lo, mi)��(mi, hi)
    } //�ɹ����Ҳ�����ǰ��ֹ
    return lo - 1; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ���lo - 1��������e��Ԫ�ص������
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ��

#endif //VECTOR_VECTOR_SEARCH_BINARY_H
