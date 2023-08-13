#include<iostream>
#include "List.h"

using namespace std;

int main() {
    cout << "singly"<<endl;
    List<int>::singlyLl list1;
    list1.addElementFirst(501);
    list1.addElement(1);
    list1.addElement(2);
    list1.addElement(3);
    list1.addElement(1000);
    list1.addElement(4);
    list1.addElementFirst(502);
    list1.addElementFirst(503);
    list1.travelLl();
    list1.deleteElement(1);
    cout<<endl<<"delete 1 from singly";
    cout << endl;
    list1.travelLl();
    cout << endl;

    cout << "doubly"<<endl;
    List<int>::doublyLl list2;
    list2.addElement(1);
    list2.addElement(2);
    list2.addElement(100);
    list2.addElement(20);
    list2.travelDoublyLl();
    list2.deleteDoubly(1);
    cout<<endl<<"delete 1 from doubly";
    cout << endl;
    list2.travelDoublyLl();
    cout << endl;
    cout << "circular"<<endl;
    List<int>::circularLl list3;
    list3.addCircularElement(1);
    list3.addCircularElement(2);
    list3.addCircularElement(100);
    list3.addCircularElement(15);
    list3.addCircularElement(56);
    list3.travelCircularLl();
    list3.deleteCircularElement(56);
    cout<<endl<<"delete 56 from circular";
    cout << endl;
    list3.travelCircularLl();
    cout << endl << "Dynamic array"<<endl;
    List<int>::dynamicArray obj1;
    obj1.addArray(1);
    obj1.addArray(2);
    obj1.addArray(3);
    obj1.addArray(4);
    obj1.addArray(0);
    obj1.addArray(51);
    obj1.arrayTravel();
    obj1.deleteArray(0);
    cout<<endl<<"delete 0 from array"<<endl;
    obj1.arrayTravel();
    cout<<endl<<"stack"<<endl;
    List<int>::stack stk;
    stk.pushstk(1);
    stk.pushstk(2);
    stk.pushstk(3);
    stk.pushstk(4);
    stk.pushstk(5);
    stk.travelstk();
    cout <<endl;
    cout<<"POP"<<endl<<stk.pop()<<endl;
    stk.travelstk();
    cout<<endl<<"Queue"<<endl;
    
    List<int>::queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);
    Q.travelQ();
    cout<<endl;
    cout<<"DEQUEUE"<<endl<<Q.dequeue()<<endl;
    Q.travelQ();
    cout <<endl<< "close all";
    return 0;
}