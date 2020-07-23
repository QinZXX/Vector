#ifndef VECTOR_VECTOR_INITIALIZER_LIST_H
#define VECTOR_VECTOR_INITIALIZER_LIST_H

template <typename T>
Vector<T>::Vector(std::initializer_list<T> l) : Vector (  DEFAULT_CAPACITY, 0,  0 )  {
    cout<<"user initializer_list constructor!!!!!"<<endl;
    for(auto p=l.begin();p!=l.end();p++){
        push_back(*p);
    }
}
#endif //VECTOR_VECTOR_INITIALIZER_LIST_H
