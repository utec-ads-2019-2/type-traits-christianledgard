#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    unsigned int count;

    Node(T data) : data(data) {
        next = nullptr;
        count = 0;
    }
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }
    
    delete this;
}


#endif