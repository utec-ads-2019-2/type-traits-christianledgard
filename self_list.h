#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;

    public:
        SelfList(Method method) : head(nullptr) {};

        bool insert(T data) {
            // TODO
        }
             
        bool remove(T data) {
            // TODO
        }  

        bool find(T data) {
            // TODO
        }

        T operator [] (int index) {
            // TODO
        }
             
        int size() {
            // TODO
        }

        void print() {
            // TODO
        }

        ~SelfList() {
            // TODO
        }  
};

#endif