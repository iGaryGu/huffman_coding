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

void priority_queue::dump() {
    for(int i = 0; i < mPQ.size(); i++) {
        printf("[PQ][%c] = %d\n", mPQ[i].mch, mPQ[i].mfreq);
    }
}

void priority_queue::uninit() {


}
