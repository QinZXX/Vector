#ifndef VECTOR_VECTOR_TRAVERSE_H
#define VECTOR_VECTOR_TRAVERSE_H

template <typename T>
void Vector<T>::traverse(void (*visit) (T&)){
    for(int i=0;i<_size;i++){
        visit(_elem[i]);
    }
    std::cout<<std::endl;
}

template <typename T>
template <typename VST>
void Vector<T>::traverse ( VST& visit){
    for(int i=0;i<_size;i++){
        visit(_elem[i]);
    }
}


#endif //VECTOR_VECTOR_TRAVERSE_H
