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
    void decode(const char* in_file, const char* out_file);
    void uninit();
    void dump();
private:
    void traverse(shared_ptr<huffmanNode> node, string s);
    void parse(file_ops& in_file, shared_ptr<huffmanNode> node);
    priority_queue mMin;
    shared_ptr<huffmanNode> mhead;
    unordered_map<char, string> mMap;
    string mEncodeBitStream;
    string mDecodeBitStream;

};


#endif
