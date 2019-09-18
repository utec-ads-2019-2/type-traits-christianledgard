#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"
#include <vector>

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;
        unsigned int size;

    public:
        SelfList(Method method) : method(method), head(nullptr), size(0){};

        bool insert(T data) {
            auto newNode = new Node<T>(data);
            newNode->data = data;
            if(head != nullptr)
                newNode->next = head;
            head = newNode;
            this->size++;
        }

        bool insert(T data, int count) {
            auto newNode = new Node<T>(data);
            newNode->data = data;
            newNode->count = count;
            if(head != nullptr)
                newNode->next = head;
            head = newNode;
            this->size++;
        }
             
        bool remove(T data) {
            if(head->data == data){
                auto temp = head;
                head = temp->next;
                delete temp;
                temp = nullptr;
                this->size--;
                return true;
            }
            else{
                for (auto temp = this->head ; temp != nullptr ; temp = temp->next){
                    if (temp->data == data) {
                        auto tempAnterior = head;
                        while (tempAnterior->next != temp) tempAnterior = tempAnterior->next;
                        tempAnterior->next = temp->next;
                        delete temp;
                        temp = nullptr;
                        tempAnterior = nullptr;
                        this->size--;
                        return true;
                    }
                }
                return false;
            }

        }  

        bool find(T data) {
            switch (method) {
                case Move:
                    for (auto temp = this->head ; temp != nullptr ; temp = temp->next) {
                        if (temp->data == data) {
                            auto temp2 = head;
                            while (temp2->next != temp)
                                temp2 = temp2->next;
                            temp2->next = temp->next;
                            temp->next = head;
                            head = temp;
                            return true;
                        }
                    }
                    return false;
                case Count:
                    for (auto temp = this->head ; temp != nullptr ; temp = temp->next) {
                        if (temp->data == data) {
                            auto tempAnterior = head;
                            while (tempAnterior->next != temp) tempAnterior = tempAnterior->next;
                            temp->count++;
                            if (tempAnterior->count < temp->count) {
                                this->countSort();
                            }
                            tempAnterior = nullptr;
                            return true;
                        }
                    }
                    return false;
                case Transpose:
                    for (auto temp = this->head ; temp != nullptr ; temp = temp->next) {
                        if (temp->next->data == data) {
                            std::swap(temp->next->data, temp->data);
                            return true;
                        }
                    }
                    return false;
            }
        }

        void clear(){
            for (auto temp = this->head ; temp != nullptr ; temp = temp->next) {
                head = temp->next;
                delete temp;
                this->size--;
                if (temp->next == nullptr)
                    head = nullptr;
            }
        }

        T operator [] (int index)  {
            if (getSize() >= 0 && index < getSize()){
                auto temp = head;
                for (unsigned int i = 0; i < index; ++i)  temp = temp->next;
                return temp->data;
            }else
                throw std::out_of_range("Index out of range.");
        }

        unsigned int getSize() {
            return this->size;
        }

        void print() {
            for (auto temp = this->head ; temp != nullptr ; temp = temp->next)
                std::cout << temp->data << std::endl;
        }

        void countSort() {
            std::vector<std::pair<int, T>> vect;
            auto temp = this->head;
            for (int i = 0; temp != nullptr ; temp = temp->next, i++){
                vect.push_back(std::make_pair(temp->count,temp->data));
            }
            sort(vect.begin(), vect.end());
            this->clear();
            for (auto & element : vect) {
                this->insert(element.second,element.first);
            }
        }

    ~SelfList() {
        if(head != nullptr)
            head ->killSelf();
        }  
};

#endif