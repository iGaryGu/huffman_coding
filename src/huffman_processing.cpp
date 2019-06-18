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
        shared_ptr<huffmanNode> node = make_shared<huffmanNode>(freq, 0);
        if (!first.virtualNode)
            node->left = make_shared<huffmanNode>(first.mfreq, first.mch);
        else
            node->left = first.node;
        if (!second.virtualNode)
            node->right = make_shared<huffmanNode>(second.mfreq, second.mch);
        else
            node->right = second.node;

        Item item = Item(node, freq, true);
        mMin.push(item, &size);
        mhead = item.node;
    }
    traverse(mhead, string(""));
    //printf("head total cnt : %d\n", mhead->mfreq);
}

void huffman_processing::traverse(shared_ptr<huffmanNode> node, string s) {
    
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
    out.output(mEncodeBitStream, true);
}

void huffman_processing::decode(const char* in_path, const char* out_path) {
    file_ops in, out;
    char ch;
    if (!in.open(in_path, true)) {
        printf("file(%s) open failed!\n", in_path);
        exit(1);
    }
    if (!out.open(out_path, false)) {
        printf("file(%s) open failed!\n", out_path);
        exit(1);
    }

    parse(in, mhead);

    out.output(mDecodeBitStream, false);

}

void huffman_processing::parse(file_ops& in_file, shared_ptr<huffmanNode> node) {
    string str;
    unsigned char byte[8] = {0};
    unsigned char mask = 1;
    string decodeBitStream;
    // restore bit stream string
    str = in_file.readBinary2string();
    size_t num_char = str.length();
    // remove '\0' : num_char-1
    for (size_t i = 0; i < num_char-1; i++) {
        for(int j = 0; j < 8; j++) {
            byte[j] = ((unsigned char)str[i] & (mask << j)) != 0 ? '1' : '0';
        }
        for (int j = 7; j >=0; j--) {
            decodeBitStream += byte[j];
        }
    }
    // traverse the huffman tree
    int size = decodeBitStream.length();
    for(int i = 0; i < size; i++) {
        if (node->left == nullptr && node->right == nullptr) {
            mDecodeBitStream += node->mch;
            node = mhead;
        }
        if (decodeBitStream[i] == '0') node = node->left;
        else if (decodeBitStream[i] == '1') node = node->right;
    }
    
}

void huffman_processing::dump() {
    //traversal the huffman tree

}

void huffman_processing::uninit() {

}
