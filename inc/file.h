#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;
class priority_queue;

class Record {
public:
    friend priority_queue;

    bool readFile(const char* path);
    unordered_map<char, int> getRecord();
    bool uninit();
    void dump();

private:
    unordered_map<char, int> mRecord;
};

#endif
