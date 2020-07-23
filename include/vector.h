/******************************************************************************************
 * Data Structures in C++
 * Created by laoqin on 2020/7/2.
 ******************************************************************************************/

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "util.h"
typedef int Rank; //��
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ����

template <typename T> class Vector { //����ģ����
protected:
    Rank _size; int _capacity;  T* _elem; //��ģ��������������
    void copyFrom ( T const* A, Rank lo, Rank hi ); //������������A[lo, hi)
    void expand(); //�ռ䲻��ʱ���� (vector_expand.h)
    void shrink(); //װ�����ӹ�Сʱѹ�� (vector_shrink.h)
    void bubbleSort ( Rank lo, Rank hi ); //���������㷨 (vector_bubblesort.h)
    Rank max ( Rank lo, Rank hi ); //ѡȡ���Ԫ�� (vector_selectionSort.h)
    void selectionSort ( Rank lo, Rank hi ); //ѡ�������㷨 (vector_selectionSort.h)
    void merge ( Rank lo, Rank mi, Rank hi ); //�鲢�㷨 (vector_merge.h)
    void mergeSort ( Rank lo, Rank hi ); //�鲢�����㷨 (vector_mergeSort.h)
    void heapSort ( Rank lo, Rank hi ); //������ (vector_heapSort.h) Todo
    Rank partition ( Rank lo, Rank hi ); //��㹹���㷨 (vector_partition.h)
    void quickSort ( Rank lo, Rank hi ); //���������㷨 (vector_quickSort.h)
    void shellSort ( Rank lo, Rank hi ); //ϣ�������㷨 (vector_shellSort.h)
    Rank Vector<T>::binSearch(const T& e,Rank lo,Rank hi); // (vector_search_binary.h)
public:

    // Constructor
    Vector ( int c = DEFAULT_CAPACITY, int s = 0, T v = 0 ) { //����Ϊc����ģΪs������Ԫ�س�ʼΪv
        _elem = new T[_capacity = c];
        for ( _size = 0; _size < s; _elem[_size++] = v );
    } //s<=c
    Vector ( T const* A, Rank n ) { //�������帴��
        copyFrom ( A, 0, n ); }
    Vector ( T const* A, Rank lo, Rank hi ) { //����
        copyFrom ( A, lo, hi ); }
    Vector ( Vector<T> const& V ) { //�������帴��
        copyFrom ( V._elem, 0, V._size ); }
    Vector ( Vector<T> const& V, Rank lo, Rank hi ) { //����
        copyFrom ( V._elem, lo, hi ); }

    // Destructor
    ~Vector() { delete [] _elem; } //�ͷ��ڲ��ռ�

    // Read only access interface
    Rank size() const { return _size; } //��ģ
    bool empty() const { return !_size; } //�п�
    Rank find ( T const& e ) const { //���������������
        return find ( e, 0, _size );
    }
    Rank find ( T const& e, Rank lo, Rank hi ) const; //��������������� (vector_find.h)
    Rank search ( T const& e ) const { //���������������
        return ( 0 >= _size ) ? -1 : search ( e, 0, _size );
    }
    Rank search ( T const& e, Rank lo, Rank hi ) const; //��������������� (vector_search.h)

    // Writeable access interface
    T& operator[] ( Rank r ); //�����±������������������������ʽ���ø�Ԫ��
    const T& operator[] ( Rank r ) const; //����������ֵ�����ذ汾 (vector_bracket.h)
    Vector<T> & operator= ( Vector<T> const& ); //���ظ�ֵ���������Ա�ֱ�ӿ�¡���� (vector_assignment.h)
    T remove ( Rank r ); //ɾ����Ϊr��Ԫ�� (vector_remove.h)
    int remove ( Rank lo, Rank hi ); //ɾ����������[lo, hi)֮�ڵ�Ԫ�� (vector_removeInterval.h)
    Rank insert ( Rank r, T const& e ); //����Ԫ��
    Rank push_back(const T&e){ // (vector_insert.h)
        return insert(_size,e);
    }
    void sort ( Rank lo, Rank hi ); //��[lo, hi)���� (vector_sort.h)
    void sort() { sort ( 0, _size ); } //��������
    void unsort ( Rank lo, Rank hi ); //��[lo, hi)���� (vector_unsort.h)
    void unsort() { unsort ( 0, _size ); } //��������
    int deduplicate(); //����ȥ�� (vector_deduplicate.h)
    int uniquify(); //����ȥ�� (vector_uniquify.h)

    // Traversal
    void traverse ( void (* ) ( T& ) ); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
    template <typename VST> void traverse ( VST& ); //������ʹ�ú������󣬿�ȫ�����޸ģ� (vector_traverse.h)
}; //Vector

#include "vector_implementation.h"

#endif //VECTOR_VECTOR_H
