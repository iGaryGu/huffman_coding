#include "file.h"
#include "common.h"

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
                mRecord[ch] = 0;
            } else {
                mRecord[ch]++;
            }
        }
        fclose(pFile);
//        mContent.resize(mRecord.size()+1);
//        int index = 1;
//        for (auto itr = mRecord.begin(); itr != mRecord.end(); itr++, index++) {
//            mContent[index] = make_pair((*itr).first, (*itr).second);
//        }
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
