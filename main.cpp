//main.cpp: Use Tree ADT in main function, made by Sion Lee
//Github: sioni322, Email: sioni322@naver.com

#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    Tree t(100);

    t.insert(1, 50, 0);
    t.insert(1, 150, 1);
    t.insert(2, 25, 0);
    t.insert(2, 70, 1);
    t.insert(3, 130, 0);
    t.insert(3, 170, 1);

    std::cout << "After inserting: \n";
    t.print();
    std::cout << "\n\n";


    std::cout << "After finding 5th node: \n";
    std::cout << t.find(5) << endl;
    std::cout << "\n\n";


    vector<int> result1, result2, result3;

    t.infix(t.rootnode(), result1);
    t.postfix(t.rootnode(), result2);
    t.prefix(t.rootnode(), result3);

    std::cout << "Infix order: \n";
    for(int i=0; i<result1.size(); i++)
        cout << result1[i] << "\t";
    std::cout << "\n\n";

    std::cout << "Postfix order: \n";
    for(int i=0; i<result2.size(); i++)
        cout << result2[i] << "\t";
    std::cout << "\n\n";

    std::cout << "Prefix order: \n";
    for(int i=0; i<result3.size(); i++)
        cout << result3[i] << "\t";
    std::cout << "\n\n";


    return 0;
}