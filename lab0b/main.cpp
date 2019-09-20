#include "classes.h"


int main(int argc, char* argv[])
{
    std::ifstream in;
    in.open(argv[1]);
    wordCounter wcif(in);

    wcif.writeSortedWordsInFile(std::string(argv[2]));

    in.close();
    return 0;
}