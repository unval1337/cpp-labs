//
// Created by unval on 20.09.19.
//

#ifndef LAB0B_CLASSES_H
#define LAB0B_CLASSES_H


#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

bool findDelemiter(char c);

class wordCounter
{
    int count;
    std::map<std::string, int> mp;


    void pushWord(std::string word);

    void writeWords(std::string &line);

    void printWords();

    std::vector<std::pair<std::string, int>> * returnSortedVector();


public:

    wordCounter();

    wordCounter(std::string &line);

    wordCounter(std::ifstream &in);


    int getCount() { return count; }

    void printSorted();

    void writeSortedWordsInFile(std::string outputName);
};


#endif //LAB0B_CLASSES_H
