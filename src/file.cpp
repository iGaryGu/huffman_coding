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

string file_ops::readBinary2string() {
    size_t size = 0;
    fseek(pFile, 0, SEEK_END);
    size = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);
    string str;
    str.resize(size);
    fread(&str[0], 1, size, pFile);
    return str;
}


bool file_ops::output(string& s, bool binary) {
    bool ret = true;
    if (!binary) {
        const char* str = s.c_str();
        fwrite(str, sizeof(char)*s.length(), 1, pFile);
    } else {
        int length = s.length();
        char input = 0;
        auto byteMask = [&](int start, int end) -> unsigned char {
            int shift_cnt = end - start;
            unsigned char byteConvert = 0;
            for(int i = start; i <= end; i++) {
                byteConvert |= (((s[i] - '0') & 1) << shift_cnt);
                shift_cnt--;
            }
            return byteConvert;
        };
        for(int i = 0; i < length; i += 8) {
            auto ret = byteMask(i, i+7);
            fwrite((void*)&ret, sizeof(unsigned char), 1, pFile);
            if (UNLIKELY(i+8 >=length)) {
                ret = byteMask(i, length-1);
                fwrite((void*)&ret, sizeof(unsigned char), 1, pFile);
                break;
            }
        }
    }
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

