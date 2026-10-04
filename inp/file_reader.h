#ifndef INP_FILE_READER_H
#define INP_FILE_READER_H

#include <fstream>
#include <stdlib.h>
#include <string>

class FileReader {
  public:
    template <typename T> static std::vector<T> Read(std::string path) {
        std::vector<T> a;
        std::ifstream in(path);
        std::string s;
        while (in >> s) {
            char *check;
            const char *cs = s.c_str();
            T num = strtol(cs, &check, 10);
            if (!(*check)) {
                a.push_back(num);
            } else { // must be comment
                std::getline(in, s);
            }
        }
        in.close();

        return std::move(a);
    }
};

#endif // INP_FILE_READER_H
