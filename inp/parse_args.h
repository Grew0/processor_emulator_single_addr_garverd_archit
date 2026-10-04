#ifndef INP_PARSE_ARGS_H
#define INP_PARSE_ARGS_H

#include <cstring>
#include <iostream>

class ArgsParser {
  public:
    ArgsParser(int argc, char **argv) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp("-i", argv[i]) == 0) {
                if (++i < argc) {
                    instr = argv[i];
                } else {
                    std::cout << "Please input file path after '-i'";
                }
            } else if (strcmp("-m", argv[i]) == 0) {
                if (++i < argc) {
                    mem = argv[i];
                } else {
                    std::cout << "Please input file path after '-m'";
                }

            } else if (strcmp("-d", argv[i]) == 0) {
                gdeb = true;
            } else if (strcmp("-h", argv[i]) == 0) {
                help = true;
            } else { // Unknow arg
                help = true;
                std::cout << "Unknow arg: \'" << argv[i] << "\'" << std::endl;
            }
        }
        if (instr == nullptr || mem == nullptr) {
            help = true;
        }

        if (help) {
            std::cout << "This is proccessor emulator. Next arguments are "
                         "supported:\n"
                      << "    -i /file/path - path to binary file with "
                         "instructions (sequence of numbers);\n"
                      << "    -m /file/path - path to binary file with memory "
                         "(sequence of numbers);\n"
                      << "    -d - use debbuger;\n"
                      << "    -h - show this help message.\n\n"
                      << "To make proccessor work you have to insert both "
                         "instructions and memory";
            exit(1);
        }
    }

    bool GetIsGDeb() { return gdeb; }
    const char *GetFPInstr() { return instr; }
    const char *GetFPMem() { return mem; }

  private:
    bool help = false, gdeb = false;
    const char *instr = nullptr;
    const char *mem = nullptr;
};

#endif // INP_PARSE_ARGS_H
