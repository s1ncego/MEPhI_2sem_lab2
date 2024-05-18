#pragma once

template<typename T>
T helpFunc(T &value) {
    value++;

    return value;
}

template<typename T>
class DynamicArray {
private:
    Array<T> array;

public:
    DynamicArray() = default;

    DynamicArray(const DynamicArray &other) : array(other.array) {}

    ~DynamicArray() = default;

    size_t Size() const {
        return array.Size();
    }

    size_t Capacity() const {
        return array.Capacity();
    }

    void Clear() {
        array.Clear();
    }

    void Resize(size_t newSize) {
        array.Resize(newSize);
    }

    void PushBack(const T &value = 0) {
        array.PushBack(value);
    }

    void PopBack() {
        array.PopBack();
    }

    void Map(){
        for (size_t i = 0; i < array.Size(); ++i) {
            helpFunc(array[i]);
        }
    }

    T &operator[](const size_t i) {
        return array[i];
    }

    const T &operator[](const size_t i) const {
        return array[i];
    }

    class Iterator {
    private:
        const DynamicArray<T> &array;
        size_t currentIndex;
    public:
        Iterator(const DynamicArray<T> &arr, size_t startIndex = 0) : array(arr), currentIndex(startIndex) {}

        bool hasNext() const {
            return currentIndex < array.Size();
        }

        T next() {
            if (!hasNext()) {
                throw std::out_of_range("Out of range!");
            }
            return array[currentIndex++];
        }
    };

    Iterator begin() const {
        return Iterator(*this);
    }

    Iterator end() const {
        return Iterator(*this, *this->Size() - 1);
    }
};

template<typename T>
class LinkedList {
private:
    List<T> list;

public:
    LinkedList() = default;

    ~LinkedList() = default;

    LinkedList(const LinkedList<T> &other) {
        list = other.list;
    }

    size_t Size() const {
        return list.Size();
    }

    void Clear() {
        list.Clear();
    }

    T Get(size_t i) const {
        return list[i];
    }

    T GetFirst() const {
        return list[0];
    }

    T GetLast() const {
        return list[list.Size() - 1];
    }

    List<T> *GetSubList(size_t start, size_t end) {
        return new List<T>(list.GetSubList(start, end));
    }

    size_t GetLength() const {
        return list.Size();
    }

    void PushFront(const T &value) {
        list.Insert(0, value);
    }

    void PushBack(const T &value) {
        list.PushBack(value);
    }

    void PopBack() {
        list.PopBack();
    }

    void Insert(size_t index, const T &value) {
        list.Insert(index, value);
    }

    void Erase(size_t index) {
        list.Erase(index);
    }

    void Map(){
        for (size_t i = 0; i < list.Size(); ++i) {
            helpFunc(list[i]);
        }
    }

    LinkedList<T> &operator=(const List<T> &other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    class Iterator {
    private:
        const LinkedList<T> &llist;
        size_t currentIndex;
    public:
        Iterator(const LinkedList<T> &ll, size_t startIndex = 0) : llist(ll), currentIndex(startIndex) {}

        bool hasNext() const {
            return currentIndex < llist.Size();
        }

        T next() {
            if (!hasNext()) {
                throw std::out_of_range("Out of range!");
            }
            return llist[currentIndex++];
        }
    };

    Iterator begin() const {
        return Iterator(*this);
    }

    Iterator end() const {
        return Iterator(*this, *this->Size() - 1);
    }
};