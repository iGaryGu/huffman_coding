#include "huffman_processing.h"

void huffman_processing::init(priority_queue&& pq) {
    mMin = pq;
    mhead = nullptr;
}

void huffman_processing::generateHuffman() {
    int index = 1;
    int size = mMin.mPQ.size() - 1;
    int end = mMin.mPQ.size() - 1;
    Item first, second;
    while(size >= 2) {
        first = mMin.pop(&size);
        if (first.mfreq == 0) first = mMin.pop(&size);
        second = mMin.pop(&size);
        if (second.mfreq == 0) second = mMin.pop(&size);
//        printf("first : [%c] = %d , second : [%c] = %d\n", 
//                first.mch, first.mfreq, second.mch, second.mfreq);
        int freq = first.mfreq + second.mfreq;
        huffmanNode* node = new huffmanNode(freq, 0);
        if (!first.virtualNode)
            node->left = new huffmanNode(first.mfreq, first.mch);
        else
            node->left = first.node;
        if (!second.virtualNode)
            node->right = new huffmanNode(second.mfreq, second.mch);
        else
            node->right = second.node;

        Item item = Item(node, freq, true);
        mMin.push(item, &size);
        mhead = item.node;
    }
    //printf("head total cnt : %d\n", mhead->mfreq);
}

void huffman_processing::encode() {


}

void huffman_processing::decode() {

}

void huffman_processing::dump() {
    //traversal the huffman tree
}

void huffman_processing::uninit() {

}
