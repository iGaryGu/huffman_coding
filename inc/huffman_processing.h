#ifndef _HUFFMAN_PROCESSING_H_
#define _HUFFMAN_PROCESSING_H_

#include "common.h"
#include "priority_queue.h"

class huffman_processing {
public:
    void init(priority_queue&& pq);
    void generateHuffman();
    void encode();
    void decode();
    void uninit();
    void dump();
private:
    priority_queue mMin;
    huffmanNode* mhead;

};


#endif
