#include <stdio.h>
#include "file.h"
#include "priority_queue.h"
#include "huffman_processing.h"

#define FILEPATH "/home/garygu/huffman_coding/speech.txt"

int main (int argc, char* argv[]) {

    Record record;
    priority_queue pq;
    huffman_processing hfp;
    bool ret = record.readFile((char*)FILEPATH);
    if (!ret) {
        printf("read file failed!\n");
        exit(1);
    } else {
//        record.dump();
        pq.init(std::move(record));
        pq.generatePQ();
//        pq.dump();
        hfp.init(std::move(pq));
        hfp.generateHuffman();
    }

    pq.uninit();
    record.uninit();


    return 0;
}
