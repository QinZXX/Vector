#ifndef VECTOR_VECTOR_ASSIGNMENT_H
#define VECTOR_VECTOR_ASSIGNMENT_H

template <typename T>
Vector<T>& Vector<T>::operator= ( Vector<T> const& V ) { //���
#ifdef TEST
    cout<<"use = constructor!!!"<<endl;
#endif
    if ( _elem )
        delete [] _elem; //�ͷ�ԭ������
    copyFrom ( V._elem, 0, V.size() ); //���帴��
    return *this; //���ص�ǰ��������ã��Ա���ʽ��ֵ
}

#endif //VECTOR_VECTOR_ASSIGNMENT_H
