/******************************************************************************************
 * Data Structures in C++
 * Created by laoqin on 2020/7/2.
 ******************************************************************************************/

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "util.h"
typedef int Rank; //秩
#define DEFAULT_CAPACITY  3 //默认的初始容量

template <typename T> class Vector { //向量模板类
protected:
    Rank _size; int _capacity;  T* _elem; //规模、容量、数据区
    void copyFrom ( T const* A, Rank lo, Rank hi ); //复制数组区间A[lo, hi)
    void expand(); //空间不足时扩容 (vector_expand.h)
    void shrink(); //装填因子过小时压缩 (vector_shrink.h)
    void bubbleSort ( Rank lo, Rank hi ); //起泡排序算法 (vector_bubblesort.h)
    Rank max ( Rank lo, Rank hi ); //选取最大元素 (vector_selectionSort.h)
    void selectionSort ( Rank lo, Rank hi ); //选择排序算法 (vector_selectionSort.h)
    void merge ( Rank lo, Rank mi, Rank hi ); //归并算法 (vector_merge.h)
    void mergeSort ( Rank lo, Rank hi ); //归并排序算法 (vector_mergeSort.h)
    void heapSort ( Rank lo, Rank hi ); //堆排序 (vector_heapSort.h) Todo
    Rank partition ( Rank lo, Rank hi ); //轴点构造算法 (vector_partition.h)
    void quickSort ( Rank lo, Rank hi ); //快速排序算法 (vector_quickSort.h)
    void shellSort ( Rank lo, Rank hi ); //希尔排序算法 (vector_shellSort.h)
    Rank Vector<T>::binSearch(const T& e,Rank lo,Rank hi); // (vector_search_binary.h)
public:

    // Constructor
    Vector ( int c = DEFAULT_CAPACITY, int s = 0, T v = 0 ) { //容量为c、规模为s、所有元素初始为v
        _elem = new T[_capacity = c];
        for ( _size = 0; _size < s; _elem[_size++] = v );
    } //s<=c
    Vector ( T const* A, Rank n ) { //数组整体复制
        copyFrom ( A, 0, n ); }
    Vector ( T const* A, Rank lo, Rank hi ) { //区间
        copyFrom ( A, lo, hi ); }
    Vector ( Vector<T> const& V ) { //向量整体复制
        copyFrom ( V._elem, 0, V._size ); }
    Vector ( Vector<T> const& V, Rank lo, Rank hi ) { //区间
        copyFrom ( V._elem, lo, hi ); }

    // Destructor
    ~Vector() { delete [] _elem; } //释放内部空间

    // Read only access interface
    Rank size() const { return _size; } //规模
    bool empty() const { return !_size; } //判空
    Rank find ( T const& e ) const { //无序向量整体查找
        return find ( e, 0, _size );
    }
    Rank find ( T const& e, Rank lo, Rank hi ) const; //无序向量区间查找 (vector_find.h)
    Rank search ( T const& e ) const { //有序向量整体查找
        return ( 0 >= _size ) ? -1 : search ( e, 0, _size );
    }
    Rank search ( T const& e, Rank lo, Rank hi ) const; //有序向量区间查找 (vector_search.h)

    // Writeable access interface
    T& operator[] ( Rank r ); //重载下标操作符，可以类似于数组形式引用各元素
    const T& operator[] ( Rank r ) const; //仅限于做右值的重载版本 (vector_bracket.h)
    Vector<T> & operator= ( Vector<T> const& ); //重载赋值操作符，以便直接克隆向量 (vector_assignment.h)
    T remove ( Rank r ); //删除秩为r的元素 (vector_remove.h)
    int remove ( Rank lo, Rank hi ); //删除秩在区间[lo, hi)之内的元素 (vector_removeInterval.h)
    Rank insert ( Rank r, T const& e ); //插入元素
    Rank push_back(const T&e){ // (vector_insert.h)
        return insert(_size,e);
    }
    void sort ( Rank lo, Rank hi ); //对[lo, hi)排序 (vector_sort.h)
    void sort() { sort ( 0, _size ); } //整体排序
    void unsort ( Rank lo, Rank hi ); //对[lo, hi)置乱 (vector_unsort.h)
    void unsort() { unsort ( 0, _size ); } //整体置乱
    int deduplicate(); //无序去重 (vector_deduplicate.h)
    int uniquify(); //有序去重 (vector_uniquify.h)

    // Traversal
    void traverse ( void (* ) ( T& ) ); //遍历（使用函数指针，只读或局部性修改）
    template <typename VST> void traverse ( VST& ); //遍历（使用函数对象，可全局性修改） (vector_traverse.h)
}; //Vector

#include "vector_implementation.h"

#endif //VECTOR_VECTOR_H
