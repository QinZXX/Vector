#ifndef VECTOR_VECTOR_ASSIGNMENT_H
#define VECTOR_VECTOR_ASSIGNMENT_H

template <typename T>
Vector<T>& Vector<T>::operator= ( Vector<T> const& V ) { //深复制
#ifdef TEST
    cout<<"use = constructor!!!"<<endl;
#endif
    if ( _elem )
        delete [] _elem; //释放原有内容
    copyFrom ( V._elem, 0, V.size() ); //整体复制
    return *this; //返回当前对象的引用，以便链式赋值
}

#endif //VECTOR_VECTOR_ASSIGNMENT_H
