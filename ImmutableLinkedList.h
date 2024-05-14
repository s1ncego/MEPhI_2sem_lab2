#pragma once

template<typename T>
class ImmutableLinkedList : public Sequence<T> {
private:
    struct Node {
        T value;
        Node *next;

        Node(const T &value) : value(value), next(nullptr) {}
    };

    Node *head;
    size_t size;

public:
    ImmutableLinkedList() : head(nullptr), size(0) {}

    ~ImmutableLinkedList() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    ImmutableLinkedList(const ImmutableLinkedList &other) : head(nullptr), size(0) {
        Node *other_current = other.head;
        Node *this_last = nullptr;
        while (other_current) {
            Node *new_node = new Node(other_current->value);
            if (!head) {
                head = new_node;
            } else {
                this_last->next = new_node;
            }
            this_last = new_node;
            other_current = other_current->next;
            ++size;
        }
    }

    [[nodiscard]] size_t Size() const {
        return size;
    }

    const T &operator[](const size_t i) const {
        if (i >= size) {
            throw std::out_of_range("Out of range");
        }
        Node *current = head;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        return current->value;
    }

    ImmutableLinkedList &operator=(const ImmutableLinkedList &other) {
        if (this == &other) return *this;

        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;

        Node *other_current = other.head;
        Node *this_last = nullptr;
        while (other_current) {
            Node *new_node = new Node(other_current->value);
            if (!head) {
                head = new_node;
            } else {
                this_last->next = new_node;
            }
            this_last = new_node;
            other_current = other_current->next;
            ++size;
        }

        return *this;
    }
};
