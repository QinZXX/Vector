#ifndef VECTOR_UTIL_H
#define VECTOR_UTIL_H

template <typename T>
void swap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}
#endif //VECTOR_UTIL_H
