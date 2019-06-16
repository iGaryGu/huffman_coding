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
    traverse(mhead, string(""));
    //printf("head total cnt : %d\n", mhead->mfreq);
}

void huffman_processing::traverse(huffmanNode* node, string s) {
    
    if (node->left != nullptr) {
        traverse(node->left, s+"0");
    }
    if (node->left == nullptr && node->right == nullptr) {
        // leaf node and create new code for character
//        printf("\tCodebook, [char]: %c = %s\n", node->mch, s.c_str());
        mMap[node->mch] = s;
        return;
    }
    if (node->right != nullptr) {
        traverse(node->right, s+"1");
    }

}

void huffman_processing::encode(const char* in_path, const char* out_path) {
    file_ops in, out;
    char ch;
    size_t count = 0;

    if (!in.open(in_path, true)) {
        printf("file(%s) open failed!\n", in_path);
        exit(1);
    }
    if (!out.open(out_path, false)) {
        printf("file(%s) open failed!\n", out_path);
        exit(1);
    }
    
    while((ch = in.readChar()) != EOF) {
        auto temp = mMap[ch];
        mEncodeBitStream += temp;
        count++;
    }
//    printf("length = %zu, count = %zu origin bit = %zu\n", mEncodeBitStream.length(), count, count * 8);
    out.output(mEncodeBitStream); 
}

void huffman_processing::decode() {

}

void huffman_processing::dump() {
    //traversal the huffman tree
}

void huffman_processing::uninit() {

}
