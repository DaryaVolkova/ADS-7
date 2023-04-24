// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
    struct SYM* next;
};

template<typename T>
class TPQueue {
 private:
    T* head = nullptr;

 public:
    bool isEmpty() const {
        return !head;
    }

    const T& pop() {
        if (isEmpty()) {
            throw std::string("Empty!");
        } else {
            T* tmp = head;
            head = head->next;
            return *tmp;
        }
    }

    void push(const T& arg) {
        if (isEmpty()) {
            head = new T;
            head->next = nullptr;
            head->ch = arg.ch;
            head->prior = arg.prior;
        } else {
            if (head->prior < arg.prior) {
                T* v = new T;
                v->ch = arg.ch;
                v->prior = arg.prior;
                v->next = head;
                head = v;
        } else {
            if (!head->next) {
                T* v = new T;
                v->ch = arg.ch;
                v->prior = arg.prior;
                head->next = v;
                v->next = nullptr;
            } else {
                T* cur = head;
                while (cur->next && cur->next->prior >= arg.prior) {
                    cur = cur->next;
                }
                if (!cur->next) {
                    T* v = new T;
                    v->ch = arg.ch;
                    v->prior = arg.prior;
                    cur->next = v;
                    v->next = nullptr;
                } else {
                    if (cur->next->prior < arg.prior) {
                        T* v = new T;
                        v->ch = arg.ch;
                        v->prior = arg.prior;
                        v->next = cur->next;
                        cur->next = v;
                    }
                }
            }
            }
        }
    }
};
#endif  // INCLUDE_TPQUEUE_H_
