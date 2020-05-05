//
// Markov.cpp
// Nathanael Epps
//

#include "Markov.hpp"
using namespace std;

#include <algorithm>
#include <sstream>

Markov::Markov(string in, int ord)
{
    // validate parameters
    if (ord <= 0)
        throw MakeException("Order is negative/zero");
    
    // set instance vars
    order = ord;
    input = in;
    
    // go through the input and replace newlines with spaces
    for (char& c : input) {
        if (c == '\n')
            c = ' ';
    }
    
    // enable circular strings
    int len = input.length();
    input += input.substr(0, order);
    
    // loop through input
    for (int x = 0; x < len; x++)
    {
        string chunk = input.substr(x, order + 1);
        
        // get kgram
        string kgram = chunk.substr(0, chunk.length() - 1);
        
        // get next char
        char next = chunk.substr(chunk.length() - 1, 1).at(0);
        
        // skip newline characters
        if (next == '\n')
            continue;
        
        // get the entry (entry is created by operator[] if it
        // doesn't exist already)
        PairVec& pv = freqTable[kgram];
        
        // look through entry to see if it has a mapping
        auto pos = std::find_if(pv.begin(), pv.end(), [=](EntryPair& ep){
            return ep.first == next;
        });
        
        // if no mapping, add one (note find_if returns second parameter if
        // unable to find requested element)
        if (pos == pv.end())
            pv.push_back(EntryPair(next, 1)); // aha!
        
        // if there is already a mapping
        else
            pos->second++;
    }
}

/*
 
 Original version of 'next'. Doesn't work
 very well because there's no randomness, so gets stuck
 doing the same thing over and over easily.
 
char Markov::next(string kgram) const
{
    if (kgram.length() != order)
        throw runtime_error(FNAME + ": Invalid kgram");
    
    char rval = 0;
    int max = 0;
    
    // note that "at" doesn't create entries
    // (whereas operator[] does)
    const PairVec& pv = freqTable.at(kgram);
    
    for (EntryPair ep : pv)
    {
        if (ep.second > max) {
            max = ep.second;
            rval = ep.first;
        }
    }
    
    if (rval == 0)
        throw runtime_error(FNAME + ": rval == 0");
    
    return rval;
}
 */

char Markov::next(string kgram) const
{
    if (kgram.length() != order)
        throw MakeException("Invalid Kgram");
    
    const PairVec& pv = freqTable.at(kgram);
    vector<char> vec;
    
    // fill 'vec' with a char for each time it appears
    // after 'kgram'
    for (const EntryPair& pair : pv)
        for (int x = 0; x < pair.second; x++)
            vec.push_back(pair.first);
    
    // since vec is proportionally filled out, we can
    // just return a random element
    return vec.at(randint(0, vec.size() - 1));
}
#ifdef DEBUG
#define SEP "        "
string Markov::toString() const
{
    stringstream ss;
    
    ss << "-- kgram" << SEP << "next (count)\n";
    
    for (const auto& itr : freqTable)
    {
        ss << "-- ";
        
        // insert kgram char by char to catch spaces
        for (char c : itr.first)
        {
            if (c == ' ')
                ss << "(s)";
            else
                ss << c;
        }
        
        ss << SEP;
        
        // loop through list of pairs
        for (const EntryPair& ep : itr.second)
        {
            if (ep.first == '\n')
                ss << "(n)";
            else if (ep.first == ' ')
                ss << "(s)";
            else
                ss << ep.first;
            
            ss << " (" << ep.second << ") ";
        }
        
        // newline!
        ss << "\n";
    }
    
    return ss.str();
}
#endif
