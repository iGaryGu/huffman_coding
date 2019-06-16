#include "priority_queue.h"

void priority_queue::init(Record&& record) {
    mContent = record;
    mPQ.resize(mContent.mRecord.size()+1);
}

void priority_queue::generatePQ() {
    int size = 0;    
    for (auto itr = mContent.mRecord.begin(); itr != mContent.mRecord.end(); itr++) {
        Item item((*itr).first, (*itr).second);
        push(item, &size);
    }
}

void priority_queue::push(Item item, int *n) {
    int i;
    i = ++(*n);
    while((i != 1) && (item.mfreq < mPQ[i/2].mfreq)) {
        mPQ[i] = mPQ[i/2];
        i /=2;
    }
    mPQ[i] = item;
}

Item priority_queue::pop(int *n) {
    int parent, child;
    Item item, temp;
    // the smallest freqency character
    item = mPQ[1];
    // use the last item to adjust the min-heap
    temp = mPQ[(*n)--];
    parent = 1;
    child = 2;
    while(child <= (*n)) {
        if ((child < *n) && (mPQ[child].mfreq > mPQ[child+1].mfreq))
            child++;
        if (temp.mfreq <= mPQ[child].mfreq) break;
        mPQ[parent] = mPQ[child];
        parent = child;
        child *= 2;
    }
    mPQ[parent] = temp;
    return item;
}

void priority_queue::dump() {
    size_t cnt = 0;
    for(int i = 0; i < mPQ.size(); i++) {
        printf("[PQ][%c] = %d\n", mPQ[i].mch, mPQ[i].mfreq);
        cnt += mPQ[i].mfreq;
    }
    printf("all element cnt : %zu\n", cnt);
}

void priority_queue::uninit() {


}
