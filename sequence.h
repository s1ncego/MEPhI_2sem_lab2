#pragma once

#include <iostream>

template<typename T>
class Sequence {
public:
    virtual ~Sequence() = default;

    virtual size_t Size() const = 0;

    virtual void Clear() = 0;

    virtual void PushBack(const T &value) = 0;

    virtual void PopBack() = 0;

    virtual void Insert(size_t index, const T &value) = 0;

    virtual bool Erase(size_t index) = 0;

    virtual T &operator[](size_t i) = 0;

    virtual const T &operator[](size_t i) const = 0;
};


template<typename T>
class List : public Sequence<T> {
private:
    struct Node {
        T value;
        Node *next;

        Node(const T &value) : value(value), next(nullptr) {}
    };

    Node *head;
    size_t size = 0;

public:
    List() : head(nullptr), size(0) {}

    ~List() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    size_t Size() const {
        return size;
    }

    void Clear() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    void PushBack(const T &value) {
        if (!head) {
            head = new Node(value);
        } else {
            Node *current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(value);
        }
        size++;
    }

    void PopBack() {
        if (!head) {
            return;
        }
        Node *current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        size--;
    }

    void Insert(size_t index, const T &value) {
        if (index > size) {
            throw std::out_of_range("Out of range");
        }
        if (index == 0) {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        } else {
            Node *current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            Node *newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    bool Erase(size_t index) {
        if (index > size) {
            throw std::out_of_range("Out of range!");
        }
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
        } else {
            Node *current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }

        size--;
        return true;
    }

    T &operator[](const size_t i) {
        Node *current = head;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        return current->value;
    }

    const T &operator[](const size_t i) const {
        Node *current = head;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        return current->value;
    }

    bool operator==(const List &list) const {
        if (size != list.size) return false;
        Node *current = head;
        Node *list_curr = list.head;
        while (current) {
            if (current->value != list_curr->value) return false;
            current = current->next;
            list_curr = list_curr->next;
        }
        return true;
    }

    bool operator!=(const List &list) const {
        return *this != list;
    }

    bool operator<(const List &list) const {
        size_t minimum = std::min(list.size, size);
        for (size_t i = 0; i < minimum; ++i) {
            if ((*this)[i] < list[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator>(const List &list) const {
        return list < *this;
    }

    bool operator<=(const List &list) const {
        return *this <= list;
    }

    bool operator>=(const List &list) const {
        return *this >= list;
    }

    friend std::ostream &operator<<(std::ostream &ostream, const List &list) {
        ostream << "LinkedList's size is " << list.size << ", elements: ";
        Node *current = list.head;
        while (current) {
            ostream << current->value << ", ";
            current = current->next;
        }
        return ostream;
    }

};

template<typename T>
class Array : public Sequence<T> {
private:
    size_t size;
    size_t capacity;
    T *value;

public:
    Array() : size(0), capacity(2), value(new T[2]) {}

    Array(const Array &array) : size(array.size_), capacity(array.capacity_), value(new T[capacity]) {
        std::copy(array.value, array.value + size, value);
    }

    ~Array() {
        delete[] value;
    }

    size_t Size() const {
        return size;
    }

    size_t Capacity() const {
        return capacity;
    }

    void Clear() {
        delete[] value;
        value = new T[capacity];
        size = 0;
    }

    void Reserve(size_t newCapacity) {
        if (newCapacity <= capacity) {
            return;
        }
        T *temp = new T[newCapacity];
        std::copy(value, value + size, temp);
        delete[] value;
        value = temp;
        capacity = newCapacity;
    }

    void Resize(size_t newSize) {
        if (newSize == size) {
            return;
        } else if (newSize > capacity) {
            Reserve(newSize * 2);
        } else if (newSize < size) {
            for (size_t i = newSize; i < size; ++i) {
                value[i].~T();
            }
        }
        size = newSize;
    }

    void PushBack(const T &val = 0) {
        if (size == capacity) {
            Reserve(capacity * 2);
        }
        value[size++] = val;
    }

    void PopBack() {
        if (size == 0) {
            throw std::out_of_range("Array is empty!");
        }
        value[size - 1].~T();
    }

    void Insert(size_t index, const T &val) {
        if (index > size) {
            throw std::out_of_range("Out of range!");
        } else if (size == capacity) {
            Reserve(capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            value[i] = value[i - 1];
        }
        value[index] = *value;
        size++;
    }

    bool Erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Out of range!");
        }
        for (size_t i = index; i < size - 1; ++i) {
            value[i] = value[i + 1];
        }
        size--;
        return true;
    }

    T &operator[](const size_t i) {
        return value[i];
    }

    const T &operator[](const size_t i) const {
        return value[i];
    }

    explicit operator bool() const {
        return size > 0;
    }

    bool operator==(const Array &arr) const {
        if (size != arr.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if ((*this)[i] != arr[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Array &arr) const {
        return *this != arr;
    }

    bool operator<(const Array &arr) const {
        size_t minimum = std::min(arr.size, size);
        for (size_t i = 0; i < minimum; ++i) {
            if ((*this)[i] < arr[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator>(const Array &arr) const {
        return arr < *this;
    }

    bool operator<=(const Array &arr) const {
        return *this <= arr;
    }

    bool operator>=(const Array &arr) const {
        return *this >= arr;
    }

    Array &operator<<(const Array &it) {
        size_t temp = size;
        Resize(size + it.size_);
        for (size_t i = temp; i < size; ++i) {
            (*this)[i] = it[i - temp];
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &ostream, const Array &array) {
        ostream << "Array's capacity is " << array.capacity << " and size: " << array.size
                << ", elements: ";
        for (size_t i = 0; i < array.size; ++i) {
            ostream << array[i] << ", ";
        }
        return ostream;
    }


};

template<typename T>
std::ostream &operator<<(std::ostream &ostream, const Array<T> &array) {
    ostream << "Array's capacity is " << array.capacity << " and size: " << array.size << ", elements are: ";
    for (size_t i = 0; i < array.size; ++i) {
        ostream << array[i] << ", ";
    }
    return ostream;
}



