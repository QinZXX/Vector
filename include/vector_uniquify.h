#ifndef VECTOR_VECTOR_UNIQUIFY_H
#define VECTOR_VECTOR_UNIQUIFY_H

template <typename T>
int Vector<T>::uniquify() { //有序向量重复元素剔除算法
    Rank i = 0, j = 0; //各对互异“相邻”元素的秩
    while ( ++j < _size ) //逐一扫描，直至末元素
        if ( _elem[i] != _elem[j] ) //跳过雷同者
            _elem[++i] = _elem[j]; //发现不同元素时，向前移至紧邻于前者右侧
    _size = ++i;
    shrink(); //直接截除尾部多余元素
    return j - i; //向量规模变化量，即被删除元素总数
} // 空间不一定被释放 （高效）

#endif //VECTOR_VECTOR_UNIQUIFY_H
