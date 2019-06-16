#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "common.h"

#include <vector>

using namespace std;

class huffman_processing;
// use vector to implement min-heap
// start from index 1

class priority_queue {
public:
    friend class huffman_processing;
   void init(Record&& record);
   void generatePQ();
   void push(Item item, int *n);
   Item pop(int *n);
   void uninit();
   // debug usage
   void dump();

private:
   vector<Item> mPQ;
   Record mContent;
};

#endif
