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

//    auto V6=V2;
//    cout<<V6.search(V6[5])<<endl;
//    V6.traverse(visit);
//    for(int i=0;i<5;i++) {
//        int rNum = getRandNum(0, 50);
//        V6.insert(V6.search(rNum + 1), rNum);
//    }
//    V6.traverse(visit);
//    V6.uniquify();
//    V5.traverse(visit);
//    cout<<"*****************************************************"<<endl;



    return 0;
}