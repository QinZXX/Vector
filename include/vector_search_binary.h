#ifndef VECTOR_VECTOR_SEARCH_BINARY_H
#define VECTOR_VECTOR_SEARCH_BINARY_H

template <typename T> // [lo,hi)
Rank Vector<T>::binSearch(const T& e,Rank lo,Rank hi) const { // issue: When hi=INT_MAX, lo=1
    while ( lo < hi ) { //每步迭代仅需做一次比较判断，有两个分支
        Rank mi = ( lo + hi ) >> 1; //以中点为轴点（区间宽度的折半，等效于宽度之数值表示的右移）
        ( e < _elem[mi] ) ? hi = mi : lo = mi + 1; //经比较后确定深入[lo, mi)或(mi, hi)
    } //成功查找不能提前终止
    return lo - 1; //循环结束时，lo为大于e的元素的最小秩，故lo - 1即不大于e的元素的最大秩
} //有多个命中元素时，总能保证返回秩最大者；查找失败时，能够返回失败的位置

#endif //VECTOR_VECTOR_SEARCH_BINARY_H
