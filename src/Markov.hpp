//
// Markov.hpp
// Nathanael Epps
//

#ifndef MARKOV
#define MARKOV

#include <string>
#include <map>
#include <vector>
#include <utility>

#include "Util.hpp"

using std::string;

class Markov
{
public:
    Markov(string, int);
    
    char next(string) const;
#ifdef DEBUG
    string toString() const;
#endif
private:
    int order;
    
    string input;
    
    // a character and how many times it appears
    typedef std::pair<char, int> EntryPair;

    // a list of characters and how many times they appear
    typedef std::vector<EntryPair> PairVec;

    // mapping of a kgram to a list of characters and how many
    // times they appear
    typedef std::map<string, PairVec> FreqTable;
    
    FreqTable freqTable;
};

#endif
