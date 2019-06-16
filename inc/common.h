#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

struct huffmanNode {
    huffmanNode()
        :mfreq(0),
        mch(0),
        right(nullptr),
        left(nullptr)
    {}
    huffmanNode(int freq, char c)
        :mfreq(freq),
        mch(c),
        right(nullptr),
        left(nullptr)
    {}

    int mfreq;
    char mch;
    huffmanNode* right;
    huffmanNode* left;
};

struct Item {
    char mch;
    huffmanNode *node;
    int mfreq;
    bool virtualNode;
    Item()
        : mch(0),
        node(nullptr),
        mfreq(0),
        virtualNode(false)
    {}
    Item(char ch, int freq)
        : mch(ch),
        node(nullptr),
        mfreq(freq),
        virtualNode(false)
    {}
    Item(char ch, int freq, bool virt)
        : mch(ch),
        node(nullptr),
        mfreq(freq),
        virtualNode(virt)
    {}
    Item(huffmanNode *n, int freq, bool virt)
        : node(n),
        mfreq(freq),
        virtualNode(virt)
    {}
};

#endif
