#include <iostream>
using namespace std;

template<class T>
class solution {
public:
    class singlyLl {
    public:
        struct node {
            T data;
            node* ptr;
        };
        node* head = nullptr;
        node* tail = nullptr;
        singlyLl() {
            head = NULL;
            tail = NULL;
        }
        void addElementFirst(T x) {
            if (!head) {
                head = tail = new node;
                head->data = x;
                head->ptr = NULL;
            }
            else {
                node* temp = new node;
                temp->data = x;
                temp->ptr = head;
                head = temp;
            }
        }
        
        void addElement(T x) {
            if (!head) {
                head = new node;
                head->data = x;
                head->ptr = nullptr;
                tail = head;
            }
            else {
                node* temp = new node;
                temp->data = x;
                temp->ptr = nullptr;
                tail->ptr = temp;
                tail = temp;
            }
        }
        void travelLl() {
            node* t = head;
            while (t) {
                cout << t->data << " ";
                t = t->ptr;
            }
        }
        void deleteElement(T a) {
            if (!(head)) {
                return;
            }
            if (head->data == a) {
                node* temp = head;
                head = head->ptr;
                delete temp;
                return;
            }
            node* t = head;
            while (t) {
                if (t->ptr->data == a) {
                    node* tempt = t;
                    t->ptr = tempt->ptr->ptr;
                    break;
                }
                t = t->ptr;
            }
        }
    };

    class doublyLl {
    public:
        struct Node {
            T data;
            Node* next;
            Node* pre;
        };
        Node* head = nullptr;
        Node* tail = nullptr;
        doublyLl() {
            head = NULL;
            tail = NULL;
        }
        void addElement(T val) {
            if (!head) {
                head = tail = new Node;
                head->data = val;
                head->next = NULL;
                head->pre = NULL;
            }
            else {
                Node* newnode = new Node;
                newnode->data = val;
                tail->next = newnode;
                newnode->next = NULL;
                newnode->pre = tail;
                tail = newnode;
            }
        }
        void travelDoublyLl() {
            Node* t = head;
            while (t) {
                cout << t->data << " ";
                t = t->next;
            }
        }
        void deleteDoubly(T a) {
            Node* t = head;
            if (t && t->data == a) {
                head = t->next;
                if (head)
                    head->pre = nullptr;
                delete t;
                return;
            }
            Node* p = nullptr;
            while (t) {
                if (t->data == a) {
                    p->next = t->next;
                    if (t->next)
                        t->next->pre = p;
                    if (t == tail)
                        tail = p;
                    delete t;
                    break;
                }
                p = t;
                t = t->next;
            }
        }
    };

    class circularLl {
    public:
        struct node {
            T data;
            node* ptr;
        };
        node* head;
        node* tail;
        circularLl() {
            head = NULL;
            tail = NULL;
        }
        void addCircularElement(T x) {
            if (!head) {
                head = tail = new node;
                head->data = x;
                head->ptr = NULL;
            }
            else {
                node* temp = new node;
                temp->data = x;
                tail->ptr = temp;
                tail = temp;
                tail->ptr = head;
            }
        }
        void travelCircularLl() {
            node* t = head;
            if (t) {
                do {
                    cout << t->data << " ";
                    t = t->ptr;
                } while (t != head);
            }
        }
        void deleteCircularElement(T a) {
            if (!head) {
                return;
            }
            if (head->data == a) {
                node* temp = head;
                head = head->ptr;
                tail->ptr = head;
                delete temp;
                return;
            }
            node* t = head;
            while (!(t == tail)) {
                if (t->ptr->data == a) {
                    node* tempt = t;
                    t->ptr = tempt->ptr->ptr;
                    break;
                }
                t = t->ptr;
            }
        }
    };
        class dynamicArray {
    public:
        int cnt = 0;
        T* arr = nullptr;
        
        dynamicArray() {
            arr = new T[1];
        }
        
        void addArray(T a) {
            if (cnt == (1 << cnt) - 1) {
                T* temp = new T[2 * (1 << cnt)];
                for (int i = 0; i < cnt; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
            }
            arr[cnt] = a;
            cnt++;
        }
        
        void arrayTravel() {
            for (int i = 0; i < cnt; i++) {
                cout << arr[i]<< " ";
            }
        }
        
        ~dynamicArray() {
            delete[] arr;
        }
        void deleteArray(T a){
            for(int i=0; i<cnt; i++){
                if(arr[i]==a){
                    for(int j=i; j<cnt; j++){
                        arr[i]=arr[j+1];
                    }
                }
            }
        }
    };
    class stack: public singlyLl {
    public:
        void pushstk(T x) {
            this->addElementFirst(x);
        }
        
        void travelstk() {
            this->travelLl();
        }
    };
};

int main() {
    cout << "singly";
    solution<int>::singlyLl list1;
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

    cout << "doubly";
    solution<int>::doublyLl list2;
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
    cout << "circular";
    solution<int>::circularLl list3;
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
    cout << endl << "Dynamic array";
    solution<int>::dynamicArray obj1;
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
    solution<int>::stack stk;
    stk.pushstk(1);
    stk.pushstk(2);
    stk.pushstk(3);
    stk.pushstk(4);
    stk.pushstk(5);
    stk.travelstk();
    cout <<endl<< "close all";
    return 0;
}
