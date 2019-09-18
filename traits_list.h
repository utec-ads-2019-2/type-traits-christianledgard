#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
        unsigned int nodesSize;

        bool find(T data, Node<T> **&ptr) {
            ptr = &head;
            while(*ptr != nullptr) {
                if (cmp((*ptr)->data, data)) {
                    if ((*ptr)->data == data)
                        return true;
                }
                else return false;
                ptr = &((*ptr)->next);
            }
            return false;
        }
              
    public:
        TraitsList() : head(nullptr), nodesSize(0){};
             
        bool insert(T data) {
            Node<T> **ptr = nullptr;
            if(!this->find(data,ptr)){
                auto * newNode = new Node<T>(data);
                newNode->next = *ptr;
                *ptr = newNode;
                nodesSize++;
                return true;
            }
            return false;
        }
             
        bool remove(T data) {
            Node<T> **ptr = &head;
            if(find(data,ptr)){
                Node<T>* temp = *ptr;
                *ptr = (*ptr)->next;
                delete temp;
                nodesSize--;
                temp = nullptr;
                return true;
            }
            return false;
        }

        bool find(T data) {
            Node<T> **ptr = nullptr;
            return find(data,ptr);
        }

        T operator [] (int index) {
            if (getSize() >= 0 && index < getSize()){
                auto temp = head;
                for (unsigned int i = 0; i < index; ++i)  temp = temp->next;
                return temp->data;
            }else
                throw std::out_of_range("Index out of range.");
        }
             
        int getSize() {
            return nodesSize;
        }

        void print() {
            auto temp = head;
            for (unsigned int i = 0; i < getSize(); ++i, temp = temp->next)
                cout << temp->data << endl;
        }

        ~TraitsList() {
            if (head != nullptr)
                head->killSelf();
        }         
};

#endif