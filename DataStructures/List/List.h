#ifndef ALGORITHMSANDDATASTRUCTURES_LIST_H
#define ALGORITHMSANDDATASTRUCTURES_LIST_H

#include <memory>

namespace my {

    template<class T>
    class List {
        class Iterator;

        class ConstIterator;

    public:
        using value_type = T;
//        using allocator_type =
        using size_type = std::size_t;
//        using difference_type =     /* your code */;
        using reference = value_type &;
        using const_reference = const value_type &;
//        using pointer =
//        using const_pointer =
        using iterator = Iterator;
        using const_iterator = ConstIterator;

        List() : size(0u), begin(nullptr), end(nullptr) {}

        List(const List<T> &other);

        List(List<T> &&other) noexcept;

        List(std::initializer_list<T> src);

        ~List();

        List &operator=(const List<T> &other) &;

        List &operator=(List<T> &&other) & noexcept;

        bool isEmpty() const;

        void clear();


        reference front();

        const_reference front() const;

        reference back();

        const_reference back() const;

        void pushBack(const T &value);

        void pushBack(T &&value);

    private:

        struct ElemList {
            T data_;
            ElemList *nextElem_;
            ElemList *prevElem;
        };


        class Iterator {

        };

        class ConstIterator {

        };

        void copyList(const List<T> &other);

        void swap(List<T> &other);

    private:
        ElemList *begin;
        ElemList *end;
        size_t size;

    };

    template<class T>
    List<T>::List(const List<T> &other) : List() {
        copyList(other);
    }

    template<class T>
    List<T>::List(List<T> &&other) noexcept : List() {
        other.swap(*this);
    }

    template<class T>
    List<T>::List(std::initializer_list<T> src) : List() {
        const T *temp = src.begin();
        while (temp != src.end()) {
            pushBack(*temp);
            ++temp;
        }
    }

    template<class T>
    List<T> &List<T>::operator=(const List<T> &other) &{
        if (this == &other) {
            return *this;
        }
        if (!isEmpty()) {
            clear();
        }
        copyList(other);
        return *this;
    }

    template<class T>
    List<T> &List<T>::operator=(List<T> &&other) & noexcept {
        if (this == &other) {
            return *this;
        }
        other.swap(*this);
        return *this;
    }

    template<class T>
    List<T>::~List() {
        clear();
        //TODO(check memory leaks)
    }

    template<class T>
    void List<T>::copyList(const List<T> &other) {
        if (other.size == 0) {
            size = 0;
            begin = nullptr;
            end = nullptr;
            return;
        }
        auto otherElem = other.begin;
        begin = new ElemList;
        begin->data_ = otherElem->data_;
        begin->nextElem_ = nullptr;
        begin->prevElem = nullptr;
        end = begin;
        size = 1;

        while (otherElem != other.end) {
            otherElem = otherElem->nextElem_;

            auto newElem = new ElemList;

            newElem->data_ = otherElem->data_;
            newElem->nextElem_ = nullptr;
            newElem->prevElem = end;
            end->nextElem_ = newElem;
            end = newElem;
            size++;
        }
    }

    template<class T>
    void List<T>::swap(List<T> &other) {
        std::swap(begin, other.begin);
        std::swap(end, other.end);
        std::swap(size, other.size);
    }

    template<class T>
    bool List<T>::isEmpty() const {
        return begin == nullptr;
    }

    template<class T>
    void List<T>::clear() {
        auto elem = begin;
        while (elem != nullptr) {
            auto tmp = elem;
            elem = elem->nextElem_;
            delete tmp;
        }
        //TODO(check memory leaks)
    }

    template<class T>
    void List<T>::pushBack(const T &value) {
        auto newElem = new ElemList;
        newElem->data_ = value;
        newElem->nextElem_ = nullptr;
        size++;
        if (isEmpty()) {
            begin = newElem;
            end = newElem;
            newElem->prevElem = nullptr;
            return;
        }
        end->nextElem_ = newElem;
        newElem->prevElem = end;
        end = newElem;
    }

    template<class T>
    void List<T>::pushBack(T &&value) {
        auto newElem = new ElemList;
        newElem->data_ = std::move(value);
        newElem->nextElem_ = nullptr;
        size++;
        if (isEmpty()) {
            begin = newElem;
            end = newElem;
            newElem->prevElem = nullptr;
            return;
        }
        end->nextElem_ = newElem;
        newElem->prevElem = end;
        end = newElem;
    }

}

#endif //ALGORITHMSANDDATASTRUCTURES_LIST_H
