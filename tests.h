#pragma once

#include <cassert>
#include "Array&&List.h"
#include "ImmutableLinkedList.h"

void Test(Sequence<int> *sequence) {
    LinkedList<int> list;
    list.PushBack(1);
    list.PushFront(2);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);

    list.PushBack(3);
    list.PushBack(4);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);
    assert(list.Get(2) == 3);
    assert(list.Get(3) == 4);
    assert(list.GetFirst() == 2);
    assert(list.GetLast() == 4);

    list.PushBack(5);
    list.PushBack(6);
    assert(list.Get(0) == 2);
    assert(list.Get(1) == 1);
    assert(list.Get(2) == 3);
    assert(list.Get(3) == 4);
    assert(list.Get(4) == 5);
    assert(list.Get(5) == 6);
    assert(list.GetFirst() == 2);
    assert(list.GetLast() == 6);


    DynamicArray<int> dynArray;

    dynArray.PushBack(1);
    dynArray.PushBack(2);
    dynArray.PushBack(3);

    assert(dynArray.Size() == 3);
    assert(dynArray[0] == 1);
    assert(dynArray[1] == 2);
    assert(dynArray[2] == 3);

    dynArray.Clear();

    assert(dynArray.Size() == 0);
    assert(sequence->Size() == 0);

    sequence->PushBack(10);
    sequence->PushBack(20);

    assert((*sequence)[0] == 10);
    assert((*sequence)[1] == 20);

    Array<int> array;
    List<int> llist;
    Sequence<int> *sequence2 =
            sequence == dynamic_cast<List<int> *>(sequence) ? static_cast<Sequence<int> *>(&array)
                                                            : static_cast<Sequence<int> *>(&llist);
    sequence2->PushBack(10);
    sequence2->PushBack(20);

    sequence->Insert(0, 5);
    assert((*sequence)[0] == 5);
    assert((*sequence)[1] == 10);
    assert((*sequence)[2] == 20);

    sequence->Clear();
    assert(sequence->Size() == 0);


}