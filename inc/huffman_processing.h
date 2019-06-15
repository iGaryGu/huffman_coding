#ifndef _HUFFMAN_PROCESSING_H_
#define _HUFFMAN_PROCESSING_H_

class huffman_processing {
public:
    class huffman_tree {
        public:
            huffman_tree()
                :freq(0),
                c(' '),
                right(nullptr),
                left(nullptr)
            {}

        private:
            int freq;
            char c;
            huffman_tree* right;
            huffman_tree* left;
    };

public:
    void init(priority_queue&& pq);
    void encode();
    void decode();
    void uninit();
private:
    priority_queue mMin;

};


#endif
