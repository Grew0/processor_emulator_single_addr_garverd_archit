#include "inp/file_reader.h"
#include "inp/parse_args.h"

#include "gdeb/debbuger.h"
#include "proc/proc.h"

int main(int argc, char **argv) {
    ArgsParser ap(argc, argv);
    std::vector<Operation> instr(FileReader::Read<Operation>(ap.GetFPInstr()));
    std::vector<Word> mem(FileReader::Read<Word>(ap.GetFPMem()));
    if (instr.empty()) {
        std::cout << "Failed to read instructions";
        return 1;
    }

    if (mem.empty()) {
        std::cout << "Failed to read memory";
        return 1;
    }

    Proc proc;
    proc.SetUpInstructions(instr);
    proc.SetUpMemory(mem);
    if (ap.GetIsGDeb()) {

        GDeb deb(&proc);
        deb.Start();
    } else {
        proc.ExecuteAll();
        for (auto &i : mem) {
            std::cout << i << " ";
        }
    }
    return 0;
}
