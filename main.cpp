#include <iostream>
#include <ctime>
#include"vector.h"

using std::cout;
using std::endl;

template <typename T>
void visit(T &e){
    cout<< e <<"->";
}

int main(){
    srand ( ( unsigned int ) time ( NULL ) ); //设置随机种子

    Vector<int> V;
    for(int i=0;i<10;i++){
        V.push_back(getRandNum(0,50));
    }
    V.traverse(visit);

    cout<<"V[5]="<<V[5]<<" result="<<V.find(V[5])<<endl;
    cout<<"Random number out of Vector: "<<V.find(getRandNum(50,100))<<endl;
    cout<<"*****************************************************"<<endl;

    auto V2=V;
    V2.sort();
    V2.traverse(visit);

    cout<<"V2[5]="<<V2[5]<<" result="<<V2.find(V2[5])<<endl;
    //cout<<V.search(V2[5])<<endl;
    cout<<"*****************************************************"<<endl;


    auto V3=V;
    V3.remove(5);
    V3.traverse(visit);
    cout<<"*****************************************************"<<endl;


    auto V4=V;
    V4.push_back(V4[5]);
    V4.traverse(visit);
    V4.deduplicate();
    V4.traverse(visit);
    cout<<"*****************************************************"<<endl;


    auto V5=V2;
    V5.push_back(V5[V5.size()-1]);
    V5.traverse(visit);
    V5.uniquify();
    V5.traverse(visit);
    cout<<"*****************************************************"<<endl;

    auto V6=V2;
    cout<<V6.search(V6[5])<<endl;
    V6.traverse(visit);
    for(int i=0;i<5;i++) {
        int rNum = getRandNum(0, 50);
        V6.insert(V6.search(rNum) + 1, rNum);
    }
    V6.traverse(visit);
    V6.uniquify();
    V5.traverse(visit);
    cout<<"*****************************************************"<<endl;

    cout<<"initializer_list constructor"<<endl;
    Vector<int> a({8,5,90,32,67,85});
    a.traverse(visit);
    cout<<"*****************************************************"<<endl;
    Vector<int> b{8,5,90,32,67,85};
    b.traverse(visit);
    cout<<"*****************************************************"<<endl;
    Vector<int> c={8,5,90,32,67,85}; //并未调用拷贝构造函数（因为有优化？？）
    //在编译选项中添加 -fno-elide-constructors
    //CMAKELISTS文件中添加编译选项：
    //1）add_compile_options(-fno-elide-constructors)    #关闭编译器优化
    // or
    //2）set(CMAKE_CXX_FLAGS "-fno-elide-constructors ${CMAKE_CXX_FLAGS}")
    // 仍未调用
    c.traverse(visit);
    cout<<"*****************************************************"<<endl;




    return 0;
}