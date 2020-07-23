#ifndef VECTOR_VECTOR_SHELLSORT_H
#define VECTOR_VECTOR_SHELLSORT_H

template <typename T>  // Ï£¶ûÅÅÐò
void Vector<T>::shellSort(Rank lo,Rank hi){
    if ( lo >= hi ) {
        std::cout<<"Interval Error !"<<std::endl;
    }
    for ( int d = 0x3FFFFFFF; 0 < d; d >>= 1 ) {//PS Sequence: { 1, 3, 7, 15, ..., 1073741823 }
        for (int j = lo + d; j < hi; j++) { //for each j in [lo+d, hi)
            T x = _elem[j];
            int i = j - d;
            while (lo <= i && _elem[i] > x) {
                _elem[i + d] = _elem[i];
                i -= d;
            }
            _elem[i + d] = x; //insert [j] into its subsequence
        }
    }
}

#endif //VECTOR_VECTOR_SHELLSORT_H
