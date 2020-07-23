#ifndef VECTOR_VECTOR_DEDUPLICATE_H
#define VECTOR_VECTOR_DEDUPLICATE_H

template <typename T>
int Vector<T>::deduplicate() { //ɾ�������������ظ�Ԫ�أ���Ч�棩
    int oldSize = _size; //��¼ԭ��ģ
    Rank i = 1; //��_elem[1]��ʼ
    while (i < _size) //��ǰ�����һ�����Ԫ��_elem[i]
        if (find(_elem[i], 0, i) < 0) //��ǰ׺[0,i)��Ѱ����֮��ͬ�ߣ�����һ����
            i++; //������ͬ�������������
        else
            remove(i); //����ɾ����ǰԪ��
    return oldSize - _size; //��ɾ��Ԫ������
}

#endif //VECTOR_VECTOR_DEDUPLICATE_H
