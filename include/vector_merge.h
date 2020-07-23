#ifndef VECTOR_VECTOR_MERGE_H
#define VECTOR_VECTOR_MERGE_H

template <typename T> //�������������䣩�Ĺ鲢
void Vector<T>::merge ( Rank lo, Rank mi, Rank hi ) { //���������������[lo, mi)��[mi, hi)
    T* A = _elem + lo; //�ϲ��������A[0, hi - lo) = _elem[lo, hi)
    int lb = mi - lo;
    T* B = new T[lb]; //ǰ������B[0, lb) = _elem[lo, mi)  ����
    for ( Rank i = 0; i < lb; i++ )
        B[i] = A[i]; //����ǰ������
    int lc = hi - mi;
    T* C = _elem + mi; //��������C[0, lc) = _elem[mi, hi)
    for ( Rank i = 0, j = 0, k = 0; j < lb; ) //�鲢��������B��C��Ԫ����ȡ����С��
        A[i++] = ( lc <= k || B[j] <= C[k] ) ? B[j++] : C[k++]; //�������A��
    delete [] B; //�ͷ���ʱ�ռ�B
}

#endif //VECTOR_VECTOR_MERGE_H
