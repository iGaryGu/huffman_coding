#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

#include <vector>

using namespace std;

struct Item {
    char mch;
    int mfreq;
    Item()
        : mch(' '),
        mfreq(0)
    {}
    Item(char ch, int freq)
        : mch(ch),
        mfreq(freq)
    {}
};

// use vector to implement min-heap
// start from index 1

class priority_queue {
public:
   void init(Record&& record);
   void generatePQ();
   void uninit();
   // debug usage
   void dump();

private:
   void push(Item item, int *n);
    vector<Item> mPQ;
    Record mContent;
};

#endif
