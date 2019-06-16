#include "file.h"
#include "common.h"

bool file_ops::open(const char* path, bool breadops) {
    bool ret = true;
    if (breadops) {
        pFile = fopen(path, "r");
    } else {
        pFile = fopen(path, "wb");
    }
    if (UNLIKELY(pFile == NULL)) {
        ret = false;
        printf("file open fail! readops : %d", breadops);
    }
    return ret;
}

char file_ops::readChar() {
    return getc(pFile);
}

bool file_ops::output(string& s) {
    bool ret = true;
    const char* str = s.c_str();
    fwrite(str, sizeof(char)*s.length(), 1, pFile);
    return ret;
}


file_ops::~file_ops() {
    if (fclose(pFile)) {
        printf("close file failed!\n");
        exit(1);
    }
}


bool Record::readFile(const char* path) {
    bool ret = true;
    FILE* pFile = NULL;
    char ch;
    pFile = fopen(path, "r");
    if (UNLIKELY(pFile==NULL)) {
        printf("file open fail");
        return false;
    } else {
        while ((ch = getc(pFile)) != EOF) {
            auto itr = mRecord.find(ch);
            if (itr == mRecord.end()) {
                mRecord[ch] = 0; // initialized
                mRecord[ch]++;
            } else {
                mRecord[ch]++;
            }
        }
        fclose(pFile);

    }

    return ret;
}

bool Record::uninit() {
    bool ret = true;
    
    return ret;
}

void Record::dump() {
    // for debug usage
    for(auto itr = mRecord.begin(); itr != mRecord.end(); itr++) {
        printf("[%c] = %d\n", (*itr).first, (*itr).second);
    }
}

