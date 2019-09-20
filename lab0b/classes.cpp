//
// Created by unval on 20.09.19.
//

#include "classes.h"


bool findDelemiter(char c)
{
    return (c < '0' || c > 'z' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a'));
}


wordCounter::wordCounter()
{
    count = 0;
}

wordCounter::wordCounter(std::string &line)
{
    count = 0;
    this->writeWords(line);
}

wordCounter::wordCounter(std::ifstream &in)
{
    count = 0;
    std::string line;
    while(std::getline(in, line))
    {
        this->writeWords(line);
    }
}



void wordCounter::pushWord(std::string word){      // realise copy str?
    mp[word]++;
    count++;
}

void wordCounter::writeWords(std::string &line)
{
    unsigned int start = 0;
    unsigned int end = 0;
    while(start != line.length())
    {
        if(findDelemiter(line[end]) || end == (line.length() - 1))
        {
            if (end != start)
            {
                if (end == (line.length() - 1))
                {
                    if(findDelemiter(line[end]))
                    {
                        this->pushWord(line.substr(start, end-start));
                    }
                    else
                    {
                        this->pushWord(line.substr(start, end-start+1));
                    }
                }
                else
                {
                    this->pushWord(line.substr(start, end-start));
                }
            }

            end++;
            start = end;
        }
        else
        {
            end++;
        }
    }
}

void wordCounter::printWords()
{
    std::map<std::string, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

std::vector<std::pair<std::string, int>> * wordCounter::returnSortedVector()
{
    auto *vec = new std::vector<std::pair<std::string, int>>;

    std::map<std::string, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        vec->push_back(std::pair(it->first, it->second));
    }

    std::sort(vec->begin(), vec->end(), [] (std::pair<std::string, int> const & a, std::pair<std::string, int> const & b){ return a.second > b.second;});

    return vec;
}

void wordCounter::printSorted()
{
    auto *vec = this->returnSortedVector();

    int i;
    for(i = 0; i < vec->size(); i++)
    {
        std::cout << (*vec)[i].first << " " << (*vec)[i].second << std::endl;
    }

    delete vec;

}

void wordCounter::writeSortedWordsInFile(std::string outputName)
{
    auto *vec = this->returnSortedVector();

    std::ofstream out;
    out.open(outputName);

    int i;
    for(i = 0; i < vec->size(); i++)
    {
        out << (*vec)[i].first << "," << (*vec)[i].second << "," << (*vec)[i].second * 100.0 / count << "%" << std::endl;
    }

    std::cout << "Writed" << std::endl;

    out.close();
    delete vec;
}

