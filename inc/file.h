#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;
class priority_queue;

class file_ops {
public:
    file_ops() : pFile(NULL) {}
    ~file_ops();
    bool open(const char* path, bool breadops);
    char readChar();
    bool output(string& s);
    bool close();

private:
    FILE* pFile;
};

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
