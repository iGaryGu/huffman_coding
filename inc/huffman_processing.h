#ifndef _HUFFMAN_PROCESSING_H_
#define _HUFFMAN_PROCESSING_H_

#include "common.h"
#include "priority_queue.h"
#include <string>
#include <unordered_map>

using namespace std;

class huffman_processing {
public:
    void init(priority_queue&& pq);
    void generateHuffman();
    void encode(const char* in_path, const char* out_path);
    void decode();
    void uninit();
    void dump();
private:
    void traverse(huffmanNode* node, string s);
    priority_queue mMin;
    huffmanNode* mhead;
    unordered_map<char, string> mMap;
    string mEncodeBitStream;

};


#endif
