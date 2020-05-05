//
// Util.cpp
// Nathanael Epps
//

#include "Util.hpp"
using namespace std;

#include <iterator>

string readAll(istream& stream)
{
    stream >> noskipws;
    
    istream_iterator<char> start (stream);
    istream_iterator<char> end;
    
    string input (start, end);
    
    return input;
}

#include <ctime>
#include <cstdlib>
#include <stdexcept>

int randint(int lo, int hi)
{
    static bool init = false;
    if (!init) {
        srand(time(nullptr));
        init = true;
    }
    
    if (lo > hi)
        throw MakeException("lo > hi");
    else if (lo == hi)
        return lo;
    else
        return rand() % (hi - lo + 1) + lo;
}

#include <sstream>

int stringToInt(string s)
{
    int x = 0;
    std::stringstream ss(s);
    ss >> x;
    if (ss.fail() || ss.bad())
        throw MakeException("conversion failure");
    
    return x;
}

string intToString(int x)
{
#ifndef __linux__
    return (stringstream() << x).str();
#else
    stringstream ss;
    ss << x;
    return ss.str();
#endif
}

MarkovException::MarkovException(string str, string file, int line)
{
    stringstream ss;
    
    ss << str << " @" << file << ":" << line;
    
    reason = ss.str();
}

const char* MarkovException::what() const noexcept
{
    return reason.c_str();
}
